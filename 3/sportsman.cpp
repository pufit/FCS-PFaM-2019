#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <list>


using i64 = int64_t;


template<typename T>
T Read() {
    T value;
    std::cin >> value;
    return value;
}


int main() {
    const auto n = Read<size_t>();

    std::list<i64> out;
    std::unordered_map<i64, std::list<i64>::iterator> players;

    for (i64 i = 0; i < n; ++i) {
        auto num = Read<i64>(), pos = Read<i64>();
        if (players.find(pos) == players.end()) {
            players[num] = out.insert(out.end(), num);
        } else {
            players[num] = out.insert(players[pos], num);
        }
    }

    for (auto it = out.rbegin(); it != out.rend(); ++it) {
        std::cout << *it << '\n';
    }

    return 0;
}
