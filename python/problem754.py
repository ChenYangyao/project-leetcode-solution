# from solution
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        sumn = 0
        n = 0
        while sumn < target:
            n += 1
            sumn += n
        
        k = sumn - target
        if k%2 == 0 :
            return n  
        elif (k + n + 1) % 2 ==0:
                return n+1
        else:
            return n+2
        