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

// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
        
//         int i=0;
//         int j=0;
//         int maxlen=0;
//         while(j<nums.size()){
//             if(nums[j]==1){
//              maxlen=max(maxlen,j-i+1);
//              j++;
//             } 
//             else {
//                 j++;
//                 i=j;
//             }
//         }
//         return maxlen ;
//     }
// };