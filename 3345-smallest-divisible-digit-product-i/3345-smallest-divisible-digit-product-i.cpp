class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {
            int copy = n;
            int product = 1;

            while (copy>0) {
                int lastDigit = copy%10;
                product*= lastDigit;
                copy/= 10;
            }

            if (product%t == 0) {
                return n;
            }

            n++;
        }
    }
};