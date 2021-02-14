#include <iostream>
#include <cstring>

using namespace std;

#define MOD 10000000

int cache[101][101];
int test,num;

int f(int n , int first){

    if(n == first)
        return 1;
    
    int& ret = cache[n][first];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int second = 1; second <= n-first; second++){
        int add;
        (first == 0) ? add= 1 : add = (first + second -1);
        add *= f(n-first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main(){

    cin >> test;

    for(int t = 0; t < test; t++){
        cin >> num;
        memset(cache, -1, sizeof(cache));
        cout << f(num, 0) << endl;
    }
    return 0;
}