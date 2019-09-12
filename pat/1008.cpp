/*
**1008:elevator
**https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
*/
// 已ac，寻找更快的方法
#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[101];
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }
    int cur=0;
    int total=0;
    for (int i=0; i<n; ++i) {
        if(arr[i]>cur){
            total+=6*(arr[i]-cur);
        }else{
            total+=4*(cur-arr[i]);
        }
        cur = arr[i];
        total+=5;
    }
    printf("%d\n",total);
}