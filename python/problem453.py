class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums)-len(nums)*min(nums)
        
        
# k*(n-1)+sum(nums)=n*min(nums)+k*n  
# n=len(nums)  k is answer
