#include <iostream>
#include <cstring>

using namespace std;
int cache[100][100];
int map[100][100];
int n;
bool isInside(int y, int x){
    if(x >= 0 && x < n&& y >= 0 && y < n)
        return true;
    return false;
}
bool jump(int y, int x){
    if(!isInside(y,x))
        return false;
    if(x== n-1 && y == n-1)
        return true;
    
    if(cache[y][x] != -1)
        return cache[y][x];

    int step = map[y][x];
    if(jump(y+step, x) || jump(y, x+step))
        return cache[y][x] = true;
    else
        return cache[y][x] = false;
}

int main(){


    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int test;
    cin >> test;
    for(int t=0; t<test; t++){
        cin >> n;
        memset(map, 0, sizeof(map));
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }
        if(jump(0, 0))
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
    }
    return 0;
}