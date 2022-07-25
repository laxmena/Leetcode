class Solution {
    int maxLen = 0;
    void util(vector<string> &arr, int idx, int freq, int currLen) {
        int n = arr.size(), maxSize = 0;
        for(int i = idx; i < n; i++) {
            int currFreq = 0;
            for(char ch: arr[i]) {
                int currBit = (1 << (ch - 'a')); 
                // Duplicates
                if((currFreq & currBit) != 0) {
                    currFreq = -1;
                    break;
                }
                currFreq += currBit;
            }
            if(currFreq != -1 && (currFreq & freq) == 0) util(arr, i + 1, (currFreq | freq), currLen + arr[i].size());
        }
        maxLen = max(maxLen, currLen);
    }    
  public:
    int maxLength(vector<string> &arr) {
        util(arr, 0, 0, 0);
        return maxLen;
    }
};