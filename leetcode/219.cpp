#include <cstdio>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    if (k > nums.size())
        k = nums.size();

    for (vector<int>::iterator ite = nums.begin(); ite < nums.end() - k; ++ite)
    {
        for (int i = 1; i <= k; ++i)
        {
            if (*ite == *(ite + i))
            {
                return true;
            }
        }
    }

    //printf("debug k:%d\n", *(nums.end() - 2));
    for (int j = 2; j <= k; ++j)
    {
        vector<int>::iterator ite = nums.end() - j;

        for (int n = 1; n < j; ++n)
        {
            //printf("debug k:%d j:%d n:%d\n", k, j, n);
            if (*ite == *(ite + n))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int a[10] = {1, 1};
    vector<int> aa(a, a + 2);
    printf("result: %d\n", containsNearbyDuplicate(aa, 2));
}