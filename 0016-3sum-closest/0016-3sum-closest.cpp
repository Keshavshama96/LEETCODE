class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     //sort the array
     sort(begin(nums),end(nums));
       
       long long closest_sum=INT_MAX;//store closest
     
       for(int i=0;i<nums.size();i++){
        int fix=nums[i];
       //2 pointer on left array 
       int j=i+1;
       int k=nums.size()-1;
       while(j<k){
        int sum =nums[j]+nums[k]+fix;
        if(sum>target){
         
         if(abs(closest_sum-target)> abs(sum-target)){
         closest_sum=sum;
         }else{
            closest_sum=closest_sum;
         }
        
         k--;
        }
        else if (sum<target){

        if(abs(closest_sum-target)> abs(sum-target)){
         closest_sum=sum;
         }else{
            closest_sum=closest_sum;
         }
         j++;
        }else if (sum==target){

        return sum;
        }
       }
        
       } 
       return closest_sum;
    }
};