class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxOnes=0;
        int count=0;

       for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
          count++;
          maxOnes=max(maxOnes,count);
        }else if(nums[i]==0){
            count=0;
        }
       }
        return maxOnes ;
    }
};