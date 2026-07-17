class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;  // आखिरी index जहाँ से merge करना है
        int i = m - 1;        // nums1 का आखिरी valid element
        int j = n - 1;        // nums2 का आखिरी element

        // जब तक दोनों arrays में elements बचे हैं
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
            // अगर nums1 का element बड़ा है तो उसे पीछे डालो
                nums1[idx--] = nums1[i--];
            } else {
                // वरना nums2 का element डालो
                nums1[idx--] = nums2[j--];
            }
        }
 // अगर nums2 में अभी भी elements बचे हैं (nums1 के पहले ही सारे डाल दिए गए)
        while (j >= 0) {
            nums1[idx--] = nums2[j--];  // बचा हुआ nums2 डाल दो
        }

// अगर nums1 के बचे हैं तो उन्हें वैसे ही छोड़ दो क्योंकि वो पहले से सही जगह हैं
    }
};
