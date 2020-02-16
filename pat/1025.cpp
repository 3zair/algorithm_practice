/*
**1025:PAT Ranking
**https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872
*/
#include<cstdio>
#include<algorithm>
using namespace std;

struct Member{
    char RegistrationNumber[14];
    int Score;
    int LocalRank;
    int LocationNum;
}stu[30010];

bool Compare(Member a, Member b){
    if(a.Score != b.Score){
        return a.Score>b.Score;
    }else{
        return strcmp(a.RegistrationNumber,b.RegistrationNumber) < 0;
    }
}

int main(){

    int n=0, lastN=0;
    int N;
    scanf("%d",&N);
    for(int i=1; i<=N; ++i)
    {
        int k;
        scanf("%d", &k);
        for(int j=1; j<=k; ++j)
        {
            scanf("%s %d",stu[n].RegistrationNumber,&stu[n].Score);
            stu[n].LocationNum = it;
            n++;
        }
        sort(stu+lastN, stu+n, Compare);
        stu[lastN].LocalRank = 1;
        for(int j=lastN+1; j<=n; ++j)
        {
            if(stu[j].Score==stu[j-1].Score)
            {
                stu[j].LocalRank=stu[j-1].LocalRank;
            }else{
                stu[j].LocalRank= j-lastN+1;
            }
        }
        lastN = n;
    }
    sort(stu,stu+n,Compare);
    int rank=1;
    printf("%d\n",n+1);
    printf("%s %d %d %d\n",stu[0].RegistrationNumber, rank, stu[0].LocationNum, stu[0].LocalRank);
    for(int j=1; j<=n; ++j)
        {
            if(stu[j].Score!=stu[j-1].Score)
            {
                rank = j+1;
            }
            printf("%s %d %d %d\n",stu[0].RegistrationNumber, rank, stu[0].LocationNum, stu[0].LocalRank);
        }
}