#include<stdio.h>
#include<cstring>
using namespace std;

int main()
{
    char str[100000];
    scanf("%s", str);
    int p = 0, t = 0, total = 0;
    bool flag = true;
    for(int i=0; i<strlen(str); ++i)
    {
       if(str[i]=='P')
        {
            p++;
        }

        if(str[i]=='A')
        {
            if(flag==true)
            {
                for(int j=i+1; j<strlen(str); ++j)
                {
                     if(str[j]=='T')
                     {
                         t++;
                     }
                }
                flag=false;
            }
            total += (p*t)%1000000007;
            
        }

        if(str[i]=='T' && flag==false)
        {
            t--;
        }
    }
    printf("%d \n", total);
}