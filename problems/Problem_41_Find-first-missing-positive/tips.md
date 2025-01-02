## First missing positive

#### Approaches

- One loop for iterate through elements and insert them into hash table; Another loop for checking the existence from 1 to INT_MAX in that hash table.

- One loop for iterate through elements and swap them into the right position(if it's in the range), for example, if we meet 32 in the array, try to swap it to the nums[31] position (after swapping: [0]: 1, [1]:2, ... [31]: 32). And second loop we need to check the first number that does not meet this rule.