'''
2799. Count Complete Subarrays in an Array (Medium)

You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.


Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

'''

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        right = 0
        distinct = len(set(nums))
        count = {}
        for left in range(n):
            if left > 0:
                remove = nums[left - 1]
                count[remove] -= 1
                if count[remove] == 0:
                    count.pop(remove)
            while right < n and len(count) < distinct:
                add = nums[right]
                count[add] = count.get(add, 0) + 1
                right += 1
            if len(count) == distinct:
                res += n - right + 10
        return res

