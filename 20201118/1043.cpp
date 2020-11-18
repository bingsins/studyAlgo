class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n+1, INT_MIN);
        int maxA = INT_MIN;
        for (int i = 1; i <= K; i++) {
            maxA = max(maxA, A[i - 1]);
            dp[i] = maxA * i;
        }
        for (int i = K + 1; i < n + 1; i++) {
            maxA = INT_MIN;
            for (int len = 1; len <= K; len++) {
                maxA = max(maxA, A[i - len]);
                dp[i] = max(dp[i], maxA * len + dp[i - len]);
            }
        }
        return dp[n];
    }
};

/* 
dp[n]: Partition Array for Maximum Sum from A[0], A[1], ... A[n-1].
dp[0] = 0
dp[1] = A[0]
dp[2] = max(A[1], A[0]) * 2
...
dp[K] = max(A[k-1], ..., A[0]) * K
dp[i] = max(A[i-1] + dp[i-1], max(A[i-1], A[i-2])*2 + dp[i-2], ..., max(A[i-1], ..., A[i-k])*k + dp[i-k])
dp[A.size()]

*/
