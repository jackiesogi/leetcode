## Two Sum
keywords: `#hashmap`, `#DP`

#### Use **Hash Map** to improve lookup efficiency.
```cpp
/* To store the number and its index in the array. */
std::unordered_map<int, int> umap;
```
when using C, we can also use `int hashmap[]` as hash map (array index as key, array value as value), since we're not dealing with complex type like `string` or `struct`.

#### Be aware of the order of returned indecies.
- The index that already existed in hash map goes first (Previously inserted).
```cpp
if (x.find(complement) != x.end()) {
    return {x[complement], i};
}
```

#### Tips for `std::unordered_map.find()`
- The `umap.find()` method will return the iterator of `std::pair` if result is found, and will return `umap.end()` if result cannot be found.
- `umap.count()` is either 0 or 1, since key is unique in hash map.