class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         
         int i=0;
         int j=0;
         long long count=0;
         long long p=1;
         while(j<nums.size()){
            if(k <= 1) return 0;
            p*=nums[j];
            if(p<k){//valid
                count+=j-i+1;
                j++;
            }else if(p>=k){//invalid
                while(p>=k){//making valid by shrinking
                    p=p/nums[i];
                    i++;
                }
                if(p<k){
                     count+=j-i+1;
                    }
                j++;
            }
         }
         return count ;
    }
};