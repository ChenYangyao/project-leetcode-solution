class Solution:
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxnum = 0
        pivot = 0
        secondmax = 0
        for i in range(len(nums)):
            if nums[i] > maxnum:
                secondmax = maxnum
                maxnum = nums[i]
                pivot = i
                continue
            if nums[i] > secondmax:
                secondmax = nums[i]
        if maxnum>=2*secondmax:
            return pivot
        return -1
