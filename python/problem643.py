
# Time Limit Exceeded
class Solution:
    def findMaxAverage(self, nums: 'List[int]', k: 'int') -> 'float':
        if len(nums) == 1:
            return nums[0]/1
        def av(i,nums,k):
            su = 0
            for n in range(k):
                su+=nums[i+n]
            return su/k
        maav = 0
        temp = 0
        for i in range(len(nums)-k+1):
            temp = av(i,nums,k)
            
            if temp > maav:
                maav = temp
        return maav


class Solution2:
    def findMaxAverage(self, nums: 'List[int]', k: 'int') -> 'float':
        if len(nums) == 1:
            return nums[0]/1

        
        temp = sum(nums[0:k])
        maav = temp
        for i in range(1,len(nums)-k+1):
            
            temp = temp - nums[i-1] +nums[i+k-1]
            maav = max(temp,maav)
        return maav/k
        
