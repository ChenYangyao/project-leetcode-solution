
# Time Limit Exceeded
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.li = nums

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        s = 0
        for k in range(i,j+1):
            s+=self.li[k]
        return s

# https://leetcode.com/problems/range-sum-query-immutable/discuss/221224/Python-Prefix-Sum-Array-no-if-statement-beats-98
class NumArray:
    def __init__(self, nums):
        self.prefix = [0]
        for num in nums:
            self.prefix.append(self.prefix[-1] + num)

    def sumRange(self, i, j):
        return self.prefix[j + 1] - self.prefix[i]
        
