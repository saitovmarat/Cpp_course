/**
 * @file main.cpp
 * @brief напишите программу, которая читает из файла текст состоящий из букв и знаков пунктуации (,.').
 * Необходимый текст находится в файле "input.txt".
 * Нужно для каждого предложения вывести не уникальные слова, это те слова, которые встречаются дважды и более раз в одном предложении.
 * Слова следует учитывать без учёта регистра.
 * Слово не должно содержать знаков пунктуации, но может содержать символ "\'", а концом предложения является только символ ".". Внутри предложения может присутствовать ",".
 * Для каждого такого случая вывести в std::cout номер предложения, а после символа : все неуникальные слова рядом с номером через запятую.
 * В конце списка слов вывести '\n', а не запятую.
 *   подсказка: std::cout << "\b \n"; - код для удаления последнего символа и вместо него вывод перехода на новую строку
 * Если в предложении все слова уникальны, то для этого предложения ничего не нужно выводить
 * пример вывода:
0:the\n
1:a\n
2:one,the\n
3:a,the\n
 *
 */

#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>


int areThereUniqueWords(std::map<std::string, int> uniqueWords){
    for(std::map<std::string, int>::iterator it = uniqueWords.begin(); it != uniqueWords.end(); it++){
        if(it->second > 1)
            return 1;
    }
    return 0;
}
std::map<std::string, int> uniqueWordsMap(std::vector<std::string> wordsInSentence)
{
    std::map<std::string, int> uniqueWords;
    std::vector<std::string>::iterator it = wordsInSentence.begin();
    while(it!=wordsInSentence.end()){
        if (uniqueWords.find(*it) == uniqueWords.end()){
            uniqueWords[*it] = 1;
        }
        else{
            uniqueWords[*it]++;
        }
        it++;
    }
    return uniqueWords;
} 
std::vector<std::string> Split(const std::string str)
{
    std::vector<std::string> result;
    std::string addString;
    int i = 0;
    while (i < str.size()) {
        if (str[i] != ' ' && str[i] != ',') {
            addString += str[i]; 
        } else {
            if (!addString.empty()) {
                result.push_back(addString);
                addString.clear();
            }
        }
        i++;
    }
    if (!addString.empty()) {
        result.push_back(addString);
    }
    return result;
}
void printResults(std::vector<std::string> words){
    std::vector<std::string>::iterator wordsIt = words.begin();
    std::vector<std::string> wordsInSentence;
    int sentencesCount = 0;
    while(wordsIt!=words.end()){
        size_t found = wordsIt->find('.');
        if (found != std::string::npos){
            wordsIt->pop_back();
            std::transform(wordsIt->begin(), wordsIt->end(), wordsIt->begin(), ::tolower);
            wordsInSentence.push_back(*wordsIt);
            std::map<std::string, int> uniqueWords = uniqueWordsMap(wordsInSentence);
            if(areThereUniqueWords(uniqueWords)){
                std::cout << sentencesCount << ':';
                for(std::map<std::string, int>::iterator it = uniqueWords.begin(); it != uniqueWords.end(); it++){
                    if(it->second > 1){
                        std::cout << it->first << ',';
                    }
                }
                std::cout << "\b \n";
            }
            sentencesCount++;
            wordsInSentence.clear();
        }
        else{
            std::transform(wordsIt->begin(), wordsIt->end(), wordsIt->begin(), ::tolower);
            wordsInSentence.push_back(*wordsIt);
        }
        wordsIt++;
    }
}

int main() {
    std::ifstream inputFile("input.txt");

    if (inputFile.is_open()) {
        std::vector<std::string> words;
        std::string line;
        while (std::getline(inputFile, line)) {
            std::vector<std::string> wordsInLine = Split(line);
            for(int i = 0; i < wordsInLine.size(); i++){
                words.push_back(wordsInLine[i]);
            }
        }
        inputFile.close();
        printResults(words);
    } 
    else{
        std::cout << "Не удалось открыть файл.\n";
    }
    return 0;
}
