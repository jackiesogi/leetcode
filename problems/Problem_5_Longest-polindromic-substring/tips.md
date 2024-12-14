## Longest polindromic substring

### Check Palindrome
To check if a string is palindrome, we can use either of the following methods:
1. **Reverse and Compare**: Reverse the string and compare it with the original string.
2. **Two Pointers**: Use two pointers, one from the start and one from the end, and compare the characters at both pointers.
    - **Brute Force O(n^3)**: Using two loops to generate all possible substrings and check if they are palindrome.
    - **Expand around center O(n^2)**: Using a single loop to generate all possible centers of palindrome and check if they are palindrome.

### C++ Lambda Function
We can take advantage of lambda functions in C++ to create a function that checks if a string is palindrome.
```cpp
auto isPalindrome = [](string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
};
```
