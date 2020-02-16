//
// Created by 张子钊 on 2020/1/27.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    if (digits.back() < 9)
    {
        digits[digits.size() - 1] += 1;

        return digits;
    }
    else
    {
        digits.pop_back();
        if (digits.size() == 0)
        {
            digits.push_back(1);
        }
        else
        {
            digits = plusOne(digits);
        }
        digits.push_back(0);

        return digits;
    }
}

int main()
{
    int a[6] = {1, 9, 9, 9, 9, 9};
    vector<int> aa(a, a + 6);
    aa = plusOne(aa);

    vector<int>::iterator ite = aa.begin();
    for (; ite != aa.end(); ite++)
    {
        printf("%d", *ite);
    }
    printf("\n");
}
