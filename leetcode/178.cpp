#include<cstdio>
#include<string.h>
#include<map>
#include<vector>
using namespace std;

// 第一题
bool check(int a){
    while(a!=0){
        if(a%10==0){
            return false;
        }
        a/=10;
    }
    return true;
}
vector<int> getNoZeroIntegers(int n) {
    int a=0, b=0;
    vector<int> ret;
    while (a<n)
    {
        a++;
        b = n-a;
        if(check(b)&&check(a)){
            ret.push_back(a);
            ret.push_back(b);
            return ret;
        }
    }

    return ret;
}


int main(){
    vector<int> ret = getNoZeroIntegers(11);
    printf("%d\n",ret[0]);
    printf("%d\n",ret[1]);
}

