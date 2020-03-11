//
// Created by Artem on 26.01.2019.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>
#include <map>


using i32 = int32_t;


struct Date {
    size_t day{0};
    size_t month{0};
    size_t year{0};
};


struct Entrance {
    size_t score{0};
    std::vector<std::string> preferences;
};


struct Student {
    std::string name;
    std::string surname;
    Date date;
    Entrance entrance;
};


struct University {
    std::string name;
    size_t max_students{0};
    std::vector<Student> students;
};


std::ostream& operator<<(std::ostream& out, const Date& d) {
    return out << d.day << '.' << d.month << '.' << d.year;
}


std::istream& operator>>(std::istream& inp, Date& d) {
    return inp >> d.day >> d.month >> d.year;
}


std::ostream& operator<<(std::ostream& out, const Student& s) {
    return out << s.name << ' ' << s.surname;
}


std::istream& operator>>(std::istream& inp, Entrance& e) {
    inp >> e.score;
    size_t k = 0;
    inp >> k;
    e.preferences.reserve(k);
    for (i32 i = 0; i < k; ++i) {
        std::string x;
        inp >> x;
        e.preferences.push_back(x);
    }
    return inp;
}


std::istream& operator>>(std::istream& inp, Student& s) {
    return inp >> s.name >> s.surname >> s.date >> s.entrance;
}


std::istream& operator>>(std::istream& inp, University& u) {
    return inp >> u.name >> u.max_students;
}


bool CompareSurname(const Student& s1, const Student& s2) {
    return std::tie(s1.surname, s1.name) < std::tie(s2.surname, s2.name);
}


bool CompareResult(const Student& s1, const Student& s2) {
    return std::tie(
            s1.entrance.score, s2.date.year,
            s2.date.month, s2.date.day,
            s1.surname, s1.name) > std::tie(
            s2.entrance.score, s1.date.year,
            s1.date.month, s1.date.day,
            s2.surname, s2.name);
}


std::ostream& operator<<(std::ostream& out, const University& u) {
    out << u.name;
    std::vector<Student> students = u.students;
    std::sort(students.begin(), students.end(), CompareSurname);
    for (const auto& s : students) {
        out << '\t' << s;
    }
    return out;
}


int main() {
    std::map<std::string, University> universities;
    size_t k = 0;
    std::cin >> k;
    for (size_t i = 0; i < k; ++i) {
        University university;
        std::cin >> university;
        universities[university.name] = university;
    }

    std::vector<Student> students;
    std::cin >> k;
    for (size_t i = 0; i < k; ++i) {
        Student student;
        std::cin >> student;
        students.push_back(student);
    }
    std::sort(students.begin(), students.end(), CompareResult);

    for (const auto& student : students) {
        for (const auto& university_name : student.entrance.preferences) {
            University& university = universities[university_name];
            if (university.max_students > university.students.size()) {
                university.students.push_back(student);
                break;
            }
        }
    }

    for (const auto& university : universities) {
        std::cout << university.second << '\n';
    }
}
