#include <iostream>
#include <cstring>

using namespace std;
int cache[501];
int n;
int arr[500];

int LIS(int x){
    int& ret = cache[x+1];
    if(ret != -1)
        return ret;
    
    ret = 1;
    for(int i=x+1; i<n; i++){
        if(x == -1 || arr[x] < arr[i])
            ret = max(ret, LIS(i)+1);
    }

    return ret;
}

int main(){
    int test;

    cin >>test;

    for(int t = 0; t<test; t++){
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << LIS(-1) -1 <<endl;
    }

    return 0;
}
