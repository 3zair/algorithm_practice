/*
**1009:Product of Polynomials 
**https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int Ka, Kb;
    map<int, double> A, B, ret;
    //map<int>double
    int key;
    double value;
    scanf("%d", &Ka);
    for (int i = 0; i < Ka; ++i)
    {
        scanf("%d", &key);
        scanf("%lf", &value);
        A[key] = value;
    }

    scanf("%d", &Kb);
    for (int i = 0; i < Kb; ++i)
    {
        scanf("%d", &key);
        scanf("%lf", &value);
        B[key] = value;
    }

    map<int, double>::iterator item;

    item = A.begin();
    while (item != A.end())
    {
        printf("%d:%lf", item->first, item->second);
        item++;
    }

    item = B.begin();
    while (item != B.end())
    {
        printf("%d:%lf", item->first, item->second);
        item++;
    }
}