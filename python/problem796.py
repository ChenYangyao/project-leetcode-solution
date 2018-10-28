class Solution:
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if A=='' and B==A:
            return True
        for i in range(len(A)):
            if A[i::]+A[0:i:]==B:
                return True
        return False