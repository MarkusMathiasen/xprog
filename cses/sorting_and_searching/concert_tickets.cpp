#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> tickets, people;
vector<int> ft;

int lsb(int i) {return (i & -i);}
void update(int i, int k){
    for (i; i <= n; i += lsb(i))
        ft[i] += k;
}
int sum(int i){
    int result = 0;
    for (i; i > 0; i -= lsb(i))
        result += ft[i];
    return result;
}

int findValid(int from, int to){
    int diff = sum(to) - sum(from-1);
    if (diff == to-from+1) return -1;
    if (from == to)
        return from;
    int mid = (from+to) / 2;
    int t1 = findValid(mid+1, to);
    if (t1 != -1)
        return t1;
    else 
        return findValid(from, mid);
}

int main(){
    cin >> n >> m;
    tickets.assign(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> tickets[i];
    sort(tickets.begin()+1, tickets.end());
    people.assign(m, 0);
    for (int i = 0; i < m; i++)
        cin >> people[i];
    ft.assign(2*(n+1), 0);

    for (int i = 0; i < m; i++){
        int upper = n;
        int lower = 1;
        int limit = people[i];
        while (upper != lower){
            int mid = (upper+lower) / 2;
            if (mid == lower) mid++;
            if (tickets[mid] > limit)
                upper = mid-1;
            else 
                lower = mid;
        }
        if (lower == 1){
            if (people[i] < tickets[lower]){
                cout << -1 << endl;
                continue;
            }
        }
        int tick = findValid(1, lower);
        if (tick != -1){
            update(tick, 1);
            cout << tickets[tick] << endl;
        }
        else 
            cout << -1 << endl;
    }
}