/*
ID: markus3
TASK: shopping
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("shopping.out");
ifstream fin ("shopping.in");
#define v vector

vector<vector<int>> offers;
map<int, int> m;
vector<int> price;
int dp[6][6][6][6][6];

int basePrice(vector<int> &b){
    int result = 0;
    for (int i = 0; i < price.size(); i++)
        result += b[i] * price[i];
    return result;
}

int bestPrice(vector<int> b){
    if (dp[b[0]][b[1]][b[2]][b[3]][b[4]] != -1) return dp[b[0]][b[1]][b[2]][b[3]][b[4]];
    int result = basePrice(b);
    for (int i = 0; i < offers.size(); i++){
        vector<int> newb = b;
        bool valid = true;
        for (int j = 0; j < 5; j++){
            newb[j] -= offers[i][j];
            if (newb[j] < 0) valid = false;
        }
        if (!valid) continue;
        result = min(result, bestPrice(newb)+offers[i].back());
    }
    return dp[b[0]][b[1]][b[2]][b[3]][b[4]]=result;
}

int main() {
    int offercount; fin >> offercount;
    offers.assign(offercount, vector<int>(6, 0));
    for (int i = 0; i < offercount; i++){
        int types; fin >> types;
        for (int j = 0; j < types; j++){
            int k, c; fin >> c >> k; //c = productcode; k = number of items in the offer
            if (m.count(c) == 0) m[c] = m.size();
            offers[i][m[c]] = k;
        }
        int p; fin >> p;
        offers[i].back() = p; //last element = p
    }

    int items; fin >> items;
    price.assign(items, 0);
    vector<int> b(5, 0);
    for (int i = 0; i < items; i++){
        int c, k, p; fin >> c >> k >> p; //c = productcode; k = startamount; p = baseprice
        if (m.count(c) == 0) m[c] = m.size();
        price[m[c]] = p;
        b[m[c]] = k;
    }

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++)
                for (int l = 0; l < 6; l++)
                    for (int m = 0; m < 6; m++)
                        dp[i][j][k][l][m] = -1;
    fout << bestPrice(b) << endl;
    cout << "hello" << endl;
}