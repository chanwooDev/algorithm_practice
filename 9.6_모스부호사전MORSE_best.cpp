#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int M = 1000000000 + 100;
int bino[201][201];

void calBino(){
    for(int i=0; i<=200; i++){
        bino[i][0] = bino[i][i] = 1;
        for(int j=1; j<i; j++){
            bino[i][j] = min(M, bino[i-1][j] + bino[i-1][j-1]);
        }
    }
}

string kth(int n, int m, int skip){
    if(n==0) return string(m, 'o');
    if(skip < bino[n+m-1][n-1])
        return "-" + kth(n-1, m , skip);
    return "o" + kth(n, m-1, skip - bino[n+m-1][n-1]);
}

void solve(){
    int n, m ,skip;
    cin >> n >> m>> skip;
    cout << kth(n,m,skip-1) << endl;
}

int main(){
    int t;
    cin >> t;
    calBino();
    while(t--)
        solve();

    return 0;
}