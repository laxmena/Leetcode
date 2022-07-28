class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        for(char& c: s) freq[c-'a']++;
        for(char& c: t) freq[c-'a']--;

        int sum = 0;
        for(int n: freq) sum += abs(n);
        return sum == 0;
    }
};