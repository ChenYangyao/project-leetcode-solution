class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic={}
        ma=0
        for i in nums:
            dic.setdefault(i,0)
            dic[i]+=1
        for i in dic:
            if dic.get(i-1,0) or dic.get(i-1,0):
                if max(dic[i]+dic.get(i-1,0),dic[i]+dic.get(i+1,0))>ma:
                    ma=max(dic[i]+dic.get(i-1,0),dic[i]+dic.get(i+1,0))
                
        return ma