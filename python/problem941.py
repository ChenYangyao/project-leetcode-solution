class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        k = 0
        if not A or len(A) == 1:
            return False
        if A[0] > A[1]:
            return False
        for i in range(1,len(A)-1):
            if A[i] > A[i+1]:
                k = i+1
                break
                
        for i in range(k,len(A)-1):
            if A[i] <= A[i+1]:
                return False
            
        return True
        