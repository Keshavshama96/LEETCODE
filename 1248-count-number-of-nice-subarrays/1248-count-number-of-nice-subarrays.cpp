class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prev=0;
        int oddCount=0;
        int res=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
              oddCount++;
              prev=0;
            }
            if(oddCount==k){
            while(oddCount==k){
                prev++;
               if(nums[i]%2!=0){
                oddCount--;
               }
              i++;
            }
            }
            res=res+prev;
           j++;
        }
      return res;
    }
};