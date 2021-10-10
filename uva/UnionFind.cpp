#include <vector>
class UnionFind{
    private:
    std::vector<int> p, rank;
    int findSet(int i){
        return (p[i] == i ? i : p[i] = findSet(p[i]));
    }

    public:
    UnionFind(int N){
        p.assign(N, 0); rank.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;           
    }
    
    bool isSameSet(int i, int j){return (findSet(i) == findSet(j));}
    
    void unionSet(int i, int j){
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};