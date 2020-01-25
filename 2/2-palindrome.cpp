//
// Created by pufit on 25.01.2020.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <cctype>


using i32 = int32_t;


bool IsLetter(char c);


int main() {
    std::string inp, out = "YES", str;
    std::getline(std::cin, inp);

    std::copy_if(inp.begin(), inp.end(), std::back_inserter(str), IsLetter);

    for (i32 i = 0; i < str.size() / 2; i++) {
        if (std::tolower(str[i]) != std::tolower(str[str.size() - 1 - i])) {
            out = "NO";
            break;
        }
    }
    std::cout << out << "\n";
    return 0;
}


bool IsLetter(char c) {
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
