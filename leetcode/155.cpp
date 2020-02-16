#include <cstdio>
#include <vector>

using namespace std;

// 1.最小绝对差
vector<vector<int> > minimumAbsDifference(vector<int>& arr) {
    vector<vector<int> > result;
    sort(arr.begin(), arr.end());
    int difference = arr[1] - arr[0];
    int r[2] = {arr[0], arr[1]};
    vector<int> rVector(r, r + 2);
    result.push_back(rVector);

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            int tmp = arr[j] - arr[i];
            if (tmp < difference) {
                difference = tmp;
                result.clear();
                int rTmp[2] = {arr[i], arr[j]};
                vector<int> rVectorTmp(rTmp, rTmp + 2);
                result.push_back(rVectorTmp);
            } else if (tmp == difference) {
                if (i == 0 && j == 1) {
                    continue;
                }
                int rTmp[2] = {arr[i], arr[j]};
                vector<int> rVectorTmp(rTmp, rTmp + 2);
                result.push_back(rVectorTmp);
            }
        }
    }
    return result;
}

int main() {
    int a[4] = {4, 2, 1, 3};
    vector<int> b(a, a + 4);
    // vector<int> c = minimumAbsDifference(b);
    printf("%d\n", b[1]);
}
