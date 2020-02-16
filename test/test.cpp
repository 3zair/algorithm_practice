#include <string.h>
#include <iostream>
using namespace std;

bool cmp(string a, string b) { return strcmp(a.c_str(), b.c_str()) < 0; }

int main() {
    // char s1[10],s2[10],s3[10];
    // char a;
    // scanf("%s%s%s",s1,s2,s3);
    // //a = getchar();
    // scanf("%s",&a);
    // cout<<"s1:"<<s1<<endl;
    // cout<<"s2:"<<s2<<endl;
    // cout<<"s3:"<<s3<<"a:"<<a<<endl;
    // int a=-23;
    // printf("%d %d\n", a/10,a%10);
    // printf("%d \n", cmp("a","b"));
    // int x =0;
    // float y = 0;
    // cin>>x;
    // if(x<0){
    //     y=0;
    // }else if(x<=10){
    //     y=x;
    // }else if(x<=20){
    //     y=10;
    // }else if(x<40){
    //     y=-0.5*x+20;
    // }
    // cout<<y<<endl;
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", i);
    }
    return 0;
}