/*std::vector<string> – Batch Word Processing*/
#include <iostream>
#include <vector>
#include <string>

char toLowerChar(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}
std::string toLowerString(const std::string& str) {
    std::string lowerStr;
    for (char ch : str) {
        lowerStr += toLowerChar(ch);
    }
    return lowerStr;
}
void sortStrings(std::vector<std::string>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                std::string temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}
void removeDuplicates(std::vector<std::string>& vec) {
    std::vector<std::string> uniqueVec;
    for (size_t i = 0; i < vec.size(); i++) {
        if (i == 0 || vec[i] != vec[i - 1]) {
            uniqueVec.push_back(vec[i]);
        }
    }
    vec = uniqueVec;
}

int main() {
    std::vector<std::string> words = { "Apple", "banana", "apple", "Orange", "BANANA", "grape" };
    for (std::string& word : words) {
        word = toLowerString(word);
    }

    sortStrings(words);
    removeDuplicates(words);

    std::cout << "[";
    for (size_t i = 0; i < words.size(); i++) {
        std::cout << "\"" << words[i] << "\"";
        if (i < words.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}

