#include <iostream>
#include <string>

using namespace std;
char map[5][5];
int visited[5][5];
int findString[10];
string s[10];
int dir[8][2] = {{-1, 1}, {0, 1}, {1,1}, {1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};

int cnt;

bool isInside(int y, int x){
    if(y>=0 && y<5 &&x>=0 &&x<5)
        return true;
    return false;
}


int findWord(int y, int x, const string& word){
    if(!isInside(y,x)){
        return 0;
    }
    if(word[0] != map[y][x]){
        return 0;
    }
    if(word.size() == 1)
        return 1;

    int complete=0;
    int nextX, nextY;
    for(int i=0; i<8; i++){
        nextY = y+dir[i][0];
        nextX = x+dir[i][1];

        if(findWord(nextY, nextX, word.substr(1))){
            return 1;
        }
        
    }
    return 0;
}

int main(){
    int test;
    cin >> test;

    for(int t=0; t<test; t++){

        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                cin >> map[i][j];
            }
        }

        int wordCase;

        cin >> wordCase;

        for(int i=0; i<wordCase; i++){
            cin >> s[i];
        }

        //찾기

        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                for (int k = 0; k < wordCase; k++){
                    if (!findString[k]){
                        findString[k]  = findWord(i,j,s[k]);
                    }
                }
            }
        }


        for(int i=0; i<wordCase; i++){
            cout << s[i] << " " << findString[i] <<endl;
        }
    }
    return 0;
}