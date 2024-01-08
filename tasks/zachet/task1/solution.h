#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

struct Student {
    std::string firstName;
    std::string lastName;
    int groupNumber;
    std::string bookTitle;
    int pageCount;
    bool isBookRead;
};

// Подзадача 1: Считывание данных из файла
std::vector<Student> subtask1(const std::string& filename);

// Подзадача 2: Найти самую популярную прочитанную книгу
std::string subtask2(const std::vector<Student>& students);

// Подзадача 3: Найти студента с минимальным количеством страниц
std::string subtask3(const std::vector<Student>& students);

// Подзадача 4: Статистика по группам
std::vector<std::string> subtask4(const std::vector<Student>& students);