#include <algorithm>
#include <iterator>

template <typename InputIt>
void Reverse(InputIt first, InputIt last) {
    for (; first != last && std::next(first) != last; ++first, --last) {
    // for (; std::distance(first, last) > 0; ++first, --last) {
        std::swap(*first, *std::prev(last));
        // std::iter_swap(first, std::prev(last));
    }
}

#include <iostream>
#include <vector>

using i32 = int32_t;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << ' ';
    }
    return os << '\n';
}

int main() {
    std::vector<i32> vec = {1, 2, 3, 4, 5};

    std::cout << "Before reverse: " << vec;
    Reverse(vec.begin(), vec.end());
    std::cout << "After reverse:  " << vec;
}
