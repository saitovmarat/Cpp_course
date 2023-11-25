#include <cstdio>
#include <exception>
#include <string>
 
class CannotOpenFileException {
};
 
class FileRaiiWrapper {
private:
    std::FILE* f; // тот самый файловый дескриптор, который мы оборачиваем

public:
    FileRaiiWrapper(const std::string& name) {
        f = std::fopen(name.c_str(), "r");
        if(f == nullptr)
            throw CannotOpenFileException();
    }

    FileRaiiWrapper(const FileRaiiWrapper&) = delete;
    FileRaiiWrapper& operator = (const FileRaiiWrapper&) = delete;


// File&& — ссылка на временный объект
// забираем владение дескриптором у временного объекта other
    // Конструктор перемещения
    FileRaiiWrapper(FileRaiiWrapper&& other) noexcept {
        f = other.f;
        other.f = nullptr;
    }

    // Оператор присваивания с семантикой перемещения
    FileRaiiWrapper& operator = (FileRaiiWrapper&& other) noexcept {
        if(this != &other){
            if(f!=nullptr){
                std::fclose(f);
            }
            f = other.f;
            other.f = nullptr;
        }
        return *this;
    }

    ~FileRaiiWrapper() noexcept {
        if(f!=nullptr)
            std::fclose(f);
    }

    // функция для чтения строки длинной bytes_count из файла
    std::string ReadBytes(const size_t bytes_count) const {
        char* buf = new char[bytes_count + 1]{};
        std::ignore = std::fgets(buf, bytes_count, f);
        std::string result(buf);
        delete[] buf;
        return result;
    }
};