#include<iostream>
#include<string.h>
using namespace std;

string NumberToWord(int n){
    switch (n)
    {
        case 0:
            return "zero";
        case 1 : 
            return "one";           
        case 2: 
            return "two";
        case 3: 
            return "three";
        case 4: 
            return "four";
        case 5: 
            return "five";
        case 6: 
            return "six";
        case 7: 
            return "seven";
        case 8: 
            return "eight";
        case 9: 
            return "nine";
    }
    return "";
}

int main() {
    char N[102];
    bool flag =false;
    int sum = 0;
    int result[4];
    
    scanf("%s",N);
    for (int i = 0; i < strlen(N); i ++){
        sum += N[i] - '0'; 
    }

    if (sum == 0) {
        printf("zero\n");
        return 0;
    }

    int i = 0;
    while (sum){
        result[i] = sum%10;
        sum = sum/10;
        ++i;
    }

    cout<<NumberToWord(result[--i]);
    i--;
    for (; i >= 0; --i ){
       cout<<" "<<NumberToWord(result[i]));
    }
    return 0;
}
