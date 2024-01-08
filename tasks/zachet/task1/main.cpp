#include "solution.h"

int main() {
    // Вызов подзадач
    std::vector<Student> students = subtask1("books_data.txt");
    std::string mostPopularBook = subtask2(students);
    std::string minPageStudent = subtask3(students);
    std::vector<std::string> groupStatistics = subtask4(students);

    // Вывод результатов
    std::cout << "Самая популярная книга: " << mostPopularBook << std::endl;
    std::cout << "Студент с минимальным количеством страниц: " << minPageStudent << std::endl;
    std::cout << "\nСтатистика по группам:\n";
    for (const auto& stat : groupStatistics) {
        std::cout << stat << std::endl;
    }

    return 0;
}
