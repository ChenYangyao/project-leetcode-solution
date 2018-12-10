class Solution:
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        num=1
        maxnum=1
        for i in range(len(nums)-1):
            if nums[i+1]>nums[i]:
                num+=1
            else:
                if num>=maxnum:
                    maxnum=num
                num=1
        return max(maxnum,num)  