class Solution:
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        binnum = bin(num)[2::]
        return num > 0 and binnum.count('1') == 1 and binnum.count('0')%2 == 0
