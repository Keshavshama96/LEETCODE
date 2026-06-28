class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         
        int i = 0;
        int j = 0;
        long long count = 0;
        long long p = 1;

        while(j < nums.size()){

            if(k <= 1) return 0;
            p *= nums[j];
            if(p < k){ 
             // valid window: all subarrays ending at j are valid
             count += j - i + 1; //jitna subarry hai vo sbh valid hai yha pe
                j++;
            }
            else if(p >= k){ 
                // invalid window: need to shrink from left
                while(p >= k){ 
                 // making valid by shrinking
                 p = p / nums[i];
                 i++;
                }
                //loop is ended now which means window is valid now, so we must count it before moving j(nhi to j chnge kr dega window)
                count += j - i + 1;
                j++;
            }
        }
        return count;
    }
};