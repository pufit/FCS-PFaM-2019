//
// Created by Artem on 22.01.2019.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>


using i32 = int32_t;

using Alarm = std::tuple<i32, i32, i32>;

Alarm GetAlarm();

void PrintAlarm(const Alarm &alarm);


int main() {
    Alarm current_time = GetAlarm();  
	
    size_t n = 0;
    std::cin >> n;

    std::vector<Alarm> alarms;
    for (i32 i = 0; i < n; ++i) {
        // ... Что-то содержательное нужно написать тут.
    }

    std::sort(alarms.begin(), alarms.end());
	// ... Ну и сюда что-нибудь
}
