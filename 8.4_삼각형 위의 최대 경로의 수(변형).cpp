#include <iostream>
#include <cstring>

using namespace std;
int cache[100][100][2];
int n;
int triangle[100][100];

int maxSumPath(int y, int x){
    
    int& ret = cache[y][x][0];
    if(ret != -1)
        return ret;
    if(y == n-1)
        return  ret = triangle[y][x];
    
    return ret = triangle[y][x] + max( maxSumPath(y+1,x), maxSumPath(y+1,x+1) );
}

int pathNum(int y, int x){
    int& ret = cache[y][x][1];
    
    if(y == n-1)
        return 1;

    if(ret != -1)
        return ret;
    
    int temp = 0;
    if(maxSumPath(y+1, x) >= maxSumPath(y+1, x+1))
        temp += pathNum(y+1, x);
    if(maxSumPath(y+1, x) <= maxSumPath(y+1, x+1))
        temp += pathNum(y+1, x+1);
    return ret = temp;
}
int main(){
    int test;

    cin >>test;

    for(int t = 0; t<test; t++){
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                cin >> triangle[i][j];
            }
        }
        cout << pathNum(0,0) <<endl;
    }

    return 0;
}
