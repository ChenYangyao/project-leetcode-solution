class Solution(object):
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        sumxy = 0
        xi = 1
        
        li = set()
        while xi < bound:
            
            yi = 1
            while 1:
                
                sumxy = xi + yi
                if sumxy <= bound:
                    li.add(sumxy)
                else:
                    break
                if y == 1:
                    break
                else:
                    yi *= y
            if x == 1:
                break
            else:
                xi *= x
        return list(li)
