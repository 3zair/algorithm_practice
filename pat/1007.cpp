/*
**1007:Maximum Subsequence Sumb
**https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
*/
// TODO未AC 
#include<iostream>
using namespace std;

struct Node{
    int start,end;
    int value;
    int sum;
};
int main(){
    int n;
    int max;
    Node data[10010];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       scanf("%d",&data[i].value); 
    }
    data[0].sum=data[0].value;
    data[0].start=0;
    data[0].end=0;
    max=data[0].value;

    for(int i=1;i<=n;i++){
        if(data[i-1].sum>0){
            data[i].sum=data[i-1].sum+data[i].value;
            data[i].start=data[i-1].start;
            data[i].end=i;
        }else{
            data[i].sum=data[i].value;
            data[i].end=i;
            data[i].start=i;
        }
        if (max<data[i].sum){ 
            max =data[i].sum;
        }

        // printf("i:%d value:%d start:%d end:%d sum:%d\n",i ,data[i].value, data[i].start, data[i].end, data[i].sum);
       // max=data[i].sum>max?data[i].sum:max;
    }
    if (max<0){
        printf("0 %d %d", data[0].value, data[n-1].value);
    }

    for(int i=0;i<n;i++){
       if(max==data[i].sum){
            printf("%d %d %d\n", max, data[data[i].start].value, data[data[i].end].value);
            break;
       }
    }
    return 0;
}