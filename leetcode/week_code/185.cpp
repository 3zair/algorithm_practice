#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

string reformat(string s) {
    string nums = "";
    string strs = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            nums += (s[i]);
        } else {
            strs += (s[i]);
        }
    }

    int a = nums.size() - strs.size();
    if (nums.size() < strs.size()) {
        a = 0 - a;
    }
    if (a > 1) {
        return "";
    }

    string retStr = "";
    if (nums.size() > strs.size()) {
        for (int i = 0; i < strs.size(); ++i) {
            retStr += nums[i];
            retStr += strs[i];
        }
        retStr += nums[nums.size() - 1];
    } else if (strs.size() > nums.size()) {
        for (int i = 0; i < strs.size(); ++i) {
            retStr += strs[i];
            retStr += nums[i];
        }
        retStr += strs[strs.size() - 1];
    } else {
        for (int i = 0; i < strs.size(); ++i) {
            retStr += strs[i];
            retStr += nums[i];
        }
    }

    return retStr;
}

vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<int>> tableFood(500, vector<int>(20, 0));
    int tableNum = 0;
    int foodNum = 0;
    map<string, int> tableMap;
    map<string, int> foodMap;
    for (int i = 0; i < orders.size(); ++i) {
        if (tableMap.find(orders[i][1]) == tableMap.end()) {
            tableNum++;
            tableMap[orders[i][1]] = tableNum - 1;
        }

        if (foodMap.find(orders[i][2]) == foodMap.end()) {
            foodNum++;
            foodMap[orders[i][2]] = foodNum - 1;
        }

        tableFood[tableMap[orders[i][1]]][foodMap[orders[i][2]]]++;
    }

    vector<vector<string>> show(tableNum + 1, vector<string>(foodNum + 1, "0"));
    map<string, int>::iterator iter;
    iter = tableMap.begin();
    int i = 1;
    show[0][0] = "Table";
    while (iter != tableMap.end()) {
        printf("%s\n", iter->first.c_str());
        show[i][0] = iter->first;
        iter++;
    }
    int j = 1;
    iter = foodMap.begin();
    while (iter != foodMap.end()) {
        show[0][i] = iter->first;
        iter++;
    }
    for (int n = 1; n < tableNum + 1; ++n) {
        for (int m = 1; m < tableNum + 1; ++m) {
            show[n][m] =
                to_string(tableFood[foodMap[show[n][0]]][foodMap[show[0][m]]]);
        }
    }

    return show;
}