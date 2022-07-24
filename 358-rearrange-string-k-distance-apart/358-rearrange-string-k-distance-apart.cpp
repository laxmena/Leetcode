

class Solution {
public:
    string rearrangeString(string s, int k) {
        
        unordered_map<char, int> freq;
        for(auto ch : s){
            freq[ch]++;
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for(auto m : freq){
            maxHeap.push({m.second, m.first});
        }
        
        queue<pair<int, char>> q;
        string res;
        while(!maxHeap.empty()){
            auto temp = maxHeap.top();
            maxHeap.pop();
            
            res += temp.second;
            
            q.push({temp.first-1, temp.second});
            if(q.size() >= k){
                auto temp = q.front();
                q.pop();
                
                if(temp.first){
                    maxHeap.push(temp);
                }
            }            
        }
        
        return res.size() == s.size() ? res : "";
    }
};