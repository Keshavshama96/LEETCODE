class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        

        int i=0;
        int j=arr.size()-1;
        
        while(i<j){
            if(arr[i]+arr[j]>target){
                 j--;
            }
            else if (arr[i]+arr[j]<target){
               i++;
            }
            else if(arr[i]+arr[j]==target){
                 return {i+1,j+1};
            }
        }
        return {0,0};
    }
};