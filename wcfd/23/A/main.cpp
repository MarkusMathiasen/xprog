#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string in;
vector<vi> graph;
string atom;
vi parenthesis_pair;
vi digit = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

pair<ll, bool> parse(ll pos) { // return first atom, and wether it was double to that	
	bool double_binding = false;
	if (in[pos] == '=') double_binding = true, pos++;

	char c = in[pos];
	ll num = sz(atom);
	atom.push_back(c);
	graph.push_back(vi());

	ll nxt = pos+1;
	while (nxt < sz(in) && isdigit(in[nxt])) { // handle digit
		ll d = in[nxt]-'0';
		if (digit[d] == -1)
			digit[d] = num;
		else {
			ll num2 = digit[d];
			digit[d] = -1;
			graph[num2].push_back(num);
			graph[num].push_back(num2);
		}
		nxt++;
	}
	while (nxt < sz(in) && in[nxt] == '(') { // handle parenthesis
		auto [num2, is_double] = parse(nxt+1);
		rep(i, 0, is_double+1) {
			graph[num].push_back(num2);
			graph[num2].push_back(num);
		}

		nxt = parenthesis_pair[nxt]+1;
	}
	if (nxt < sz(in) && in[nxt] == ')') // end of my parenthesis (does not have next atom)
		return {num, double_binding};
	if (nxt < sz(in)) {
		auto [num2, is_double] = parse(nxt);
		rep(i, 0, is_double+1) {
			graph[num].push_back(num2);
			graph[num2].push_back(num);
		}
	}
	return {num, double_binding};
}

void print_graph() {
	rep(i, 0, sz(graph)) {
		printf("%lld: {", i);
		for (ll x : graph[i]) printf("%lld, ", x);
		printf("}\n");
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> in;

	parenthesis_pair.assign(sz(in), -1);
	stack<ll> st;
	rep(i, 0, sz(in)) {
		if (in[i] == '(')
			st.push(i);
		if (in[i] == ')')
			parenthesis_pair[i] = st.top(),
			parenthesis_pair[st.top()] = i,
			st.pop();
	}

	parse(0);

	vi res = {0, 0, 0};
	rep(i, 0, sz(graph)) {
		if (atom[i] == 'C' && sz(set(all(graph[i]))) == sz(graph[i])) {
			ll O = false, deg = 0; // Check if we have alcohol group
			for (ll x : graph[i]) {
				O |= atom[x] == 'O' && sz(graph[x]) == 1;
				deg += atom[x] == 'C';
			}
			if (O) res[max(0ll, deg-1)] = true;
		}
	}
	if (!res[0] && !res[1] && !res[2]) printf("0");
	rep(i, 0, 3) if (res[i]) printf("%lld ", i+1);
	printf("\n");
}
