
#refer https://leetcode.com/problems/string-compression/discuss/192233/Python-solution-with-2-pointers-beats-99.7
class Solution:
    def compress(self, chars: 'List[str]') -> 'int':
        num=0
        j=0
        while j<len(chars):
            cnt=1
            k =j+1
            while k<len(chars) and chars[j] == chars[k]:
                cnt+=1
                k+=1
            chars[num] = chars[j]
            num+=1
            if cnt>1:
                for i in str(cnt):
                    chars[num]=i
                    num+=1
            j = k
        return num
            