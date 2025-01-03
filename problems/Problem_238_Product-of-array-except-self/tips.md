## Product of array except self

#### Approach 1: Bruteforce
Use nested loops to calculate the product of all elements except the current element.
Time complexity is O(n^2).

#### Approach 2: Prefix and Suffix products
Calculate the prefix and suffix products of the array.
And the answer is the product of prefix(left) and suffix(right) products.
