'''
2444. Count Subarrays With Fixed Bounds (Hard)

You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

'''

class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        start, mini, maxi = -1, -1, -1
        count = 0
        for i, nums in enumerate(nums):
            if nums > maxK or nums < minK:
                start = i
            if maxK == nums:
                maxi = i
            if nums == minK:
                mini = i
            valid = max(0, min(mini, maxi) - start)
            count += valid
        return count

