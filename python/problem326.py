class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        m=1
        while m <= n:
            if m == n:
                return True
            m = m * 3
            
            
        return False  