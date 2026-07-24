class Solution {
public:
     
     //Total count of subarrays having <= k distict elements 
     int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
         
         int count=0;
         int i=0;
         int j=0;
         while(j<nums.size()){
           
          mp[nums[j]]++;

          while(mp.size()>k){
            //shrinking case (using i)
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);

            }
            i++;
          }
          count=count+(j-i+1);//all the subarrays ending at j
          j++;
         }
         return count;
     }
     

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        //main point (substraction)
      return slidingWindow(nums ,k) -slidingWindow(nums ,k-1);
    }
};