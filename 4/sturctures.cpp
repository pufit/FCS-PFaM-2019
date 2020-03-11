#include <iostream>
#include <vector>

// <size, capacity, data>  data:-> [\x00\x00\x01...]

//  <name>       <в сред.>  <в худ.>
// push_back()     O(1)      O(n)
// operator[]      O(1)      O(1)
// pop_back()      O(1)      O(1)
// insert()        O(n)      O(n)
// erase           O(n)      O(n)


//int main() {
//    std::vector<C> v;
//    v.push_back(C()) // const 1
//    v.push_back(C()) // const 2
//    v.push_back(C()) // const 3
//}
// // des 1
// // des 2
// // des 3



#include <deque>

// <vector_1> <vector_2>   5 3 1 2 4
//     1          3
//     2          5
//     4          ^
//     \/
// .push_back(1)
// .push_back(2)
// .push_front(3)
// ...


//  <name>       <в сред.>  <в худ.>
// push_back()     O(1)      O(n)
// operator[]      O(1)      O(1)
// pop_back()      O(1)      O(1)
// pop_front()     O(1)      O(1)
// push_front()    O(1)      O(n)
// insert()        O(n)      O(n)
// erase           O(n)      O(n)


#include <map>
//  <name>       <в сред.>  <в худ.>
// insert         O(logn)   O(logn)
// operator[]     O(logn)   O(logn)
// pop()          O(logn)   O(logn)
// Бонус - поддерживает сортированный порядок

#include <unordered_map>
//  <name>       <в сред.>  <в худ. (очень плохой, или мы стреляем сами)>
// insert         O(1)       O(n)
// operator[]     O(1)       O(n)
// find()         O(1)       O(n)
// pop()          O(1)       O(n)
// НЕ ПОДДЕРЖИВАЕТ НИКАКОЙ ПОРЯДОК

#include <unordered_map>

//int main() {
//    std::unordered_map<int, int> map_of_nums;
//    int key = 42;
//    int value = 69;
//    // key in unordered_map -> print(value)
//    // else -> save(key, value)
//
//    auto it = map_of_nums.find(key);
//    if (it != map_of_nums.end()) {
//        std::cout << it->second;
//    } else {
//        map_of_nums[key] = value;
//    }
//
//}

#include <list>
//   item -> <- item -> ...
//  <name>       <в сред.>  <в худ.>
// operator[]      O(n)      O(n)
// insert()        O(1)      O(1)
// erase()         O(1)      O(1)


//
//int main() {
//    std::list<std::pair<int, int>> my_awesome_list = {
//         // {6, 7},  <-
//            {1, 2},
//            {3, 4},
//            {5, 6},
//    };
//
//    std::list<std::pair<int, int>>::iterator it = // NOLINT(hicpp-use-auto,modernize-use-auto)
//            my_awesome_list.insert(my_awesome_list.begin(), {6, 7});
//
//    ++it;  // ~указатель~ на объект внутри контейнера
//    --it;  //
//    // --it;  // UB
//
//
//    std::cout << it->first << '\n';  // 6
//    std::cout << (*it).first << '\n';  // 6
//
//    return 0;
//}
//

//
//int f(std::string&& s) {
//    return 42;
//}
//
//
//int main() {
//    std::vector<std::string> v;
//
//    size_t n = 0;
//    std::cin >> n;
//
//    for (size_t i = 0; i < n; ++i) {
//        std::string s; // len >> 10 ** 5   // size, capacity, data
//        std::cin >> s;
//
//        f(std::move(s));  // ... ... ... ... ...
//    }
//}
