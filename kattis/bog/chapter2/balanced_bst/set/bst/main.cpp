#include <bits/stdc++.h>
using namespace std;

struct node {
	node* left = NULL;
	node* right = NULL;
	int val;
	node(int val) : val(val) {}
};
int c = 0;
node* tree = NULL;

void insert(node*& x, int v) {
	if (x == NULL) {
		x = new node(v);
		return;
	}
	c++;
	if (x->val > v)
		insert(x->left, v);
	else
		insert(x->right, v);
	
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int x; scanf("%d", &x);
		insert(tree, x);
		printf("%d\n", c);
	}
}
