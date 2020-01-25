//
// Created by pufit on 25.01.2020.
//


#include <iostream>
#include <cstdint>
#include <vector>


using i32 = int32_t;
using Matrix = std::vector<std::vector<i32>>;


Matrix ReadMatrix();


void PrintMatrix(const Matrix& matrix);


int main() {
    auto matrix = ReadMatrix();
    PrintMatrix(matrix);

    return 0;
}

// size_t  0, 2 ** 64 - 1

template<typename T>
T Read() {
    T value;
    std::cin >> value;
    return value;
}

Matrix ReadMatrix() {
    auto n = Read<size_t>(), m = Read<size_t>();
    Matrix matrix;

    matrix.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        matrix.emplace_back();  // matrix.push_back(std::vector<i32>());

        matrix.back().reserve(m);
        for (size_t j = 0; j < m; ++j) {
            matrix.back().push_back(Read<i32>());
        }
    }
    return matrix;
}

// int    -2 ** 31, 2 ** 31 - 1
// size_t 0,        2 ** 64 - 1

void PrintMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (auto x: row) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}
