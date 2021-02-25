#include <iostream>
#include <set>
#include <vector>

using namespace std;


int order(const vector<int>& russian, const vector<int>& korean){
    int n = russian.size(), wins = 0;
    multiset<int> rating(korean.begin(), korean.end());
    for(int rus = 0; rus < n; rus++){
        if(*rating.rbegin() < russian[rus])
            rating.erase(rating.begin());
        else{
            rating.erase(rating.lower_bound(russian[rus]));
            wins++;
        }
    }    
    return wins;
}
int main(){
    int test,n;
    vector<int> russian, korean;

    cin >> test;
    for(int t=0; t<test; t++){
        int temp;
        cin >> n;
        
        for(int i=0; i<n; i++){
        cin >> temp;
        russian.push_back(temp);
        }
        for(int i=0; i<n; i++){
        cin >> temp;
        korean.push_back(temp);
        }
        cout << order(russian, korean) << endl;
        russian.clear(); korean.clear();
    }

    return 0;
}