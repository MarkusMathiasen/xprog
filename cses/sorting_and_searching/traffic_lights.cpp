#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, n; cin >> x >> n;
    priority_queue<int> Q;
    set<int> m;
    map<int, int> blacklist;
    m.insert(0);
    m.insert(x);
    for (int i = 0; i < n; i++){
        int p; cin >> p;
        set<int>::iterator it = m.insert(p).first;
        it--;
        int p0 = *it;
        it++; it++;
        int p2 = *it;
        Q.push(p-p0); Q.push(p2-p);
        blacklist[p2-p0]++;
        while (blacklist.count(Q.top())){
            if (blacklist[Q.top()]){
                blacklist[Q.top()]--;
                Q.pop();
            }
            else break;
        }
        cout << Q.top() << " ";
    }
    cout << endl;
}