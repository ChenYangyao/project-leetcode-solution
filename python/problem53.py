# refer:https://blog.csdn.net/lengxiao1993/article/details/52303492

class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ma=nums[0]
        m=nums[0]
        for i in nums[1::]:
            m=max(i,m+i)
            ma=max(ma,m)
        return ma