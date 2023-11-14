/**
 * @file main.cpp
 * @brief задача написать программу, которая будет обслуживать текстовую key-value базу данных в файле db.txt
 * 
 * Должен компилироваться бинарник db, и откликаться на команды (команды подаются как аргументы при запуске приложения *argv)
 * `INSERT KEY=VALUE` - операция вставки пары в базу данных (если добавляется ключ который уже есть в файле, то он обновляется)
 * `DELETE KEY` - удалить пару из базы данных
 * `FIND KEY` - вывести значение по ключу в базе данных (возврашает сообщение с элементов в консоль `FOUND: VALUE`, или выдаёт на вывод `NOT FOUND`, если элемента нет в базе данных)
 * `PRINT KEYS/VALUES` - вывести значение всех ключей/значений в базе данных
 * `DROPALL` - удалить всю базу данных (все значения из базы)
 * Любая команда должна заканчиваться на '?' , можно обрабатывать сразу несколько команд
 * 
 * KEY и VALUE - гарантированно не пустые строки (используют символы букв и цифр, не используют знаки)
 * Как вы будете хранить в файле данные - на ваше усмотрение. Главное - чтобы пользовательское API не нарушалось.
 * Главное - база данных храниться в файле, но не в памяти и программу запускаем по необходимости.
 * Программа может быть неоптимальна с точки зрения вычислений, главное чтобы правильно выполнялась основная логика команд.
 */

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

/*namespace {
    constexpr char end_command_delimiter{'?'};
}*/

using namespace std;
auto Split(const string& str, char delimiter) -> vector<string> 
{
    vector<string> result;
    string addString;
    for(int i = 0; i < str.size(); i++){
        if (str[i] == delimiter || i == str.size()-1){
            result.push_back(addString);
            addString = "";
        }
        else addString += str[i];
    }
    return result;
}
class FileReader {
public:
    string fileName;
    FileReader(const string& fileName) {
        this->fileName = fileName;
    }

    int Print(const string& whatToPrint) {
        FILE* f = fopen(fileName.c_str(), "rt");
        if(f!=NULL){
            char line[100];
            while (fgets(line, sizeof(line), f) != NULL) {
                if(strchr(line, ' ')){
                    vector<string> value = Split(line, ' ');
                    if (strcasecmp(whatToPrint.c_str(), "keys") == 0) {
                        cout << value[0] << endl;
                    } else if (strcasecmp(whatToPrint.c_str(), "values") == 0) {
                        cout << value[1] << endl;
                    }
                }
            }
            fclose(f);
        }
        return 1;
    }

    int find(const string& key) {
        FILE* f = fopen(fileName.c_str(), "rt");
        if (f != NULL) {
            char line[100];
            while (fgets(line, sizeof(line), f) != NULL) {
                if (strstr(line, key.c_str()) != NULL) { //Тут надо проверять по ключу у меня со сплитом не работает
                                                        //Сделал так
                    vector<string> value = Split(line, ' ');
                    cout << "FOUND: " << value[1] << "\n";
                    fclose(f);
                    return 1;
                }
            }
            fclose(f);
            cout << "NOT FOUND\n";
            return 2;
        } else {
            cout << "Не удалось открыть файл\n";
            return 0;
        }
    }
};

class FileWriter {
public:
    string fileName;

    FileWriter(const string& fileName) {
        this->fileName = fileName;
    }

    int drop() {
        FILE* f = fopen(fileName.c_str(), "w");
        fclose(f);
        return 0;
    }

    int insert(const string& key, const string& value) {
        FILE* f = fopen(fileName.c_str(), "a");
        if (f != NULL) {
            fprintf(f, "\n%s %s", key.c_str(), value.c_str());
            fclose(f);
            return 1;
        }
        return 0;
    }

    int Delete(const string& key) {
        FILE* f = fopen(fileName.c_str(), "r+");
        FILE* ftemp = fopen("db_temp.txt", "w");
        char line[100];
        while (fgets(line, sizeof(line), f) != NULL) {
            vector<string> value = Split(line, ' ');
            if (strcmp(value[0].c_str(), key.c_str()) == 1) {
                fputs(line, ftemp);
            }
        }
        fclose(f);
        fclose(ftemp);

        remove(fileName.c_str());
        rename("db_temp.txt", fileName.c_str());
        return 0;
    }
};

class ArgumentsParser {
public:
    map<string, string> commands;
    ArgumentsParser(int argc, char** argv) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "INSERT") == 0 || strcmp(argv[i], "DELETE") == 0 ||
                strcmp(argv[i], "FIND") == 0 || strcmp(argv[i], "PRINT") == 0) {
                commands[argv[i]] = argv[i + 1];
                i++;
            } else if (strcmp(argv[i], "DROPALL") == 0) {
                commands[argv[i]] = "";
            }
        }
    }

    int ProcessAllCommands(string filePath ) {
        FileWriter write(filePath);
        FileReader read(filePath);
        for (auto itCommands = commands.begin(); itCommands != commands.end(); itCommands++) {
            if (itCommands->first == "INSERT") {
                string key = itCommands->second.substr(0, itCommands->second.find('='));
                string value = itCommands->second.substr(itCommands->second.find('=') + 1);
                write.insert(key, value);
            } else if (itCommands->first == "DELETE") {
                write.Delete(itCommands->second);
            } else if (itCommands->first == "FIND") {
                read.find(itCommands->second);
            } else if (itCommands->first == "PRINT") {
                read.Print(itCommands->second);
            } else if (itCommands->first == "DROPALL") {
                write.drop();
            }
        }
        return 1;
    }
};
int main(int argc, char** argv){   
    string fileName = "db.txt";
    auto ap = ArgumentsParser(argc, argv);

    ap.ProcessAllCommands(fileName);

    return 0;
}