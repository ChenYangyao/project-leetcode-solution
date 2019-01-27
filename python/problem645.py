class Solution:
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        se1=set(nums)
        n = len(nums)+1
        se = set(i for i in range(1,n))
        l = list(se-se1)[0]
        for i in range(n-1):
            if nums[i] == nums[i+1]:
                k=nums[i]
                break
        return [k,l]

# from https://leetcode.com/problems/set-mismatch/discuss/105558/Oneliner-Python
def findErrorNums(self, nums):
    return [sum(nums) - sum(set(nums)), sum(range(1, len(nums)+1)) - sum(set(nums))]
