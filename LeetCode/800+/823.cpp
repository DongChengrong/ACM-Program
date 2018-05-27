//C++ Solkution
//刚开始因为错误的使用了int型而导致了溢出
class Solution {
public:

    long long dp[1100];

    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size();
        int Mod = 1000000007;
        sort(A.begin(), A.end());
        for (int i = 0; i < n; ++i) dp[i] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int l = A[j];
                if (A[i] % l == 0) {
                    int r = A[i] / l;
                    int p = lower_bound(A.begin(), A.end(), r) - A.begin();
                    if (A[p] == r) dp[i] = (dp[i] + dp[j] * dp[p]) % Mod;
                }
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            //printf("%d %d\n",A[i], dp[i]);
            sum = (sum + dp[i]) % Mod;
        }
        return sum % Mod;
    }
};
