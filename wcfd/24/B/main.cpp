#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct st {
    vi s;
    void push(int x) { s.push_back(x); }
    int pop() { if (s.empty()) s.push_back(0); int x = s.back(); s.pop_back(); return x; }
    int& top() { if (s.empty()) s.push_back(0); return s.back();}
};

int n, i=0, j=0;
vector<string> code;
char dir = '>';
st s;
bool push_mode=false;



void step() {
    if (dir == '>') j=(j+1)%sz(code[i]);
    else if (dir == '<') j=(j-1+sz(code[i]))%sz(code[i]);
    else if (dir == '^') i=(i-1+n)%n;
    else if (dir == 'v') i=(i+1)%n;
    else assert(false);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    cin >> n;
    code.resize(n);
    getline(cin, code[0]);
    rep(i, 0, n) {
        getline(cin, code[i]);
        while (code[i].size() < 80) code[i] += ' ';
    }
    rep(i, n, 25) code.push_back(string(80, ' '));
    while (true) {
        char c = code[i][j];
        if (c == '"') push_mode = !push_mode;
        else if (push_mode) s.push(c);
        else if (isdigit(c)) s.push(c-'0');
        else if (string("+-*/%`").find(c) != string::npos) {
            int a = s.pop(), b = s.pop();
            if (c == '+')       s.push(b+a);
            else if (c == '-')  s.push(b-a);
            else if (c == '*')  s.push(b*a);
            else if (c == '/')  s.push(b/a);
            else if (c == '%')  s.push(b%a);
            else if (c == '`') s.push(b>a);
            else assert(false);
        } else if (c == '!') s.top() = s.top() == 0;
        else if (string("<>^v").find(c) != string::npos) dir = c;
        else if (c == '_') dir = s.pop()==0 ? '>' : '<';
        else if (c == '|') dir = s.pop()==0 ? 'v' : '^';
        else if (c == ':') s.push(s.top());
        else if (c == 'p') {
            int r=s.pop(), c=s.pop(), v=s.pop();
            code[r][c] = (char)v;
        } else if (c == 'g') {
            int r = s.pop(), c = s.pop();
            s.push(code[r][c]);
        } else if (c == '\\') {
            int a = s.pop(), b = s.pop();
            s.push(a), s.push(b);
        } else if (c == '$') s.pop();
        else if (c == '.') printf("%d ", s.pop());
        else if (c == ',') printf("%c", s.pop());
        else if (c == '#') step();
        else if (c == '@') break;
        else assert(c == ' ');
        step();
    }
}