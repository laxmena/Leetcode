class Solution {
public:
    void recurse(int edge, map<int, set<int> >& mem, set<int> &isVisited) {
        if(isVisited.find(edge) != isVisited.end()) return;
        isVisited.insert(edge);
        
        set<int> connections = mem[edge];

        for(auto c: connections) {
            if(isVisited.find(c) != isVisited.end()) continue;
            recurse(c, mem, isVisited);
            isVisited.insert(c);
            mem.erase(c);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, set<int> > mem;
        set<int> isVisited;
        for(auto edge: edges) {
            int e1 = edge[0], e2 = edge[1];
            if(mem.find(e1) == mem.end()) mem[e1] = set<int>();
            if(mem.find(e2) == mem.end()) mem[e2] = set<int>();
            mem[e1].insert(e2);
            mem[e2].insert(e1);
        }
        
        for(int i=0; i<n; i++) {
            recurse(i, mem, isVisited);
        }
        return mem.size();
    }
};