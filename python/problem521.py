class Solution(object):
    def findLUSlength(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        if (not a and b)or (not b and a):
            return max(len(a),len(b))
        if a==b:
            return -1
        a1=[]
        b1=[]
        count=[]
        for i in range(len(a)):
            for k in range(i+1,len(a)+1):
                a1.append(a[i:k])
        for i in range(len(b)):
            for k in range(i+1,len(b)+1):
                b1.append(b[i:k])
        for i in range(len(a1)):
            if a1[i] not in b:
                count.append(len(a1[i]))
        for i in range(len(b1)):
            if b1[i] not in a:
                count.append(len(b1[i]))
        return max(count)
        
        
        
        
        
# from discuss
'''
def findLUSlength(self, a, b):
    """
    :type a: str
    :type b: str
    :rtype: int
    """
    if a == b:
        return -1
    else:
        return max(len(a), len(b))
'''
