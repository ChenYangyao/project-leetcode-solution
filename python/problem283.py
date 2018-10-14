import time
class Test:
    def test(self,s,repeat):
        t1=time.time()
        for i in range(repeat):
            s.moveZeroes(nums)
            
        t2=time.time()
        print('time=',t2-t1)

class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        count=nums.count(0)
        for i in range(count):
            nums.remove(0)
            nums.append(0)
                
# from discuss                
class Solution2:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zeros = 0
        count = 0
        for i in nums:
            if i == 0:
                zeros+=1
        
        for i in range(len(nums)):
            if nums[i] == 0:
                count += 1
                continue
            nums[i-count] = nums[i]
        
        for i in range(len(nums)-count,len(nums)):
            nums[i] = 0


                  
                
                
if __name__ == '__main__':
    nums=[1,112,25,5,15,0,0,54165,0,123,0,456,0,156,13215]
    #for i in range():
    s=Solution()
    s1=Solution2()
    t=Test()
    t.test(s,100000)
    t.test(s1,100000)