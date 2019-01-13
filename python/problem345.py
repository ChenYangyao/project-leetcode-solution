class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        st=list(s)
        se=('a','e','i','o','u','A','E','I','O','U')
        head = 0
        tail = len(s)-1
        while head<tail:
            if st[head] in se:
                if st[tail] in se:
                    st[head],st[tail] = st[tail],st[head]
                    head+=1
                    tail-=1
                    
                else:
                    tail-=1
            else:
                head+=1
        return ''.join(st)
