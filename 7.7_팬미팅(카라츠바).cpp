#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void normalize(vector<int>& num){
    num.push_back(0);
    for(int i=0; i+1 < num.size(); i++){
        if(num[i] < 0){
            int borrow = (abs(num[i]) + 9) /10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){
    vector<int> c(a.size()+ b.size()+ 1, 0);
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b.size(); j++)
            c[i+j] += a[i]*b[j];
    normalize(c);
    return c;
}

vector<int> addTo(const vector<int>& a, const vector<int>& b, int t){
 
    int csize = max(a.size(), b.size() + t);
    vector<int> c(csize, 0);
     
    for(int i=0; i<a.size(); i++){
        c[i] = a[i];
    }
    for(int i=0; i<b.size(); i++){
        c[i+t] += b[i];
    }
    normalize(c);   
    return c;
}

vector<int> subTo(const vector<int>& a, const vector<int>& b){

    if(a.size() < b.size()) return subTo(b, a);

    vector<int> c(a.size(), 0);
     
    for(int i=0; i<a.size(); i++){
        c[i] = a[i];
    }
    for(int i=0; i<b.size(); i++){
        c[i] -= b[i];
    }
    normalize(c);

    while(c.back() == 0){
        c.pop_back();
    }
    return c;        
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size();
    int bn = b.size();
    // 기저사례
    if(bn > an) return karatsuba(b, a);
    if(an == 0 || bn == 0) return vector<int>();
    if(an <= 50) return multiply(a, b);

    int half = an/2;

    vector<int> a1(a.begin(), a.begin()+half);
    vector<int> a0(a.begin()+half, a.end());
    vector<int> b1(b.begin(), b.begin()+half);
    vector<int> b0(b.begin()+half, b.end());

    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z1 = karatsuba(addTo(a0, a1, 0), addTo(b0, b1, 0));
    z1 = subTo(z1, z0);
    z1 = subTo(z1, z2);
    
    vector<int> c(0, 0);
    c = addTo(c, z0 ,2*half);
    c = addTo(c, z1, half);
    c = addTo(c, z2, 0);
    return c;
}

int hugs(const string& members, const string& fans){
    int N = members.size();
    int M = fans.size();
    vector<int> A(N), B(M);

    for(int i=0; i<N; i++){
        A[i] = (members[i] == 'M');
    }
    for(int i=0; i<M; i++)  B[M-i-1] = (fans[i] == 'M');
    
    vector<int> C = karatsuba(A, B);

    int allHuges = 0;
    for(int i= N-1; i<M; ++i){
        if(C[i]==0)
            ++allHuges;
    }
    return allHuges;
}


int main(){
    int test;
    string members;
    string fans;
    cin >> test;
    for(int t = 0; t<test; t++){
        cin >> members;
        cin >> fans;

        cout << hugs(members, fans) << endl;
    }
    return 0;
}