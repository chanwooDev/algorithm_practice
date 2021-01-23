#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int cache[101][101];
string W;
string S;

int f(int w, int s){

    
    while(w<W.size() && s<S.size() &&(W[w] == '?' || W[w] == S[s])){
        s++;
        w++;
    }

    int& ret = cache[w][s];
    if(ret != -1)
        return ret;

    if(w== W.size())
        return ret = (s == S.size());

    if(W[w] == '*'){
        if((f(w+1, s) || (s < S.size() && f(w, s+1))))
            return ret = 1;
    }
        
    return ret = 0;
}

int main(){

    int test;
    cin >> test;
    vector<string> ss;
    for(int t=0; t<test; t++){
        
        cin >> W;
        int count;
        cin >> count;
        for(int i=0; i<count; i++){
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if(f(0 ,0)) ss.push_back(S);
        }
        sort(ss.begin(), ss.end());
        for(int i =0; i<ss.size(); i++)
            cout << ss[i] << endl;
        ss.clear();
    }

    return 0;
}