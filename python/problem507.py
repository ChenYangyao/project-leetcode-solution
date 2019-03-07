import math
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        n = int(math.sqrt(abs(num))) + 1
        li = [1]
        for i in range(2,n):
            
            if num%i == 0:
                li.append(num//i)
                li.append(i)
        
        return num == sum(li)


import math
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 1:
            return False
        n = int(math.sqrt(num)) + 1
        li = 1
        for i in range(2,n):
            
            if num%i == 0:
                li += i + num//i
        return num == li
              