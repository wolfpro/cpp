#include <iostream>
#include <cstdio>
#include <string>

std::string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
std::string day_week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int sel_day = 0, sel_year = 0, first_day = 0;

int num_month(std::string s)
{
    for (int i = 0; i < 12; ++i) {
        if (month[i] == s) {
            // std::cout << s << "=" << month[i] << " i=" << i << std::endl;
            return i;
        }
    }
    return -1;
}

int num_day(std::string s)
{
    for (int i = 0; i < 12; ++i) {
        if (day_week[i] == s) {
            return i;
        }
    }
    return -1;
}

int get_sum_day(int m)
{
    int sum = 31;
    if ((m == 3) || (m == 5) || (m == 8) || (m == 10)) {
        sum = 30;
    }
    if (m == 1) {
        sum = 28;
        if ((sel_year % 400 == 0 ) || ((sel_year % 4 == 0) && (sel_year % 100 != 0))) {
            sum = 29;
        }
    }
    return sum;
}

int get_day(int d, std::string s)
{
    int day = 0, numm = num_month(s);
    for (int i = 0; i < numm; ++i) {
        //std::cout << i << " " << get_sum_day(i) << std::endl;
        day += get_sum_day(i);
    }
    day += d;
    //std::cout << ((day + first_day) % 7) << std::endl;
    return ((day + first_day - 1) % 7);
}

int main()
{
    std::cin >> sel_day >> sel_year;
    int cel_mas[7] = {0, 0, 0, 0, 0, 0, 0};//Celebration day;
    int work_day[7] = {0, 0, 0, 0, 0, 0, 0};

    std::string s;
    int t;
    for (int i = 0; i < sel_day; ++i) {
        std::cin >> t >> s;
        cel_mas[get_day(t, s)]++;
    }

    std::cin >> s;
    first_day = num_day(s);

    int now_day = 0;

    for (int i = 0; i < 12; ++i) {
        int dm = get_sum_day(i);
        for (int i = 0; i < dm; ++i) {
            work_day[now_day % 7]++;
            now_day++;
            // /    now_day++;
        }
        //work_day[i] = day_in_month(i, sel_year);
    }


    int ans = 0, mans = 999999999;
    int dans = 0, dmans = 0;

    //std::cout << first_day << " gg\n";

    int d_cel_mas[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 7; ++i) {
        // std::cout << work_day[i] << " " < cel_mas[i] << "\n";
        d_cel_mas[i] = work_day[i] - cel_mas[i];
        d_cel_mas[i + 7] = work_day[i] - cel_mas[i];
    }
    for (int i = 7 - first_day; i < 14 - first_day; ++i) {
        cel_mas[i + first_day - 7] = d_cel_mas[i];
    }

    for (int i = 0; i < 7; ++i) {
        // std::cout << work_day[i] << " " << cel_mas[i] << std::endl;
        // cel_mas[i] = work_day[i] - cel_mas[i];
        if (ans < cel_mas[i]) {
            ans = cel_mas[i];
            dans = i;
        }
        if (mans > cel_mas[i]) {
            mans = cel_mas[i];
            dmans = i;
        }
        // std::cout << cel_mas[i] << " ";
    }
    //  std::cout << "\n";

    std::cout << day_week [(dans) % 7] << " " << day_week[(dmans) % 7] << std::endl;
    return 0;
}