class Solution {
public:
    vector<int> ch{0,2,0,0};
    
    int bfs(set<vector<int>>& visited, vector<int>& t) {
        vector<int> s({0,0,0,0});
        if(visited.count(s) > 0) return -1;
        int level = -1;
        
        queue<vector<int>> q;
        q.push(s);
        
        while(!q.empty()) {
            level += 1;
            int n = q.size();
            
            // cout << "Level: " << level << endl;
            while(n--) {
                vector<int> v = q.front();
                q.pop();
                
                if(visited.count(v) > 0) continue; // duplicate
                // cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
                
                if(v == t) return level; // exit condition

                visited.insert(v);
                
                for(int i=0; i<4; i++) {
                    vector<int> temp(begin(v), end(v));
                    if(temp[i] == 9) continue;
                    temp[i] += 1;
                    if(visited.count(temp) > 0) continue;
                    q.push(temp);
                }
                
                 for(int i=0; i<4; i++) {
                    vector<int> temp(begin(v), end(v));
                    if(temp[i] == 0) temp[i] = 9;
                    else temp[i] -= 1;
                    if(visited.count(temp) > 0) continue;
                    q.push(temp);
                }
            }
        }
        
        return -1;
    }
    
    int openLock(vector<string>& d, string tar) {
        vector<int> t({tar[0]-'0', tar[1]-'0', tar[2]-'0', tar[3]-'0'});
        set<vector<int>> visited;
        for(auto end: d) {
            vector<int> temp({end[0]-'0', end[1]-'0', end[2]-'0', end[3]-'0'});
            visited.insert(temp);
        }
        return bfs(visited, t);
    }
};
