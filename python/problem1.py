class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        se = set(nums)
        for i in se:
            if target - i in se:
                if target - i == i:
                    k = nums.index(i)
                    return [k,nums.index(i,k+1)]
                else:
                    return [nums.index(i),nums.index(target-i)]
