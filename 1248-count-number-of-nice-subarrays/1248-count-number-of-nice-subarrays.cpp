class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int prev = 0;      // Current window ke liye kitne valid starting points hain
        int oddCount = 0;  // Window ke andar total odd numbers
        int res = 0;       // Final answer

        int i = 0;         // Left pointer
        int j = 0;         // Right pointer

        while (j < nums.size()) {

            // Agar current element odd hai to odd count badhao
            // Aur prev reset karo kyunki naye odd ke baad valid starts dobara calculate honge
            if (nums[j] % 2 != 0) {
                oddCount++;
                prev = 0;
            }

            // Jab window me exactly k odd aa jaye
            // Tab jitne valid left pointers milte hain unhe count karo
            while (oddCount == k) {

                prev++;   // Ek aur valid starting point mil gaya

                // Agar left wala odd tha to odd count kam ho jayega
                if (nums[i] % 2 != 0) {
                    oddCount--;
                }

                // Window ko shrink karo
                i++;
            }

            // Current right pointer ke liye jitne valid starts hain
            // Unhe answer me add kar do
            res += prev;

            // Right pointer aage badhao
            j++;
        }

        return res;
    }
};