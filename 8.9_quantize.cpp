#include <iostream>
#include <cstring>
#include <algorithm>
/*
일반화 -> 한 덩이씩

기저사례 체크!!
예외부분 놓침

*/

using namespace std;
const int INF = 999999999;
int cache[101][11];
int A[101],pSum[101], pSqSum[100];
int n,s;

int minError(int from, int to){
    int sum = pSum[to] - (from == 0 ? 0 : pSum[from-1]);
    int sqSum = pSqSum[to] - (from == 0 ? 0 :pSqSum[from-1]);

    int m =  int(0.5 + (double)sum/(to - from +1));

    int ret = (to - from + 1)*m*m - 2*m*sum + sqSum;
    return ret;
}
int quantize(int from, int part){
    if(from == n)
        return 0;
    if(part == 0)
        return INF;
    int& ret = cache[from][part];
    if(ret != -1)
        return ret;
    ret = INF;

    for(int size = 1; from+size<=n; size++){
        ret = min(ret, minError(from, from+size-1) + quantize(from+size, part-1));
    }

    return ret;
}
int init(int n){
    sort(A, A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];
    for(int i=0; i<n-1; i++){
        pSum[i+1] = pSum[i] + A[i+1];
        pSqSum[i+1] = pSqSum[i] + (A[i+1] * A[i+1]);
    }
}
int main(){

    int testCase = 0;
    cin >> testCase;

    for(int t =0; t<testCase; t++){

        cin >> n >> s;
        memset(cache,-1,sizeof(cache));
        for(int i=0; i< n; i++){
            cin >> A[i];
        }
        init(n);
        
        cout << quantize(0, s) << endl;
    }


    return 0;
}


