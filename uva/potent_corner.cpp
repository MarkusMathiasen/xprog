#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> w, p;

int main(){
    while (cin >> N){
        w.assign((1 << N), 0);
        for (int i = 0; i < w.size(); i++)
            cin >> w[i];
        p.assign((1 << N), 0);
        for (int i = 0; i < p.size(); i++){
            int potens = 0;
            for (int j = 0; j < N; j++)
                potens += w[i ^ (1 << j)];
            p[i] = potens;
        }
        int result = 0;
        for (int i = 0; i < p.size(); i++){
            int best = 0;
            for (int j = 0; j < N; j++)
                best = max(best, p[i]+p[i ^ (1 << j)]);
            result = max(result, best);
        }
        cout << result << endl;
    }
}