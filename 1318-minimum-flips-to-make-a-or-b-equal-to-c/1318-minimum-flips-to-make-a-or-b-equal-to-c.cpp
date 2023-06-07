class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;

        while (a > 0 || b > 0 || c > 0) {
            int a_bit = a & 1;
            int b_bit = b & 1;
            int c_bit = c & 1;

            if (c_bit == 0) {
                if (a_bit == 1) {
                    count++; // Flip the bit in 'a'
                }
                if (b_bit == 1) {
                    count++; // Flip the bit in 'b'
                }
            } else {
                if (a_bit == 0 && b_bit == 0) {
                    count++; // Flip either 'a' or 'b' to 1
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return count;
    }
};
