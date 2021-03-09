#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int M = 1000000000+100;
int skip;
int bino[201][201];

void calbino(){
    memset(bino, 0, sizeof(bino));
    for(int i=0; i<200; i++){
        bino[i][0] = bino[i][i] = 1;
        for(int j=1; j<i; j++)
            bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
    }
}

void generate3(int n, int m , string S){
    if(skip < 0)
        return;
    if(n == 0 && m == 0){
        
        if(skip == 0 )
            cout << S;
        skip--;
        return;
    }
    if(skip >= bino[n+m][n]){
        skip -= bino[n+m][n];
        return;
    }
    if(n>0) generate3(n-1, m, S + "-");
    if(m>0) generate3(n, m-1, S + "o");
    
}

void solve(){
    int n,m;
    cin >> n >> m >> skip;
    skip--;
    generate3(n, m, string());
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        calbino();
        solve();
    }
    return 0;
}
