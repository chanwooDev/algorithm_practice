#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
int cache[101][101];
int n,m, A[100], B[100];


int jlis(int indexA, int indexB){
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1)
        return ret;

    ret = 2;

    

    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxElement = max(a,b);

    for(int next = indexA+1; next < n; next++)
        if(maxElement<A[next])
            ret = max(ret, jlis(next, indexB)+1);
    for(int next = indexB+1; next < m; next++)
        if(maxElement<B[next])
            ret = max(ret, jlis(indexA, next)+1);
    return ret;
}

int main(){
    int testCase;

    cin >> testCase;
    for(int t=0; t<testCase; t++){
        cin >> n >> m;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; i++){
            cin >> A[i];
        }
        for(int i=0; i<m; i++){
            cin >> B[i];
        }
        cout << jlis(-1,-1) - 2 << endl;
    }


    return 0;
}