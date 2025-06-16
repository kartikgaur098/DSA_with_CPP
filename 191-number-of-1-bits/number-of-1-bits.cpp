class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1;  // check last bit
            n >>= 1;         // right shift
        }
        return count;
    }
};
