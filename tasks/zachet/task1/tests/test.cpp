#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include <cstring>
#include <list>

#include "solution.h"

// Подготовка тестовых данных
const std::string testFile = "test_books_data.txt";


TEST(Subtask1, ReadingFromFile) {
    std::ofstream testFileStream(testFile);
    testFileStream << "John, Doe, 123, \"The_Great_Gatsby\", 300, да\n";
    testFileStream << "Alice, Wonderland, 456, \"To_Kill_a_Mockingbird\", 250, нет\n";
    testFileStream << "Bob, Builder, 123, \"1984\", 400, да\n";
    testFileStream.close();

    std::vector<Student> students = subtask1(testFile);

    EXPECT_EQ(students.size(), 3);
    EXPECT_EQ(students[0].firstName, "John");
    EXPECT_EQ(students[1].bookTitle, "\"To_Kill_a_Mockingbird\"");
    EXPECT_EQ(students[2].lastName, "Builder");
}

TEST(Subtask2, MostPopularBook) {
    std::vector<Student> students = {
        {"John", "Doe", 123, "The_Great_Gatsby", 300, true},
        {"Alice", "Wonderland", 456, "To_Kill_a_Mockingbird", 250, false},
        {"Bob", "Builder", 123, "1984", 400, true},
        {"Eve", "Smith", 123, "The_Great_Gatsby", 300, true}
    };

    std::string result = subtask2(students);

    EXPECT_EQ(result, "The_Great_Gatsby");
}

TEST(Subtask3, MinPageStudent) {
    std::vector<Student> students = {
        {"John", "Doe", 123, "The_Great_Gatsby", 300, true},
        {"Alice", "Wonderland", 456, "To_Kill_a_Mockingbird", 250, false},
        {"Bob", "Builder", 123, "1984", 400, true},
        {"Eve", "Smith", 123, "The_Great_Gatsby", 200, true}
    };

    std::string result = subtask3(students);

    EXPECT_EQ(result, "Eve Smith");
}

TEST(Subtask4, GroupStatistics) {
    std::vector<Student> students = {
        {"John", "Doe", 123, "The_Great_Gatsby", 300, true},
        {"Alice", "Wonderland", 456, "To_Kill_a_Mockingbird", 250, false},
        {"Bob", "Builder", 123, "1984", 400, true},
        {"Eve", "Smith", 456, "The_Catcher_in_the_Rye", 200, true},
        {"Charlie", "Brown", 789, "Pride_and_Prejudice", 350, true},
        {"Maikl", "Dezzer", 111, "War_and_Peace_1", 1, true},
        {"Maikl", "Dezzer", 111, "War_and_Peace_2", 1, true},
        {"Maikl", "Dezzer", 111, "War and_Peace_3", 1, true},
        {"Maikl", "Dezzer", 111, "War and_Peace_4", 1, true},
        {"Maikl", "Dezzer", 111, "War_and_Peace_5", 1, true},
    };

    std::vector<std::string> result = subtask4(students);

    EXPECT_EQ(result.size(), 4);
    // Проверка, что либо "apple" либо "grape" содержится в массиве
    EXPECT_THAT(result, testing::Each(testing::AnyOf(
        std::string("Группа 123: 2 книги"),
        std::string("Группа 456: 1 книга"),
        std::string("Группа 789: 1 книга"),
        std::string("Группа 111: 5 книг"))
        ));
}

