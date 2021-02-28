#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m[10000], e[10000] , n;
int heat(){
    vector<pair<int, int>> a;
    for(int i=0; i<n; i++) 
        a.push_back(make_pair(-e[i], i));
    sort(a.begin(), a.end());

    int mSum = 0;
    int ret = -1;    
    for(int i=0; i<n; i++){
        int curNum = a[i].second;
        mSum +=  m[curNum];
        ret = max(ret, mSum + e[curNum]); 
    } 
    return ret;
}
void solve(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> m[i];
    for(int i=0; i<n; i++)
        cin >> e[i];

    cout << heat() << endl;    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}