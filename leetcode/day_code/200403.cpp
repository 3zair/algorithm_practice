#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int myAtoi(string str) {
    vector<int> num;
    bool opertorFlag = true;
    bool flag = false;
    for (int i = 0; i < str.size(); ++i) {
        if (!flag && str[i] == ' ' && num.size() == 0) {
            continue;
        }

        if (!flag && str[i] == '-' && num.size() == 0) {
            opertorFlag = false;
            flag = true;
            continue;
        }

        if (!flag && str[i] == '+' && num.size() == 0) {
            opertorFlag = true;
            flag = true;
            continue;
        }

        if (str[i] == '0' && num.size() == 0) {
            continue;
        }

        if (num.size() > 10) {
            return opertorFlag ? INT32_MAX : INT32_MIN;
        }

        if (str[i] < '0' || str[i] > '9') {
            break;
        }

        num.emplace_back(str[i] - '0');
    }

    long int ret = 0;
    for (int i = 0; i < num.size(); i++) {
        ret *= 10;
        ret += num[i];

        if (ret > INT32_MAX) {
            return opertorFlag ? INT32_MAX : INT32_MIN;
        }
    }

    return opertorFlag ? ret : 0 - ret;
}