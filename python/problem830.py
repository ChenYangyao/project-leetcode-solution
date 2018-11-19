class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        start=0
        li=[]
        end=0
        for i in range(len(S)-1):
            if S[i+1]!=S[i] or i==len(S)-1:
                end=i
                
                if end-start+1>=3:
                    li.append([start,end])   
                start=i+1
            if S[i+1]==S[i] and i+2==len(S):
                end=i+1
                if end-start+1>=3:
                    li.append([start,end])   
                
        return li

        
        
        
class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        start=0
        li=[]
        end=0
        for i in range(len(S)):
            if i==len(S)-1 or S[i+1]!=S[i]: # judgement order
 
                end=i
                print(start,end)
                if end-start+1>=3:
                    li.append([start,end])   
                start=i+1  
                
        return li       