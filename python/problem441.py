class Solution:
    def arrangeCoins(self, n: 'int') -> 'int':
        k = 1
        while 1:
            
            n -= k
            if n < 0:
                return k-1
            k += 1