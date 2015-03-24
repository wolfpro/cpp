#include <iostream>
#include <string>

int date[5];
int adate[5];
int check_date[5];

bool used[5];

bool is_date(int *mas) {
    int d = mas[0];
    int m = mas[1];
    int y =  mas[2];
    int cloc = mas[3];
    int sec = mas[4];

    if (sec > 59 || cloc > 23 || m > 12)
        return false;

    int sum = 31;
    if ((m == 3) || (m == 5) || (m == 8) || (m == 10)) {
        sum = 30;
    }
    if (m == 1) {
        sum = 28;
        if ((y % 400 == 0 ) || ((y % 4 == 0) && (y % 100 != 0))) {
            sum = 29;
        }
    }
    if (d > sum)
        return false;

    return true;
}

int get_day_at(int *mas) {
    int d = mas[0];
    int m = mas[1];
    int y =  mas[2];
    int cloc = mas[3];
    int sec = mas[4];

    int d2 = mas[0];
    int m2 = mas[1];
    int y2 =  mas[2];
    int cloc2 = mas[3];
    int sec2 = mas[4];

    if (d2 * m2 == 0)
        return 0;

    if (y > y2)
        return 0;
    if (y == y2 && m > m2)
        return 0;
    if (y == y2 && m == m2 && d > d2)
        return 0;
    if (y == y2 && m == m2 && d == d2 &&  cloc > cloc2)
        return 0;
    if (y == y2 && m == m2 && d == d2 &&  cloc == cloc2 && sec > sec2)
        return 0;

    return 1;
}

void r(int s) {
    if (s == 5) {
        if (is_date(check_date) && (get_day_at(check_date))) {
            for (int i = 0; i < 5; ++i) {
                adate[i] = check_date[i];
            }
        }
        return;
    }

    for (int i = 0; i < 5; ++i) {
        if (!used[i]) {
            //  t = date[i];
            used[i] = 1;
            check_date[s] = date[i];
            r(s + 1);
            used[i] = 0;
        }
    }
}

int main() {

    std::string a, b;
    std::cin >> a >> b;
    //std::cout << a << " " << b << std::endl;

    date[0] = (a[0] - '0') * 10;
    date[0] += a[1] - '0';
    date[1] = (a[3] - '0') * 10;
    date[1] += a[4] - '0';
    date[2] = (a[6] - '0') * 10;
    date[2] += a[7] - '0';
    date[3] = (b[0] - '0') * 10;
    date[3] += b[1] - '0';
    date[4] = (b[3] - '0') * 10;
    date[4] += b[4] - '0';

    for (int i = 0; i < 5; ++i) {
        // std::cout << date[i];
        adate[i] = date[i];
    }

    for (int i = 0; i < 5; ++i) {
        check_date[0] = date[i];
        used[i] = 1;
        r(1);
        used[i] = 0;
    }

    for (int i = 0; i < 5; ++i) {
        if (adate[i] / 10 == 0) {
            std::cout << 0;
        }
        std::cout << adate[i];
        if (i == 0  || i == 1)
            std::cout << ".";
        if (i == 2)
            std::cout << " ";
        if (i == 3)
            std::cout << ":";
    }
    std::cout << std::endl;

    return 0;
}