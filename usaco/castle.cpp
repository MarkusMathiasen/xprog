/*
ID: markus3
TASK: castle
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

void addRoom(int posN, int posM);

int M, N;
int roomCount = 0;
vector<int> roomSize;
vector<vector<int>> castle, roomNumber;    

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    
    fin >> M >> N;
    for (int i = 0; i < N; i++){
        vector<int> row;
        vector<int> roomRow;
        int value;
        for (int j = 0; j < M; j++){
            fin >> value;
            row.push_back(value);
            roomRow.push_back(0);
        }
        castle.push_back(row);
        roomNumber.push_back(roomRow);
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (roomNumber[i][j] != 0)
                continue;
            roomCount++;
            addRoom(i, j);
        }
    }
    
    cout << "Done" << endl;
    return 0;
}

void addRoom(int posN, int posM){
    int thisRoomSize = 0;
    queue<pair<int, int> > Q;
    pair<int, int> start(posN, posM);
    Q.push(start);
    while(!Q.empty()){
        thisRoomSize++;
        int n = Q.front().first;
        int m = Q.front().second;
        roomNumber[n][m] = roomCount;
        int indexVal = castle[n][m];
        if (indexVal < 8 && n > 0){
            if (roomNumber[n-1][m] == 0){
                pair<int, int> room(n-1, m);
                Q.push(room);
            }
        } else
            indexVal -=8;
        if (indexVal < 4){
            if (roomNumber[n][m+1] == 0){
                pair<int, int> room(n, m+1);
                Q.push(room);
            }
        } else
            indexVal -=4;
        if (indexVal < 2 && n+1 < N){
            if (roomNumber[n+1][m] == 0){
                pair<int, int> room(n+1, m);
                Q.push(room);
            }
        } else
            indexVal -=2;
        if (indexVal < 1){
            if (roomNumber[n][m-1] == 0){
                pair<int, int> room(n, m-1);
                Q.push(room);
            }
        } else
            indexVal -= 1;
        Q.pop();
    }
    roomSize.push_back(thisRoomSize);
}