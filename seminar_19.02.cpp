#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class TextGenerator {
public:
    void ReadText() {
        std::string word;
        while (std::cin >> word) {
            words_.emplace_back(word);
        }
    }

    void Train() {
        if (words_.empty()) {
            throw std::runtime_error("No data for train.");
        }
        for (size_t i = 0; i < words_.size() - 1; ++i) {
            const auto& firstWord = words_[i];
            const auto& secondWord = words_[i + 1];
            ++counters_[firstWord][secondWord];
        }
        for (const auto& [firstWord, secondWords] : counters_) {
            auto cmp = [](const auto& lhs, const auto& rhs) {
                return lhs.second < rhs.second;
            };
            auto it = std::max_element(secondWords.begin(), secondWords.end(), cmp);
            model_[firstWord] = it->first;
        }
    }

    void GenerateText(const std::string& initial, size_t textSize) {
        std::string currentWord = initial;
        for (size_t i = 0; i < textSize; ++i) {
            std::cout << currentWord << ' ';
            currentWord = GetNext(currentWord);
        }
        std::cout << currentWord << ".\n";
    }

private:
    std::string GetNext(const std::string& word) {
        return model_[word];
    }

    std::vector<std::string> words_;
    std::unordered_map<
        std::string,
        std::unordered_map<std::string, int>> counters_;
    std::unordered_map<std::string, std::string> model_;
};

int main() {
    TextGenerator generator;
    generator.ReadText();
    generator.Train();
    generator.GenerateText("a", 100);
}
