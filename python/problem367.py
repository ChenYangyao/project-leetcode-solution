class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        i=0
        while i*i <=num:
            if i*i == num:
                return True
            i+=1
        return False
