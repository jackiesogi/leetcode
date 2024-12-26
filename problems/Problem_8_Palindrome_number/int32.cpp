class Solution {
public:
    bool isPalindrome(int x) {
        // 負數和最後一位是 0 的數字（但不包括 0 本身）不可能是回文
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        /* 這個停止條件是關鍵! */
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10; // 反轉後半部分
            x /= 10; // 移除數字的最後一位
        }

        // 當數字位數是奇數時，reversedHalf 會多一位數字，去掉即可
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

