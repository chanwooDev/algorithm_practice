#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

vector<pair<int , int>> mincho;
pair<int, int> home;
int hp;
int cache[100][1024][10];
int n,m,h;

int getNum(int hp, int taken , int cur){

    int& ret = cache[hp][taken][cur];
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(int i=0; i<mincho.size(); i++){
        if(!((1 << i) & taken)){
            int dt = abs(mincho[cur].first - mincho[i].first) + abs(mincho[cur].second - mincho[i].second);
            if(dt <= hp)
                ret = max(ret, 1+getNum(hp-dt+h, taken | 1<<i, i));   
        }
    }
    if(ret == 0){
        if(abs(mincho[cur].first - home.first) + abs(mincho[cur].second - home.second) > hp)
            return ret = -9999;
        else
            return 0;
    }
    return ret;
}
int solve(int hp, int taken){
    int ret=0;
    for(int i=0; i<mincho.size(); i++){
        if(abs(mincho[i].first - home.first) + abs(mincho[i].second - home.second) <= hp){
            int dt = abs(mincho[i].first - home.first) + abs(mincho[i].second - home.second);
            ret = max(ret, 1+getNum(hp - dt+h, taken | 1<<i, i));
        }
    }
    return ret;
}

int main(){

    cin >> n >> m >> h;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                home.first = i; home.second = j;
            }
            if(temp == 2)
                mincho.push_back(pair<int, int>(i, j));            
        }
    
    cout << solve(m, 0);

    return 0;
}