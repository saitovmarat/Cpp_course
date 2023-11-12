import unittest
from subprocess import Popen, PIPE
from io import StringIO

from unittest import TestCase

from contextlib import contextmanager

TEST_PROGRAM = './classTask1 '

@contextmanager
def clear_db_fixture(message):
    with Popen(TEST_PROGRAM + message, stdout=PIPE, stderr=PIPE, shell=True) as process:
        process.wait()
    try:
        yield
    finally:
        with Popen(TEST_PROGRAM + message, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()


class TestClassTask(unittest.TestCase):

    def setUp(self):
        with Popen(TEST_PROGRAM + 'DROPALL', stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

    def tearDown(self):
        with Popen(TEST_PROGRAM + 'DROPALL', stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0


    @clear_db_fixture('DROPALL')
    def test_simple_insert(self):
        TEST_ARGS = 'INSERT 1=2? INSERT 3=4? INSERT 5=6? INSERT 7=8?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

        TEST_ARGS = 'FIND 1?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

            # Check stdout
            expected_out = b'FOUND: 2\n'
            self.assertEqual(process.stdout.read(), expected_out)


    @clear_db_fixture('DROPALL')
    def test_simple_delete(self):
        TEST_ARGS = 'INSERT 1=2? INSERT 3=4?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

        TEST_ARGS = 'DELETE 3?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

        TEST_ARGS = 'FIND 3?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

            # Check stdout
            expected_out = b'NOT FOUND\n'
            self.assertEqual(process.stdout.read(), expected_out)


    @clear_db_fixture('DROPALL')
    def test_simple_reassign(self):
        TEST_ARGS = 'INSERT hello=world?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

        TEST_ARGS = 'FIND hello?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

            # Check stdout
            expected_out = b'FOUND: world\n'
            self.assertEqual(process.stdout.read(), expected_out)

        TEST_ARGS = 'INSERT hello=mir?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0


        TEST_ARGS = 'FIND hello?'
        with Popen(TEST_PROGRAM + TEST_ARGS, stdout=PIPE, stderr=PIPE, shell=True) as process:
            process.wait()
            assert process.returncode == 0

            # Check stdout
            expected_out = b'FOUND: mir\n'
            self.assertEqual(process.stdout.read(), expected_out)


if __name__ == '__main__':
    unittest.main()