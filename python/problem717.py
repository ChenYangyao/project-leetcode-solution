#from solution
class Solution:
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        k=0
        while k <len(bits)-1:
            k+=bits[k]+1
        return k==len(bits)-1
