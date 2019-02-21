
#refer https://leetcode.com/problems/string-without-aaa-or-bbb/discuss/235809/Python3-brief-and-simple
class Solution:
    def strWithout3a3b(self, A: 'int', B: 'int') -> 'str':
        li = []
        while A and B:
            if A > B:
                li.append('aab')
                A, B = A - 2, B - 1
            elif B > A:
                li.append('bba')
                A, B = A - 1, B - 2
            else:
                li.append('ab')
                A, B = A - 1, B - 1
        
        if A or B:
            li.append('a' * A)
            li.append('b' * B)
        return ''.join(li)