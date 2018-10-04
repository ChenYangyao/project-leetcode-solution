class Solution(object):
    def countPrimeSetBits(self, L, R):
        """
        :type L: int
        :type R: int
        :rtype: int
        """
        count=0
        li=[2,3,5,7,11,13,17,19]
        for i in xrange(L,R+1):
            n=str(bin(i)[2:])
            m=n.count('1')
            if m in li:
                count+=1
        return count