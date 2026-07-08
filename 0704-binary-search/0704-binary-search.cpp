class Solution {
public:
    int search(vector<int>& nums, int target) {
        int strt=0;
        int end=nums.size()-1;
         int mid;
        while(strt<=end){
            mid=strt-(strt-end)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end=mid-1;
            else strt=mid+1;
        }
        return -1;
    }
};