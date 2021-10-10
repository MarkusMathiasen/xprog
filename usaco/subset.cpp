/*
ID: markus3
TASK: subset
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

int N;
map<pair<int, int>, int> m;
int called = 0;

int perm(int place, int sum){
    if (place > N) return 0;
    pair<int, int> p(place, sum);
    if (m.count(p)) return m[p];
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    called++;
    int c1 = perm(place+1, sum);
    int c2 = perm(place+1, sum-place);
    m.insert(pair<pair<int, int>, int> (p, c1+c2));
    return c1+c2;
}

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    fin >> N;
    int firstN = N;
    for (N = N; N == firstN; N++){
        m.clear();
        //fout << N << ": ";
        int sumAll = ((N+1)*N)/2;
        if (sumAll % 2 != 0) {fout << 0 << endl; continue;}
        int result = perm(1, (int) (N+1)/(float)4*N);
        fout << result << endl;
    }
}