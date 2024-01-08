#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


int main() {
    // Пример использования
    ReadWriteManager readWriteManager;

    FileWriter fileWriter1("file1.txt");
    FileWriter fileWriter2("file2.txt");
    ConsoleWriter consoleWriter;

    readWriteManager.addWriter(&fileWriter1);
    readWriteManager.addWriter(&fileWriter2);
    readWriteManager.addWriter(&consoleWriter);

    readWriteManager.writeAll("Hello, World!");
    readWriteManager.writeToFile("file1.txt", "This is file 1.");
    readWriteManager.writeToFile("file2.txt", "This is file 2.");

    FileReader fileReader1("file1.txt");
    FileReader fileReader2("file2.txt");

    readWriteManager.readAndPrint(fileReader1);
    readWriteManager.readAndPrint(fileReader2);

    return 0;
}
