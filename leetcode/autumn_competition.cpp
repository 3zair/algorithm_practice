#include <isotream>
using namespace std;

bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
    int a=0,b=0,u=0,v=0;
    for(auto i:command)if(i=='R')a++;
    else b++;
    bool c=0;
    for(auto i:command)
    {
         for(auto j:obstacles)if(j[0]<=x&&j[1]<=y&&(j[0]-u)%a==0&&(j[1]-v)%b==0&&(j[0]-u)/a==(j[1]-v)/b)return 0;
            if((x-u)%a==0&&(y-v)%b==0&&(x-u)/a==(y-v)/b)c=1;
            if(i=='R')u++;
            else v++;
    }
    return c;
 }

int main(){
}