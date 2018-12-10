class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        l1=[]
        l2=[]
        for i in S:
            try:
                if i =='#':
                    l1.pop()
                    continue
            except:
                continue
            l1.append(i)
        for i in T:
            try:
                if i =='#':
                    l2.pop()
                    continue
            except:
                continue
            l2.append(i)
        return l1==l2