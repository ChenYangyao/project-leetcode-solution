class Solution:
    def addBinary(self, a: 'str', b: 'str') -> 'str':
        def strtobin(i):
            sum = 0
            for k in range(len(i)-1,-1,-1):
                sum = sum + int(i[k]) * 2**(len(i)-k-1)
            return sum
        
        return str(bin(strtobin(a) +strtobin(b)))[2::]
                