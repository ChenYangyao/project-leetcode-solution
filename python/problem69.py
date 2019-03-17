class Solution:
    def mySqrt(self, x: int) -> int:
        if not x:
            return 0
        left = 1
        right = x
        
        while 1:
            k = max((left + right)//2,1)
            
            if  (k+1)*(k+1) == x:
                return k+1
            if k*k <= x and (k+1)*(k+1) >= x:
                return k
            elif k*k > x:
                right = k
            elif (k+1)*(k+1) < x:
                left = k