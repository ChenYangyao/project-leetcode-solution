# from solution
class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        nu=0
        for j in range(0, len(nums)):
            if nums[j]!=val:
                nums[nu]=nums[j]
                nu+=1
        return nu
