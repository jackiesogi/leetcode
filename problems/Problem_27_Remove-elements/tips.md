## Remove Elements

#### Approaches
- Single Pointer
Maintain a pointer called `write_pos`. `write_pos` will increment by one when the meet a value that is not equal to the specified value we're going to remove.

- Double Pointer
Maintain two pointers, `i` and `n` to swap the value to the back. It is efficient when we have small number of values going to remove.