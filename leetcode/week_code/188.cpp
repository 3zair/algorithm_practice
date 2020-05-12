#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> buildArray(vector<int>& target, int n) {
    int i = 0, j = 1;
    vector<string> ans;
    while (i < target.size() && j <= n) {
        if (target[i] == j) {
            ans.push_back("Push");
            j++;
            i++;
        } else {
            ans.push_back("Push");
            ans.push_back("Pop");
            j++;
        }
    }

    return ans;
}
int countTriplets(vector<int>& arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        vector<int> dpa;
        dpa.push_back(arr[i]);
        for (int j = i + 1; j < arr.size(); ++j) {
            int a = dpa[dpa.size() - 1];
            if (i < j - 1) {
                a = a ^ arr[j - 1];
                dpa.push_back(a);
            }
            vector<int> dpb;
            dpb.push_back(arr[j]);
            for (int k = j; k < arr.size(); ++k) {
                int b = dpa[dpb.size() - 1];
                b = b ^ arr[k];
                dpb.push_back(a);

                if (a == b) ans++;
            }
        }
    }

    return ans;
}