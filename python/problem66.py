class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        x=''.join(str(i) for i in digits)
        k=int(x)+1
        li=[]
        for i in str(k):
            li.append(int(i))
        return li
