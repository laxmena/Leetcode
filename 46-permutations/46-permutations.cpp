class Solution {
public:
    // map<vector<int>, set<vector<int>>> mem;
    
    set<vector<int>> recurse(vector<int>& arr) {
        set<vector<int>> result;       
        
        // Exit statements
        if(arr.size() == 0) return result;
        if(arr.size() == 1) {
            vector<int> temp({arr[0]});
            result.insert(temp);
            return result;
        };
        
        // Check if we have combinations stored in the hash
        // if(mem.find(arr) != mem.end()) return mem[arr];
        
        // Iterate through each element in array
        // Generate combinations of all remaining elements using recursion
        // Include the selected num in first and last position of each combination
        
        for(int i=0; i<arr.size(); i++) {
            // select the current iter of the element and remove it from array
            int num = arr[i]; 
            arr.erase(arr.begin()+i);
            
            // Get combination of the remaining elements
            set<vector<int>> temp = recurse(arr);
            
            for(auto vec: temp) {
                // Adding num to each combinatin
                vec.push_back(num);
                result.insert(vec);
            }
            
            // Add the element back in the same position for other recursive actions
            arr.insert(arr.begin()+i, num);
        }
        
        // mem[arr] = result;
        return result;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> resset = recurse(nums);
        vector<vector<int> > result(begin(resset), end(resset));
        return result;        
    }
};