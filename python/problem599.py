class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        d={}
        li=[]
        for i in list1:
            try:

                d[i]=list1.index(i)+list2.index(i)
            except:
                continue
        mi=min(d.values())
        for i in d:
            if d[i]==mi:
                li.append(i)
        return li



# from https://leetcode.com/problems/longest-palindrome/discuss/191708/python-2-lines  
class Solution2:
    def findRestaurant(self, list1, list2):
        d1,d2=({r:i for (i,r) in enumerate(l)} for l in (list1,list2))
        c=set(list1).intersection(list2)  #reduce loop
        m=min(d1[x]+d2[x] for x in c)
        return [x for x in c if m==d1[x]+d2[x]]