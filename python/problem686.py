class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        s = A
        k = 1
        if len(s) >= len(B):
            while k<4:   
                if B in s:
                    return k
                s += A
                k += 1
            return -1
                
                
        while len(s) < len(B):
            s += A
            k += 1
        m = k
        while m < 2*k:
            if B in s:
                return m
            s += A
            m += 1
            
        return -1