#include <cstdio>
#include <vector>
using namespace std;
// @1 厄拉多塞筛选
int countPrimes(int n)
{
    int count = 0;
    vector<bool> sins(n + 1);

    for (int i = 2; i < n; ++i)
    {

        if (!sins[i])
        {
            count++;
            for (int j = i * 2; j < n; j += i)
            {
                sins[j] = true;
            }
        }
    }
    return count;
}

// @2
// bool isPrimes(int n)
// {
//     if (n == 2 || n == 3)
//         return true;

//     int m = n % 6;
//     if (m != 1 && m != 5)
//         return false;

//     int tmp = int(sqrt(n)) + 1;
//     for (int i = 5; i < tmp; i + 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// int countPrimes(int n)
// {
//     int count = 0;
//     for (int i = 2; i < n; ++i)
//     {
//         if (isPrimes(i))
//         {
//             //printf("debug %d\n", i);
//             count++;
//         }
//     }

//     return count;
// }
int main()
{
    printf("%d\n", countPrimes(10000));
}