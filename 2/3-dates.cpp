//
// Created by pufit on 25.01.2020.
//

#include <iostream>
#include <cstdint>
#include <tuple>

using i32 = int32_t;


struct Date {
    i32 day{0};
    i32 month{0};
    i32 year{0};
};

template<typename T>
T Read() {
    T value;
    std::cin >> value;
    return value;
}


std::ostream& operator<<(std::ostream& out, const Date& d) {
    return out << d.day << ' ' << d.month << ' ' << d.year;
}


std::istream& operator>>(std::istream& inp, Date& d) {
    return inp >> d.day >> d.month >> d.year;
}


// def __gt__(self, x): ...
bool operator>(const Date& d1, const Date& d2) {
    return (
            std::make_tuple(d1.year, d1.month, d1.day) >
            std::make_tuple(d2.year, d2.month, d2.day)
    );
}


bool operator==(const Date& d1, const Date& d2) {
    return (
            d1.year == d2.year && d1.month == d2.month &&
            d1.day == d2.day
    );
}


bool operator<=(const Date& d1, const Date& d2) {
    return !(d1 > d2);
}

bool operator<(const Date& d1, const Date& d2) {
    return (d1 <= d2) && !(d1 == d2);
}


int main() {

    Date d1 = Read<Date>(), d2 = Read<Date>();
    std::cout << (d1 > d2) << '\n';

    return 0;
}
