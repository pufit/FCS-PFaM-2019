A
// Example program
#include <iostream>
#include <string>
#include <vector>

struct Point {
    size_t xCoord = 0;
    size_t yCoord = 0;
};

struct Input {
    size_t numRows = 0;
    size_t numColumns = 0;
    std::vector<Point> points;
};

Input ReadInput() {
    size_t numRows = 0;
    size_t numColumns = 0;
    size_t numMines = 0;
    std::cin >> numRows >> numColumns >> numMines;
    std::vector<Point> points;

    for (size_t i = 0; i < numMines; ++i) {
        Point point;
        std::cin >> point.xCoord >> point.yCoord;
        points.push_back(point);
    }
    return Input{numRows, numColumns, points};
}

std::vector<std::string> MakeTable(const Input& input) {
    std::vector<std::string> table(
        input.numRows,
        std::string(input.numColumns, '0'));
        
    const auto& points = input.points;
    
    
    std::vector
    
}

void PrintTable(const std::vector<std::string>& table) {
    for (const auto& row : table) {
        std::cout << row << '\n';
    }
}

int main()
{
    Input input = ReadInput();
    std::vector<std::string> table = MakeTable(input);
    PrintTable(table);
}





L
// Example program
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string str = "abc de f";
    std::string needle = " ";
    
    std::cout << str.substr(0, str.find(needle)) << '\n';
    
    std::cout << str.substr(
        str.find(needle) + 1,
        str.find(needle, str.find(needle) + 1) - (str.find(needle) + 1)) << '\n';
}
