#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

int find(vector<int> nums, int a) {
    // int start = 0;
    // int end = nums.size() - 1;
    // while (start <= end) {
    //     int mid = (start + end) / 2;
    //     if (nums[mid] == a) {
    //         return mid;
    //     } else if (nums[mid] > a) {
    //         end = mid - 1;
    //         continue;
    //     } else {
    //         start = mid + 1;
    //         continue;
    //     }
    // }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == a) {
            return i;
        }
    }

    return -1;
}

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> sortedNums(nums);
    vector<int> result;
    sort(sortedNums.begin(), sortedNums.end());
    for (int i = 0; i < nums.size(); i++) {
        printf("%d\n", find(sortedNums, nums[i]));
        result.push_back(find(sortedNums, nums[i]));
    }

    return result;
}

// 02
string rankTeams(vector<string>& votes) {
    map<char, vector<int>> ranks;
    string ret = "";

    for (int i = 0; i < votes.size(); ++i) {
        for (int j = 0; j < votes[i].size(); ++j) {
            // printf("%c\n", votes[i][j]);
            if (ranks.find(votes[i][j]) != ranks.end()) {
                ranks[votes[i][j]][j]++;
            } else {
                vector<int> rank(votes[i].size(), 0);
                ranks[votes[i][j]] = rank;
            }
        }
    }
    map<char, vector<int>>::iterator iter;
    iter = ranks.begin();
    while (iter != ranks.end()) {
        // printf("%c:", iter->first);
        // for (int j = 0; j < iter->second.size(); ++j) {
        //     printf("%d ", iter->second[j]);
        // }
        // printf("\n");

        iter++;
    }

    return "ABC";
}
int main() {
    // vector<int> a{8, 1, 2, 2, 3};
    // smallerNumbersThanCurrent(a);
    vector<string> c;
    c.push_back("ACB");
    c.push_back("ACB");
    c.push_back("ABC");
    c.push_back("ACB");
    c.push_back("ACB");
    rankTeams(c);

    return 0;
}