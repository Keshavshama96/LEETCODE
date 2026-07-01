class Solution {
public:

    // This function counts subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal){

        // If goal is negative, no subarray possible
        if(goal < 0) return 0;

        int i = 0;        // left pointer
        int sum = 0;      // current window sum
        int count = 0;    // total subarrays

        // right pointer expands window
        for(int j = 0; j < nums.size(); j++){

            sum += nums[j];   // include current element

            // if sum becomes invalid, shrink window
            while(sum > goal){
                sum -= nums[i];  // remove left element
                i++;              // move left pointer
            }

            // all subarrays ending at j and starting from i to j are valid
            count += (j - i + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Idea:
        // exact = atMost(goal) - atMost(goal - 1)

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};