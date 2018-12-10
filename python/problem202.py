class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        
        se=set()
        while True:
            k=0
            for i in str(n):
                k+=int(i)**2
            n=k
            if k in se:
                return False
            if k==1:
                return True
            else:
                se.add(k)