#include <iostream>
// ...
// some other includes

int ReadInput() {
    int value = 0;
    std::cin >> value;
    return value;
}

void PrintOutput(int answer) {
    std::cout << answer << '\n';
}

int FindSquare(int value) {
    return value * value;
}

int main() {
    int value = ReadInput();
    int answer = FindSquare(value);
    PrintOutput(answer);

    return 0;
}
