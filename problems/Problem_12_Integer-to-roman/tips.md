## Integer to Roman

| Symbol | Value |
|--------|-------|
|    I   |   1   |
|    V   |   5   |
|    X   |  10   |
|    L   |  50   |
|    C   |  100  |
|    D   |  500  |
|    M   | 1000  |

Exceptions are : 4(IV), 9(IX), 40(XL), 90(XC), 400(CD), 900(CM)

To achieve this conversion, we need to construct a table to match the relationships.
And since the exception should go first, i.e. 40 is "XL" not "XXXX", we need to have 40's division priority higher than 10's division.

Since size is known, we can also use `std::array` instead.
```cpp
vector<pair<int, string>> v = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};
```

