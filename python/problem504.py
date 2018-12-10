class Solution:
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        
        k=abs(num)
        li=[]
        while k>=7:
            li.append(str(k%7))
            k=k//7
        li.append(str(k%7))
        if num>=0:  # '-0'
            return ''.join(li[::-1])
        else:
            return '-'+''.join(li[::-1])