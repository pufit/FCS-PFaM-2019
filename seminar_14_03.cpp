#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// В clion пропишите в CMakeLists.txt следующую строку:
// set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
// Так вы запустите компиляцию с флагом -fsanitize=address
// Это очень поможет при дебаге программ, явно работающих с памятью.

class Vector {
public:
    void PushBack(int value) {
        if (size_ >= capacity_) {
            auto prev_data = data_;
            data_ = new int[2 * capacity_];

            for (size_t i = 0; i < size_; ++i) {
                data_[i] = prev_data[i];
            }

            delete[] prev_data;
        }
        data_[size_] = value;
        ++size_;
    }

    int& Back() {
        return data_[size_ - 1];
    }

    ~Vector() {
        delete[] data_;
    }

private:
    int* data_ = new int[1];
    size_t size_ = 0;
    size_t capacity_ = 1;
};

int main() {
    Vector vector;
    vector.PushBack(120);
    vector.PushBack(230);
    // vector.PushBack(340);
    std::cout << vector.Back() << '\n';
}
