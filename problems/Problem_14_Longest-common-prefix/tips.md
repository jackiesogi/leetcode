## Longest Common Prefix

#### The question
- Do the input strings tend to have a longer or shorter common prefix?

#### Approches
1. Reduce the prefix until it matches the beginning of strs[i] -> Compare from the end.
2. Increase the prefix until it does not match -> Compare from the start.
3. Dynamically choose

### Keyword
Narrow down the prefix by one character.