class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
          
        if len(num1)<len(num2):
            num1,num2=num2,num1
        num2='0'*(len(num1)-len(num2))+num2
        
        r=''
        m='0'
        l=len(num1)
        for i in range(l):
            k=l-1-i
            
            j = ord(num1[k])-ord('0') + ord(num2[k])-ord('0') + ord(m)-ord('0')
            
            m='0'
            if j>=10:
                j-=10
                m='1'
            r+=chr(j+ord('0'))
        if m=='1':
            r+=m   
        return r[::-1]
        