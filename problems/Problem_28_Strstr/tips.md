## Find the index of the first occurence in the string
Basically, it is a `strstr()` implementation.

#### Approaches
- Naive method: using sliding window and compare the char one by one.
- Knuth–Morris–Pratt algorithm: build a LPS(Longest Prefix Suffix) table to avoid comparing the same chars. 