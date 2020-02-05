#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>

// Про стресс тестирование:

size_t binarySearch(const std::vector<int>& array, int x) {
    size_t left = 0;
    size_t right = array.size();
    while (left < right) {
        size_t mid = (left + right) / 2;
        if (array[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void UnitTest() {
    {
        std::vector<int> array{0, 1, 2, 3, 4, 5, 6};
        assert(binarySearch(array, 4) == 4);
    }
}

std::mt19937 gen;
std::uniform_int_distribution<int> distribution(0, 10);

auto GenerateArray(size_t size) {
    std::vector<int> answer(size, 0);
    for (auto& elem : answer) {
        elem = distribution(gen);
    }
    return answer;
}

int GenerateValue() {
    return distribution(gen);
}

void StressTest() {
    const int numTests = 100000;
    for (int i = 0; i < numTests; ++i) {
        auto array = GenerateArray(10000);
        std::sort(array.begin(), array.end());
        auto value = GenerateValue();

        auto it = std::find(array.begin(), array.end(), value);
        size_t position = binarySearch(array, value);
        if (it != array.end()) {
            assert(array[position] == *it);
            if (array[position] != *it) {
                std::cout << array << value << ...
                exit(1);
            }
            assert(it - array.begin() == position);
        } else {
            assert(position == array.size()
                || array[position] != value);
        }
    }
}

int main() {
    // UnitTest();
    StressTest();
    return 0;
}

// Про инвалидацию ссылок:

#include <iostream>
#include <vector>
 
int main()
{
    const int size = 100000000;
    std::vector<int> array;
    for (int number = 0; number < size; ++number) {
        array.push_back(number);
    }
    auto* element = &array.back();
    for (int number = 0; number < size; ++number) {
        array.pop_back();
    }
    std::cout << element << '\n';
    std::cout << *element << '\n';
}

// Про измерение времени работы куска кода:

int main() {
    const int size = 1000000;
    std::set<int> set;
    std::unordered_set<int> unorderedSet;

    auto start = std::chrono::steady_clock::now();
    for (int number = 0; number < size; ++number) {
        set.insert(number);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to fill a set of " 
        << size << " ints : " << diff.count() << " s\n";
    
    start = std::chrono::steady_clock::now();
    for (int number = 0; number < size; ++number) {
        unorderedSet.insert(number);
    }
    end = std::chrono::steady_clock::now();
    diff = end - start;
    std::cout << "Time to fill an unordered_set of " 
        << size << " ints : " << diff.count() << " s\n";
    
    return 0;
}
