/*
ID: markus3
TASK: kimbits
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("kimbits.out");
ifstream fin ("kimbits.in");
#define ll long long

ll N, L, I;
ll base[32][32]; //first is number of bits. Second is 1's that may be used

ll under(ll n, ll l){ //n is the number, l is the number of 1's I may use
    if (n == 0) return 0;
    if (l == 0) return 1;
    ll cp = n;
    ll msb = 0;
    while (cp != 0){
        cp /= 2;
        msb++;
    }
    ll msbNumber = (1 << --msb);
    if (msbNumber == n)
        return base[msb][l];
    return base[msb][l] + under(n-msbNumber, l-1);
}

int main() {
    fin >> N >> L >> I;
    for (ll i = 0; i < 32; i++)
        for (ll j = 0; j < 32; j++)
            base[i][j] = 1;
    for (ll i = 1; i < 32; i++)
        for (ll j = 1; j < 32; j++){
            if (j > i)
                base[i][j] = base[i][j-1];
            else if (j > 1)
                base[i][j] = base[i][j-1] + (base[i][j-1]-base[i][j-2])*(i-j+1)/j;
            else
                base[i][j] = base[i][j-1] + (base[i][j-1])*(i-j+1)/j;
            
        }
    ll upper = pow(2, 31);
    ll lower = 1;
    ll mid;
    while (upper != lower){
        mid = (upper+lower)/2;
        ll res = under(mid, L);
        if (res < I) lower = mid+1;
        else upper = mid;
    }
    int a = upper-1;
    for (int i = N-1; i >= 0; i--)
        fout << (bool)(a & (1 << i));
    fout << endl;
}