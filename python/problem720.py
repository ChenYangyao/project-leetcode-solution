class Solution:
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        se=set(words)
        li=[]
        maxl=0
        
        for i in se:
            if len(i)<maxl:
                continue
            
            for k in range(1,len(i)):
                if i[0:k] not in se:
                    break
                
                if k==len(i)-1:
                    if maxl>0 and len(i)>maxl:
                        li.clear()
                    li.append(i)
                    maxl=len(i)
        if li:
            return min(li)
        else:
            return min(se)