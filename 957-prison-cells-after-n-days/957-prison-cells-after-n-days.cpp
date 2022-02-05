class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& c, int N) {
      vector<int> f_c, next_c(c.size(), 0);
      for (int cycle = 0; N-- > 0; c = next_c, ++cycle) {
        for (auto i = 1; i < c.size() - 1; ++i) next_c[i] = c[i - 1] == c[i + 1];
        if (cycle == 0) f_c = next_c;
        else if (next_c == f_c) N %= cycle;
      }
      return c;
    }
};

