// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
        
//         int minlen=INT_MAX;
//         for(int i=0;i<nums.size();i++){
//                int sum=0;
//             for(int j=i;j<nums.size();j++){
//                sum=sum+nums[j];
//                if(sum>=target){
//                 minlen=min(minlen,j-i+1);
//                }
//             }
//         }
//         return (minlen == INT_MAX) ? 0 : minlen;//"Agar minlen abhi bhi INT_MAX hai, iska matlab koi bhi subarray target tak nahi pahunchi. Isliye 0 return kar do."
//     }
// };



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int minlen=INT_MAX;
        int sum=0;
       while(j<nums.size()){
        sum+=nums[j];

        if(sum<target){//invalid
            j++;
        }
        else if(sum>=target){//valid
           while(sum>=target){//jab tak bda hai try to minimize
           //before shrinking
            minlen=min(minlen,j-i+1);//// Update minimum length
            sum-=nums[i];//minus previous sum (window se htado)
            i++;//shift
           }
           j++;
         } 
       }
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};