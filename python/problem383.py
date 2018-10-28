class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        s=set(ransomNote)
        for i in s:
            if ransomNote.count(i)>magazine.count(i):
                return False
        return True
        