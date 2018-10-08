import time
class Test:
    def test(self,s,repeat):
        t1=time.time()
        for i in range(repeat):
            s.toGoatLatin(k)
        t2=time.time()
        print('time=',t2-t1)

        

class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        li=S.split(' ')
        k=set('aeiouAEIOU')
        for i in range(len(li)):
            l=i+1
            m=li[i][0]
            if m in k:
                li[i]+='ma'+'a'*l
            else:
                first=li[i][0]
                li[i]=li[i][1:]+first+'ma'+'a'*l
        return ' '.join(li)
class Solution2: 
    def toGoatLatin(self, S):
        vowel = "a,e,i,o,u,A,E,I,O,U"
        out = []
        arr = S.split(' ')
        for i,word in enumerate(arr):
            if word[:1] in vowel:
                word = word + "ma"
            else:
                word = word[1:] + word[:1] + "ma"
            word += (i+1)*"a"
            out.append(word)
        return " ".join(out)               

if __name__ == '__main__':
    k="The quick brown fox jumped over the lazy dog"
    t=Test()
    s=Solution()
    s1=Solution2()
    t.test(s,10000)
    t.test(s1,10000)