class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1;
        for(int i=digits.size()-1; i>=0 && rem == 1; i--) {
            digits[i] += 1;
            rem = digits[i]/10;
            digits[i] = digits[i]%10;
        }
        if(rem == 1) digits.insert(begin(digits), 1);
        return digits;
    }
};