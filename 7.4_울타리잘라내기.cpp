#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> h; 

int solve(int left, int right){
    int ret;

    if(left == right)
        return h[left];
    int mid = (left + right)/2;
    ret  = max(solve(left, mid), solve(mid+1, right));

    int lo = mid, hi = mid+1;
    int height = min(h[lo], h[hi]);
    //기저사례2 w=2일때
    ret = max(ret, height*2);

    while(left < lo || right > hi){
        if(right > hi && (left == lo || h[lo-1] < h[hi+1])){
            hi++;
            height = min(height, h[hi]);
        }
        else{
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height*(hi-lo+1));
    }
    return ret;
}

int main(){
    int test;
    int temp;
    cin >> test;
    for(int t=0; t<test; t++){
        h.clear();
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> temp;
            h.push_back(temp);
        }

        cout << solve(0, n-1) <<endl;
    }

    return 0;
}