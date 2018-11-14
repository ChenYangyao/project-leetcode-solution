class Solution:
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        s=sorted(nums,reverse=True)
        dic={}
        for i in range(0,len(s)):
                if i==0:
                    dic[s[i]]="Gold Medal"
                    continue
                if i==1:
                    dic[s[i]]="Silver Medal" 
                    continue
                if i==2:
                    dic[s[i]]="Bronze Medal"
                    continue
                else:
                    dic[s[i]]=str(i+1)
        for i in range(len(nums)):
            s[i]=dic[nums[i]]
        return s

# from https://leetcode.com/problems/relative-ranks/discuss/98472/Python-solution    
def findRelativeRanks(self, nums):
    sort = sorted(nums)[::-1]
    rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + map(str, range(4, len(nums) + 1))
    return map(dict(zip(sort, rank)).get, nums)    