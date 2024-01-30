#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll inf = 1e9;

template<class T>
ll alignment(vector<T>& A, vector<T>& B, vector<vi>& dp) {
    dp.assign(sz(A)+1, vi(sz(B)+1, 0));
    rep(i, 0, sz(A)+1) dp[i][0] = i*(-1); // delete score -1
    rep(j, 1, sz(B)+1) dp[0][j] = j*(-1); // insert score -1
    rep(i, 1, sz(A)+1) rep(j, 1, sz(B)+1) {
        // match and mismatch score (2 and -inf)
        dp[i][j]=dp[i-1][j-1]+(A[i-1]==B[j-1]?2:-inf);
        dp[i][j]=max(dp[i][j],dp[i-1][j]-1); // delete -1
        dp[i][j]=max(dp[i][j],dp[i][j-1]-1); // insert -1
    }
    return dp[sz(A)][sz(B)];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a, b;
	getline(cin, a); getline(cin, b);
    vector<char> A, B;
    for (char c : a) A.push_back(c);
    for (char c : b) B.push_back(c);
    vector<vi> dp;
    alignment(A, B, dp);
    string s = "";
    ll i = sz(A), j = sz(B);
    while (i > 0 || j > 0) {
        if (i == 0) s.push_back(B[--j]);
        else if (j == 0) s.push_back(A[--i]);
        else if (A[i-1] == B[j-1])
            s.push_back(A[--i]), j--;
        else if (dp[i][j-1] > dp[i-1][j])
            s.push_back(B[--j]);
        else
            s.push_back(A[--i]);
    }
    reverse(all(s));
	printf("%s\n", s.c_str());
}
