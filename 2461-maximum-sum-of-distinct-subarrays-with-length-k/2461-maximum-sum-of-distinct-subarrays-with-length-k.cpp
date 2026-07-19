class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //set for checking duplicates
        unordered_set<int>st;
        long long sum=0;// to calculate sum 
        long long maxsum=0;//final sum 
     
        int i=0;
        int j=0;
        while(j<nums.size()){
          //check nums[j] is present in set or not 
          //jab tak duplicate(nums[j]) nhi rehta set mai ye  calculation kro
          while(st.count(nums[j])){
            sum=sum-nums[i];//sum se minus kro
            st.erase(nums[i]);//erase kro
            i++;//aage badho jab tak duplicate(nums[j]) nhi rehta set mai a
          }
         //vhi apna purana sum krte rho
         sum=sum+nums[j];
         //set mai bhi dalte rho nums[j]
         st.insert(nums[j]);

         //window check
         //small window
         if(j-i+1<k) {
            j++;
        }//equal to window
        else if(j-i+1==k){
            maxsum=max(maxsum,sum);
            //before shrink 
            sum=sum-nums[i];//sum minus kro pichla
             st.erase(nums[i]);//erase pichla from set
             //now slide
             i++;
             j++;
         }
        }
         return maxsum;
    }
};


