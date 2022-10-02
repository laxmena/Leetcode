
// Define the disjoint-set data structure.
class UnionFind {   
    private:
        vector<int> root;
    public:
        UnionFind(int n): root(n) {
            iota(root.begin(), root.end(), 0);
        }
        int find(int x) {
            if (root[x] != x) 
                return find(root[x]);
            return root[x];
        }
        void merge(int x, int y) {
            root[x] = root[y];
        }
};

class Solution {
    public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Sort buildings by descending height.
        sort(buildings.begin(), buildings.end(), [](auto &a, auto &b) {
           return a[2] > b[2]; 
        });
        // Use a set to store the unique positions of all the edges and sort them.
        set<int> edgeSet;
        for (auto building : buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        vector<int> edges(edgeSet.begin(), edgeSet.end());
        int n = edges.size();
        
        // Map together the x value of each edge to its index in `edges`
        unordered_map<int, int> edgeIndexMap;
        for (int i = 0; i < n; ++i) {
            edgeIndexMap[edges[i]] = i;
        }

        // We'll use a disjoint set to allow us to skip past
        // already-updated indexes in `heights`.
        UnionFind edgeUF(n);
        vector<int> heights(n);
        
        // Iterate over all the buildings by descending height.
        for (auto building : buildings) {
            int leftEdge = building[0], rightEdge = building[1];
            int height = building[2];
            
            // Find the left and right starting indexes using `edgeIndexMap`.
            // We should use `find()` to jump forward to the first necessary index.
            int leftIndex = edgeUF.find(edgeIndexMap[leftEdge]);
            int rightIndex = edgeIndexMap[rightEdge];
            while (leftIndex < rightIndex) {
                heights[leftIndex] = height;
                
                // Use `merge()` to create a new shortcut to `rightIndex`.
                edgeUF.merge(leftIndex, rightIndex);
                
                // Then move forward and find the next necessary height to update.
                leftIndex = edgeUF.find(++leftIndex);
            }
        }
        
        // Finally, we just need to iterate over the updated 'heights'
        // and add every skyline key point to 'answer'.
        vector<vector<int>> answer;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || heights[i] != heights[i - 1]) {
                answer.push_back({edges[i], heights[i]});
            }
        }
        return answer;  
    }
};