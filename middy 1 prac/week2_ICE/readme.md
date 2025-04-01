### Programming Practice: Implement Function

```cpp
void ECRemoveSpace(int nums[], int len, int val)
```

- **Goal**: Remove all occurrences of `val` in the `nums` array, in-place. The relative order of elements can change.
- **Return**: The value `k`, indicating the first `k` slots of `nums` containing the final result.

#### Example 1

```plaintext
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should print k = 2, with the first two elements of nums being 2. 
```

#### Example 2

```plaintext
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should print k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4. 
```

#### Note
- The function should not allocate extra space for another array and should modify the input array in-place with O(1) extra memory.
