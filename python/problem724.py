class Solution:
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        wholesum = sum(nums)
        leftsum = 0
        for i in range(len(nums)):
            
            if wholesum - leftsum - nums[i] == leftsum:
                return i
            leftsum+=nums[i]
        return -1
            
