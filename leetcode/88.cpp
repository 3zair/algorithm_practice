//
// Created by 张子钊 on 2020/1/27.
//
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums1Copy(nums1);
    nums1.clear();

    int i = 0, j = 0;
    while (true)
    {
        if (i == m)
        {
            for (; j < n; ++j)
            {
                nums1.push_back(nums2[j]);
            }
            break;
        }

        if (j == n)
        {
            for (; i < m; ++i)
            {
                nums1.push_back(nums1Copy[i]);
            }
            break;
        }

        if (nums1Copy[i] < nums2[j])
            nums1.push_back(nums1Copy[i++]);
        else
            nums1.push_back(nums2[j++]);
    }

    // output
    vector<int>::iterator ite = nums1.begin();
    for (; ite != nums1.end(); ite++)
    {
        printf("%d", *ite);
    }
    printf("\n");

    return;
}

int main()
{
    int a[6] = {1, 2, 3, 0, 0, 0};
    vector<int> aa(a, a + 6);
    int b[3] = {2, 5, 6};
    vector<int> bb(b, b + 3);

    merge(aa, 3, bb, 3);
}
