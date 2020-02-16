#include <cstdio>
#include <vector>
using namespace std;

//@1 天秀：https://leetcode-cn.com/problems/power-of-four/solution/4de-mi-by-leetcode/

//常规
bool isPowerOfFour(int num)
{
    if (num == 1)
        return true;

    if (num % 10 != 4 && num % 10 != 6)
        return false;

    while (num >= 4)
    {
        if (num % 4 != 0)
            return false;

        num = num / 4;
    }

    return num == 1;
}
int main()
{
    printf("%d\n", isPowerOfFour(16));
}