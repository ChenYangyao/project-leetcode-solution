class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target <= nums[0]:
                return 0
        if target == nums[-1]:
            return len(nums)-1
        if target > nums[-1]:
                return len(nums)
        if len(nums)<3:
            if target > nums[0] and target < nums[-1]:
                return 1
        
        l = 0
        r = len(nums)-1
        while l<r:
            mid = (l+r)//2
            
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                if nums[mid+1] > target:
                    return mid+1
                l =mid
            if nums[mid] > target:
                if nums[mid-1] < target:
                    return mid
                r = mid
    