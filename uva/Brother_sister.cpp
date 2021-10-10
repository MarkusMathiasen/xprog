#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    while (T--){
        int N, Q; cin >> N >> Q;
        int x[N];
        for (int i = 0; i < N; i++)
            cin >> x[i];
        int q[230];
        for (int i = 0; i < 230; i++){
            int result = 0;
            for (int j = 0; j < N; j++)
                result = max(result, (i & x[j]));
            q[i] = result;
        }
        for (int i = 0; i < Q; i++){
            int a; cin >> a;
            cout << q[a] << endl;
        }
    }
}