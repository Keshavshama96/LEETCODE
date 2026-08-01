class Solution {
public:
    int t[23][23];

    // Returns (Player1 Score - Player2 Score)
    int maxDiff(vector<int>& nums, int l, int r) {

        if (l == r)
            return nums[l];

        if (t[l][r] != -1)
            return t[l][r];

        int takeLeft = nums[l] - maxDiff(nums, l + 1, r);
        int takeRight = nums[r] - maxDiff(nums, l, r - 1);

        return t[l][r] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return maxDiff(nums, 0, nums.size() - 1) >= 0;
    }
};