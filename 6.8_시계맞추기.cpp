#include <iostream>
#include <vector>

using namespace std;
#define INF 9999
#define SWITCHES 10
#define CLOCKS 16



char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks){
    for(int i=0; i<CLOCKS; i++){
        if(clocks[i] != 12)
            return false;
    }
    return true;
}

void push(vector<int>& clocks, int swtch){
    for(int i=0; i<CLOCKS; i++){
        if(linked[swtch][i] == 'x'){
            clocks[i] += 3;
            if(clocks[i] == 15) clocks[i] = 3;
        }
    }    
}

int solve(vector<int>& clocks, int swtch){
    int ret = INF;
    if(swtch == SWITCHES){
        ret = areAligned(clocks) ? 0 : INF;
        return ret;
    }
    for(int cnt=0; cnt<4; cnt++){
        ret = min(ret , cnt+solve(clocks, swtch+1));
        push(clocks, swtch);
    }
    return ret;
}

int main(){
    int test;
    cin >> test;
    vector<int> clocks;
    

    for(int t=0; t<test; t++){
        clocks.clear();
        int temp;
        for(int i=0; i<CLOCKS; i++){
            cin >> temp;
            clocks.push_back(temp);
        }

        cout << solve(clocks, 0) << endl;
    }
    

    return 0;
}