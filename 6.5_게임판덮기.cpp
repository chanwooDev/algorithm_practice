#include <iostream>
#include <string>

using namespace std;

int h, w;
char map[20][20];
int count;

pair<int ,int> block[4][2] = {{make_pair(1,0), make_pair(1,1)}, {make_pair(0,1), make_pair(1,0)}
, {make_pair(0,1), make_pair(1,1)}, {make_pair(1,-1), make_pair(1,0)}}; 

void print(){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << map[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isInside(int y, int x){
    if(y>=0 && y<h && x >= 0 && x<w)
        return true;
    return false;
}

void dfs(int y, int x){
    
    for(int i=y; i<h; i++){
        for(int j=0; j<w; j++){
            if(map[i][j] == '.'){
                for(int k=0; k<4; k++){
                    int firstP[2] = {i + block[k][0].first, j +block[k][0].second};
                    int secondP[2] ={i + block[k][1].first, j + block[k][1].second};

                    if( isInside(firstP[0], firstP[1]) && isInside(secondP[0], secondP[1]) &&
                        map[firstP[0]][firstP[1]] == '.' && map[secondP[0]][secondP[1]] == '.'){
                        map[i][j] = '@';
                        map[firstP[0]][firstP[1]] = '@'; 
                        map[secondP[0]][secondP[1]] = '@';
                        //print();
                        dfs(i, j);
                        map[i][j] = '.';
                        map[firstP[0]][firstP[1]] = '.'; 
                        map[secondP[0]][secondP[1]] = '.';
                        
                    }
                }
                return;
            }
        }
    }
    
    count++;
    return; 
}

int main(){
    int test;
    cin >> test;
    string temp;
    for(int t=0; t<test; t++){
        cin >> h >> w;
        for(int i = 0; i<h; i++){
            cin >> temp;
            for(int j = 0; j<w; j++){
                map[i][j] = temp[j];
            }
        }
        count = 0;
        
        dfs(0, 0);
        
        cout << count << endl;
    }

    return 0;
}