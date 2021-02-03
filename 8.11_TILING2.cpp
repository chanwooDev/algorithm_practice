#include <iostream>
#include <cstring>

using namespace std;
int cache[101];

int tiling2(int n){

    if(n == 0 || n == 1)
        return 1;

    int& ret = cache[n];
    if(ret != -1)
        return ret;

    return ret = (tiling2(n-1) + tiling2(n-2))%1000000007;
}


int main(){
    int testcase;
    int n;
    cin >> testcase;
    for(int t=0; t<testcase; t++){
        memset(cache, -1 , sizeof(cache));
        cin >> n;

        cout << tiling2(n) << endl;
    }

    return 0;
}