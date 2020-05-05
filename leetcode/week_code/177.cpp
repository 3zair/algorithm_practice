#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

time_t transform(string date) {
    tm _tm;
    char buf[128] = {0};
    strcpy(buf, (char*)date.c_str());
    strptime(buf, "%Y-%m-%d", &_tm);
    _tm.tm_isdst = -1;

    return mktime(&_tm);
}

time_t transform2(string date) {
    tm _tm;
    char buf[128] = {0};
    strcpy(buf, (char*)date.c_str());
    int year, month, day, hour, minute, second;
    sscanf(buf, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute,
           &second);
    _tm.tm_year = year - 1900;
    _tm.tm_mon = month - 1;
    _tm.tm_mday = day;
    _tm.tm_hour = hour;
    _tm.tm_min = minute;
    _tm.tm_sec = second;
    _tm.tm_isdst = 0;

    return mktime(&_tm);
}

int daysBetweenDates(string date1, string date2) {
    int seconds;
    seconds = difftime(transform2(date1), transform2(date2)) > 0
                  ? difftime(transform2(date1), transform2(date2))
                  : difftime(transform2(date2), transform2(date1));

    int day = seconds / 86400;
    printf("%d\n", day);

    return day;
}

// 3
bool check(int a, int b, int num) {
    return a * b == num + 1 || a * b == num + 2;
}
vector<int> closestDivisors(int num) {
    int base = sqrt(num + 2);
    printf("%d\n", base);
    vector<int> ret(2, base);
    if (check(base, base, num)) return ret;
    int diff = 0;

    int left = base, right = base;
    while (true) {
        for (int i = 0; i < diff; ++i) {
            left = base - i;
            right = base + diff - i;
            printf("diff:%d left: %d, right: %d\n", diff, left, right);
            if (check(left, right, num)) {
                ret[0] = left;
                ret[1] = right;
                for (int i = 0; i < 2; ++i) printf("%d\n", ret[i]);
                return ret;
            }
        }
        diff++;
    }
    for (int i = 0; i < 2; ++i) printf("%d\n", ret[i]);
    return ret;
}
int main() {
    // daysBetweenDates("2020-06-29", "2019-06-30");
    closestDivisors(1);
    return 0;
}