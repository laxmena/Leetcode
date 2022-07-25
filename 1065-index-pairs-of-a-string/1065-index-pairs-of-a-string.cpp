class Solution {
public:
    void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch) {
        
    }
    
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> result;
        for(string word: words) {
            size_t pos = text.find(word);
            while( pos != string::npos) {
                result.push_back(vector<int>({(int)pos, (int)(pos+word.size()-1)}));
                pos = text.find(word, pos + 1);
            }
        }
        sort(begin(result), end(result));
        return result;
    }
};