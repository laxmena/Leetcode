class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char l: letters)
            if(l > target) return l;
        return letters[0];
    }
};