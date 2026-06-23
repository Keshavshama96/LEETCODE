class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        const int MOD = 1000000007;

        if (n == 1) return k;

        vector<int> down(k + 1), up(k + 1);

        for (int v = 1; v <= k; v++) {
            down[v] = k - v;
            up[v] = v - 1;
        }

        for (int i = 3; i <= n; i++) {
            vector<int> newDown(k + 1, 0), newUp(k + 1, 0);

            long long sum = 0;
            for (int v = 1; v <= k; v++) {
                newUp[v] = sum;
                sum = (sum + down[v]) % MOD;
            }

            sum = 0;
            for (int v = k; v >= 1; v--) {
                newDown[v] = sum;
                sum = (sum + up[v]) % MOD;
            }

            down.swap(newDown);
            up.swap(newUp);
        }

        long long ans = 0;
        for (int v = 1; v <= k; v++) {
            ans = (ans + down[v] + up[v]) % MOD;
        }

        return ans;
    }
};