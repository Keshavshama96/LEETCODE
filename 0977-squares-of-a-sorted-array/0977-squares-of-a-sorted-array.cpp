class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int i=0;
        int j=nums.size()-1;
        int n=nums.size();
        vector<int>res(n);
        int pos=n-1;
        while(i<=j){

            if(nums[i]*nums[i]>nums[j]*nums[j]){
                res[pos]=nums[i]*nums[i];
                i++;
            }else{
               res[pos]=nums[j]*nums[j];
                j--;
            }
            pos--;
        }
        return res;
    }
   
};
