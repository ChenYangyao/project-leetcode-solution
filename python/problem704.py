class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target<nums[0] or target > nums[-1]:
            return -1
        if target==nums[0] :
            return 0
        if target == nums[-1]:
            return len(nums)-1
        l=0
        r=len(nums)-1
        while l<(l+r)//2:
            mid=(l+r)//2
            if target> nums[mid]:
                l=mid
            if target < nums[mid]:
                r=mid
            if target == nums[mid]:
                return mid
        return -1