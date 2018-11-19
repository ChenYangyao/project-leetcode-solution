class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        se=set(nums1)&set(nums2)
        dic={}
        for i in se:
            dic[i]=min(nums1.count(i),nums2.count(i))
        li=[]
        for i in dic:
            for k in range(dic[i]):
                li.append(i)
        return li      
        
# from  https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/195266/Simple-python-solution-beats-99-with-explanation-(not-a-fancy-2-liner)      
class Solution2:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = []
        map = {}
        for x in nums1:
        if x not in map:
            map[x] = 1
        else:
            map[x] += 1

        for y in nums2:
        if y in map:
            res.append(y)
            map[y] -=1
            if map[y] == 0:
                del(map[y])
        return res
        
# from  https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/191763/python-one-line-solve-this-problem       
class Solution3:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
       return list((collections.Counter(nums1) & collections.Counter(nums2)).elements())
        
        
        
       