#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct stuff{
    int weight, val;
    string name;
};

int testcase, n, w;
int cache[1001][101];
struct stuff a[101];


int pack(int capacity, int item){
    if(item == n)
        return 0;

    int& ret = cache[capacity][item];
    if(ret != -1)
        return ret;
    
    ret = pack(capacity, item+1);

    if(capacity >= a[item].weight)
        ret = max(ret, a[item].val + pack(capacity - a[item].weight, item+1));
    return ret;
}
void reconstruct(int capacity , int item, vector<int>& picked){
    if(item == n)
        return;
    if(pack(capacity,item) == pack(capacity,item+1))
        reconstruct(capacity,item+1, picked);
    else{
        picked.push_back(item);
        reconstruct(capacity-a[item].weight, item+1, picked);
    }
}


int main(){
    cin >> testcase;
    
    for(int t=0; t<testcase; t++){
        cin >> n >> w;

        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; i++){
            cin >> a[i].name >> a[i].weight >> a[i].val;
        }
        vector<int> picked;
        int val = pack(w,0);
        reconstruct(w, 0, picked);
        cout << val << " " << picked.size() << endl;
        for(int i=0; i<picked.size(); i++){
            cout << a[picked[i]].name <<endl;
        }
    }
    return 0;
}