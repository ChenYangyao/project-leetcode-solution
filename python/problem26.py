class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        try:
            while 1:
                if nums[i] == nums[i+1]:
                    del nums[i+1]
                else:
                    i+=1
                
        except:
            
            return len(nums)
