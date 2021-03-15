#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cacheLen[501];
int cacheSum[501];
vector<int> S;
const int M = 2000000000 + 1;

int lis(int start){

    int& ret = cacheLen[start+1];
    if(ret != -1)
        return ret;
    
    ret = 1;
    for(int next = start+1; next<S.size(); next++){
        if(start == -1 || S[next] > S[start])
            ret = max(ret, 1+lis(next));
    }
    return ret;
}

int count(int start){
    if(lis(start) == 1) return 1;
    int& ret = cacheSum[start+1];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int next = start+1; next<S.size(); next++){
        if((start == -1 || S[start] < S[next]) && lis(start) == 1 + lis(next)){
            ret = min<long long>(M, (long long)ret + count(next));
        }
    }
    return ret;
}

void kLis(int start, int skip, vector<int>& line){
    if(start != -1) line.push_back(S[start]);
    vector<pair<int, int>> table;
    for(int next= start + 1; next<S.size(); next++){
        if((start == -1 || S[start] < S[next]) && lis(start) == 1+lis(next))
            table.push_back(make_pair(S[next], next));
    }
    sort(table.begin(), table.end());

    for(int next = 0; next < table.size(); next++){
        int idx = table[next].second;
        
        if(count(idx) <= skip){
            skip -= count(idx);
        }
        else{
            kLis(idx, skip, line);
            break;
        }
    }
}

void solve()
{
    int n, skip;
    cin >> n >> skip;
    memset(cacheLen, -1, sizeof(cacheLen));
    memset(cacheSum, -1, sizeof(cacheSum));
    S.clear();

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        S.push_back(temp);
    }
    vector<int> line;
    kLis(-1, skip-1, line);
    cout << line.size() << endl;
    for(int i=0; i<line.size(); i++){
        cout << line[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}