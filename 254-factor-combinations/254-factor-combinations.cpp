class Solution {
public:
    map<int, set<vector<int>>> saved;
    
    bool isPrime(int n) {
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
    }
    
    set<vector<int>> _getFactors(int n) {
        if(saved.find(n) != saved.end()) return saved[n];
        
        set<vector<int>> result;
        if(n == 1 || n == 0) return set<vector<int>>();
        
        if(isPrime(n)) {
            result.insert(vector<int>(1, n));
            saved[n] = result;
            return result;
        }
        
        for(int i=2; i<=sqrt(n); i++) {
            if(n%i == 0) {
                set<vector<int>> temp = _getFactors(n/i);
                                    
                for(auto each: temp) {                    
                    vector<int> interres = each;
                    interres.push_back(i);
                    sort(begin(interres), end(interres));
                    result.insert(interres);
                    
                    for(int j=0; j<interres.size(); j++) {
                        interres = each;
                        interres[j] *= i;
                        sort(begin(interres), end(interres));
                        result.insert(interres);
                    }
                }
            }
        }
        
        saved[n] = result;
        
        return result;
    }
    
    vector<vector<int>> getFactors(int n) {
        set<vector<int>> result = _getFactors(n);
        result.erase(vector<int>(1, n));
        return vector(begin(result), end(result));
    }
};