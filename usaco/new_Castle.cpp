/*
ID: markus3
TASK: castle
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

int M, N;
int roomCount = 0;
vector<vector<int>> walls, roomMap;
vector<int> roomSizes(1, 0);
map<pair<int, int>, vector<int>> edgeList; //1 is North and 0 is East

void addRoom(int i, int j, int roomNumber){
    int roomSize = 0;
    queue<pair<int, int>> q;
    q.push(pair<int, int> (i, j));             //Add first section to queue
    roomMap[i][j] = roomNumber;

    while (!q.empty()){                        //BFS
        roomSize++;
        int y = q.front().first;
        int x = q.front().second;
        
        if (walls[y][x] >= 8){                                                              //Check for wall to south
            walls[y][x] -= 8;
            if (y < N-1 && roomMap[y+1][x] != 0 && roomMap[y+1][x] != roomNumber){  //is it a new room?
                pair<int, int> edge(roomNumber, roomMap[y+1][x]);
                if (edgeList.count(edge) == 0) edgeList.insert(pair<pair<int, int>, vector<int>> (edge, vector<int> {y+1, x, 1})); //If not found before
                else if(edgeList[edge][1] > x ||
                        (edgeList[edge][1] == x && edgeList[edge][0] < y+1) ||
                        (edgeList[edge][1] == x && edgeList[edge][0] == y+1 && edgeList[edge][2] == 0))
                                edgeList[edge] = vector<int> {y+1, x, 1};
            }
        }
        else if (y < N-1 && roomMap[y+1][x] == 0){q.push(pair<int, int> (y+1, x));roomMap[y+1][x] = roomNumber;}

        if (walls[y][x] >= 4){                                                              //Check for wall to east
            walls[y][x] -= 4;
            if (x < M-1 && roomMap[y][x+1] != 0 && roomMap[y][x+1] != roomNumber){
                pair<int, int> edge(roomNumber, roomMap[y][x+1]);
                if (edgeList.count(edge) == 0) edgeList.insert(pair<pair<int, int>, vector<int>> (edge, vector<int> {y, x, 0})); //If not found before
                else if(edgeList[edge][1] > x ||
                        (edgeList[edge][1] == x && edgeList[edge][0] < y))
                                edgeList[edge] = vector<int> {y, x, 0};
            }
        }
        else if (x < M-1 && roomMap[y][x+1] == 0){q.push(pair<int, int> (y, x+1)); roomMap[y][x+1] = roomNumber;}

        if (walls[y][x] >= 2){                                                              //Check for wall to north
            walls[y][x] -= 2;
            if (y > 0 && roomMap[y-1][x] != 0 && roomMap[y-1][x] != roomNumber){
                pair<int, int> edge(roomNumber, roomMap[y-1][x]);
                if (edgeList.count(edge) == 0) edgeList.insert(pair<pair<int, int>, vector<int>> (edge, vector<int> {y, x, 1})); //If not found before
                else if(edgeList[edge][1] > x ||
                        (edgeList[edge][1] == x && edgeList[edge][0] < y) ||
                        (edgeList[edge][1] == x && edgeList[edge][0] == y && edgeList[edge][2] == 0))
                                edgeList[edge] = vector<int> {y, x, 1}; //If this wall is better
            }
        }
        else if (y > 0 && roomMap[y-1][x] == 0){q.push(pair<int, int> (y-1, x)); roomMap[y-1][x] = roomNumber;}

        if (walls[y][x] >= 1){                                                              //Check for wall to west
            walls[y][x] -= 1;
            if (x > 0 && roomMap[y][x-1] != 0 && roomMap[y][x-1] != roomNumber){
                pair<int, int> edge(roomNumber, roomMap[y][x-1]);
                if (edgeList.count(edge) == 0) edgeList.insert(pair<pair<int, int>, vector<int>> (edge, vector<int> {y, x-1, 0})); //If not found before
                else if(edgeList[edge][1] > x-1 ||
                    (edgeList[edge][1] == x-1 && edgeList[edge][0] < y))
                            edgeList[edge] = vector<int> {y, x-1, 0}; //If this wall is better
            }
        }
        else if (x > 0 && roomMap[y][x-1] == 0){q.push(pair<int, int> (y, x-1)); roomMap[y][x-1] = roomNumber;}
        
        q.pop();
    }
    roomSizes.push_back(roomSize);
}

int sizeOf(pair<int, int> rooms){return roomSizes[rooms.first]+roomSizes[rooms.second];}
bool isBetter(pair<int, int> f, pair<int, int> s){
    vector<int> fir = edgeList[f]; vector<int> sec = edgeList[s];
    if (fir[1] < sec[1])                                            return true;
    if (fir[1] == sec[1] && fir[0] > sec[0])                        return true;
    if (fir[1] == sec[1] && fir[0] == sec[0] && fir[2] > sec[2])    return true;
    return false;
}

int main(){
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin >> M >> N;
    
    walls.assign(N, vector<int> (M));                 //Create walls-vector
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            fin >> walls[i][j];
    
    roomMap.assign(N, vector<int> (M));                //Create roomMap
    for (int i = 0; i < N; i++)                       
        for (int j = 0; j < M; j++)
            if (roomMap[i][j] == 0)
                addRoom(i, j, ++roomCount);
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << roomMap[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (map<pair<int, int>, vector<int>>::iterator it = edgeList.begin(); it != edgeList.end(); it++){
        cout << "key = (" << it->first.first << ", " << it->first.second << ")        ";
        cout << "value = {" << it->second[0] << ", " << it->second[1] << ", " << it->second[2] << "}" << endl;
    }



    fout << roomCount << endl;
    int largest = 0;
    for (int i = 1; i <= roomSizes.size(); i++)
        largest = max(roomSizes[i], largest);
    fout << largest << endl;
    pair<int, int> bestComb = edgeList.begin()->first;
    int bestCombSize = roomSizes[bestComb.first] + roomSizes[bestComb.second];
    for (map<pair<int, int>, vector<int>>::iterator it = edgeList.begin(); it != edgeList.end(); it++){
        pair<int, int> cur = it->first;
        if (sizeOf(cur) > sizeOf(bestComb)) bestComb = cur;
        else if(sizeOf(cur) == sizeOf(bestComb) && isBetter(cur, bestComb)) bestComb = cur;
    }
    vector<int> pos = edgeList[bestComb];
    fout << sizeOf(bestComb) << endl;
    fout << pos[0]+1 << " " << pos[1]+1 << " ";
    fout << (pos[2] == 0 ? 'E' : 'N') << endl;
    
    
    
    /*
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << roomMap[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (map<pair<int, int>, vector<int>>::iterator it = edgeList.begin(); it != edgeList.end(); it++){
        cout << "key = (" << it->first.first << ", " << it->first.second << ")        ";
        cout << "value = {" << it->second[0] << ", " << it->second[1] << ", " << it->second[2] << "}" << endl;
    }*/

}