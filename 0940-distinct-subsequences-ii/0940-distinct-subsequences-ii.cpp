class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        vector<long long> last(26, 0);
        long long total = 1; // Empty subsequence
        
        for (char ch : s) {
            int idx = ch - 'a';
            
            long long newTotal = (2 * total % MOD - last[idx] + MOD) % MOD;
            
            // Subsequences ending with this character
            last[idx] = total;
            
            total = newTotal;
        }
        
        // Remove empty subsequence
        return (total - 1 + MOD) % MOD;
    }
};