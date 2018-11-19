class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        se=set([i for i in range(len(nums)+1)])
        se2=set(nums)
        return (se-se2).pop()
        
class Solution2:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        while 1:
            try:
                if nums.pop()!=len(nums)+1:
                    return len(nums)+1
            except:
                return 0        