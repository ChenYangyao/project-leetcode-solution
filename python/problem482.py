class Solution:
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        S=S.split('-')
        S=''.join(S).upper()[::-1]
        S='-'.join(S[i:i+K] for i in range(0, len(S), K))[::-1]
        return S
