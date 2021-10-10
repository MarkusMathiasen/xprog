/*
ID: markus3
TASK: sort3
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

int N, result = 0;
vector<int> seq;
deque<int> pos1;

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    fin >> N;
    int c1, c2 = 0; //Number of 1's and 2's
    for (int i = 0; i < N; i++){
        int val; fin >> val;
        seq.push_back(val);
        if (val == 1) pos1.push_back(i);
        if (val == 2) c2++;
    }
    c1 = pos1.size(); //Number of 1's
    while (!pos1.empty() && pos1.front() < c1) pos1.pop_front(); //Remove those, that are placed correct already
    int i = 0;
    for (; i < c1; i++){       //Place 1's
        int val = seq[i];
        if (val == 2){
            result++;
            swap(seq[pos1.front()], seq[i]);
            pos1.pop_front();
        }
        if (val == 3){
            result++;
            swap(seq[pos1.back()], seq[i]);
            pos1.pop_back();
        }
    }
    for (; i < c1+c2; i++)
        if (seq[i] != 2) result++;
    fout << result << endl;
}