#include <iostream>
#include <cstring>
#include <string>

using namespace std; 

int cache[100001];
string S;
int n;

int getDifficulty(int cur, int count){
    
    string numS = S.substr(cur, count);
    if(numS == string(numS.size(), numS[0]))   
        return 1;
    
    bool progressive = true;
    for(int i=0; i < numS.size()-1; i++){
        if(numS[i+1] - numS[i] != numS[1] - numS[0])
            progressive = false;
    }

    if(progressive && abs(numS[1]-numS[0]) == 1)
        return 2;
    if(progressive)
        return 5;

    bool alternating = true;

    for(int i=0; i<numS.size(); i++)
        if(numS[i] != numS[i%2])
            alternating = false;
    if(alternating) return 4; 
        
    return 10;
}
int difficultySum(int cur){
    if(cur == n)
        return 0;
    
    int& ret = cache[cur];
    if(ret != -1)
        return ret;

    ret = 300000;
    for(int i=3; i<=5; i++){
        if(cur + i <= S.size())
            ret = min(ret, getDifficulty(cur, i) + difficultySum(cur+i));
    }
    return ret;
}

int main(){
    int testCase;

    cin >> testCase;

    for(int t=0; t<testCase; t++){
        memset(cache, -1, sizeof(cache));
        cin >> S;
        n = S.size();
        cout << difficultySum(0)<<endl;
    }

    return 0;
}