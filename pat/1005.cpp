/*
** 1005:spell it right
** https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336
*/
#include <string.h>
#include <iostream>
using namespace std;

// string NumberToWord(int n){
//     switch (n)
//     {
//         case 0:
//             return "zero";
//         case 1 :
//             return "one";
//         case 2:
//             return "two";
//         case 3:
//             return "three";
//         case 4:
//             return "four";
//         case 5:
//             return "five";
//         case 6:
//             return "six";
//         case 7:
//             return "seven";
//         case 8:
//             return "eight";
//         case 9:
//             return "nine";
//     }
//     return "";
// }

// int main() {
//     char N[102];
//     bool flag =false;
//     int sum = 0;
//     int result[4];

//     scanf("%s",N);
//     for (int i = 0; i < strlen(N); i ++){
//         sum += N[i] - '0';
//     }

//     if (sum == 0) {
//         printf("zero\n");
//         return 0;
//     }

//     int i = 0;
//     while (sum){
//         result[i] = sum%10;
//         sum = sum/10;
//         ++i;
//     }

//     printf("%s",NumberToWord(result[--i]).c_str());
//     i--;
//     for (; i >= 0; --i ){
//        printf(" %s",NumberToWord(result[i]).c_str());
//     }
//     return 0;
// }

// 改进版
int main() {
    string englishWords[10] = {"zero", "one", "two",   "three", "four",
                               "five", "six", "seven", "eight", "nine"};
    char N[102], s[5];
    scanf("%s", N);
    int sum = 0;
    for (int i = 0; i < strlen(N); i++) {
        sum += N[i] - '0';
    }
    sprintf(s, "%d", sum);
    for (int j = 0; s[j] != '\0'; j++) {
        printf("%s", englishWords[s[j] - '0'].c_str());
        if (s[j + 1] != '\0')
            printf(" ");
        else
            printf("\n");
    }
    int a = 1;
    while (true) {
        /* code */
    }
    return 0;
}
