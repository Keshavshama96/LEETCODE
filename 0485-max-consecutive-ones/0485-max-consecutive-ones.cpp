class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<nums.size()){
            if(nums[j]==1){
             maxlen=max(maxlen,j-i+1);
             j++;
            } 
            else {
                j++;
                i=j;
            }
        }
        return maxlen ;
    }
};