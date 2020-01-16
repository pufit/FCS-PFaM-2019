#include <cassert>
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

void UnitTest() {
    {
        assert(FindSquare(4) == 10);
    }
}

int main() {
    // int value = ReadInput();
    // int answer = FindSquare(value);
    // PrintOutput(answer);

    UnitTest();

    return 0;
}
