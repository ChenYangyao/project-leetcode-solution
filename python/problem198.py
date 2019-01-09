class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums)<3:
            return max(nums)
        li = []
        li.append(nums[0])
        li.append(nums[1])
        li.append(nums[0] + nums[2])
        
        for i in range(3,len(nums)):
            li.append(nums[i]+max(li[i-2],li[i-3]))
        return max(li[-2],li[-1])
        