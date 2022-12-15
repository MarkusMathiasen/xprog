#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct list {
    int val;
    list *list_val;
    list *next;
    list *prev;
};

list read_list(string list_string, int pos) {
    pos++;
    if (list_string[pos] == '[') {
        return {0, nullptr, nullptr, nullptr};
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptsions(cin.failbit);
}
