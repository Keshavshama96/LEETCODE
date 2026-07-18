class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int minii=INT_MAX;
        int maxii=INT_MIN;
        for(int i=0;i<nums.size();i++){
            minii=min(minii,nums[i]);
            maxii=max(maxii,nums[i]);
        }
        return __gcd(minii, maxii);
    }
};