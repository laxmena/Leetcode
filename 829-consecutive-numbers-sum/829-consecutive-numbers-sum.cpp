class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 1, count;
        while (N % 2 == 0) N /= 2;
        for (int i = 3; i * i <= N; res *= count + 1, i += 2)
            for (count = 0; N % i == 0; N /= i, count++);
        return N == 1 ? res : res * 2;   
    }
};