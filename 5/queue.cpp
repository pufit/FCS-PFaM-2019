//
// Created by pufit on 24.02.2020.
//

#include <vector>
#include <deque>


template<typename T, typename Container = std::deque<T>>
class Queue {
public:

private:
    Container my_awesome_container_{};

};


int main() {

    Queue<int, std::vector<int>> q;

    return 0;
}