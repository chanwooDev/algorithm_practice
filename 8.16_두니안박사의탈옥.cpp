#include <iostream>
#include <cstring>
using namespace std;

int testcase;
int n,d,p;
int oddsTownNum;
int oddsTown;
int connected[50][50];
int deg[50];
double cache[51][101];


double search(int here, int days){
    
    if(days == d) return (here == oddsTown ? 1.0 : 0.0);

    double& ret = cache[here][days];

    if(ret >= 0.0)
        return ret;

    ret = 0.0;

    for(int there = 0; there < n; there++){
        if(connected[here][there])
            ret += search(there, days+1)/deg[here];
    }
    return ret;
}

int main(){
    cin >> testcase;
    
    cout<<fixed;
    cout.precision(8);    
    for(int t=0; t<testcase; t++){
        cin >> n >> d >> p;
        memset(deg, 0 , sizeof(deg));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> connected[i][j];
                if(connected[i][j])
                    deg[i]++;
            }
        }
        cin >> oddsTownNum;
        for(int i=0; i<oddsTownNum; i++){
            memset(cache, -1, sizeof(cache));            
            cin >> oddsTown;
            cout << search(p, 0) << " ";
        }
        cout << endl;
    }
    return 0;
}