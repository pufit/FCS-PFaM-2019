#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

void print(const std::vector<int>& array) {
    for (auto elem : array) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

void RemoveIf() {
    std::vector<int> array{1, 2, 2, 3, 5, 20};

    print(array);
    auto newEnd = std::remove_if(array.begin(), array.end(), [](auto elem) {
        return elem % 2 == 0;
    });
    array.erase(newEnd, array.end());
    
    print(array);
}

void RemoveZeros(std::vector<int>& array) {
    array.erase(std::remove(array.begin(), array.end(), 0), array.end());
}

class Vector {
public:
    void push_back(int value) {
        deque_.push_back(value);
    }

    void pop_back() {
        deque_.pop_back();
    }

    int& back() {
        return deque_.back();
    }

    class Iterator : public std::iterator<std::forward_iterator_tag, int> {
    public:

        Iterator() = default;

        Iterator(int* pointer) {
            current_ = pointer;
            // На самом деле, в конструкторах всегда пишут иначе:
            //     Iterator(int* pointer) : current_(pointer) {}
            // оставляя тело конструктора пустым.
            // Пример смотрите ниже.
        }

        Iterator(const Iterator& rhs) : current_(rhs.current_) {
        }

        Iterator& operator=(const Iterator& rhs) {
            current_ = rhs.current_;
            return *this;
        }

        Iterator& operator++() {  // ++it
            ++current_;
            return *this;
        }

        Iterator operator++(int) {  // it++
            Iterator copyThis(*this);
            ++current_;
            return copyThis;
        }

        int& operator*() {  // *it = 10;
            return *current_;
        }

    private:
        int* current_ = nullptr;
    };

private:
    std::deque<int> deque_;
};

int main() {
    Vector vector;
    vector.push_back(666);
    vector.push_back(777);
    Vector::Iterator iter(&vector.back());
    *iter = 10;
    std::cout << *iter << '\n';
    std::cout << vector.back() << '\n';
}
