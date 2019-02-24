
# Time Limit Exceeded
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        def comparestr(r,t):
            return sorted(r) == sorted(t)
        li =[]
        l = len(p)
        for i in range(0,len(s)-l+1):
            if comparestr(s[i:i+l],p):
                li.append(i)
        return li
        
# https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/242617/Two-Lines-of-Code-only-%3A)-in-Python
# also late        
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        pFreq = collections.Counter(p); 
        return [ i for i in range( 0 , len(s)-len(p)+1 ) if collections.Counter( s[i : i + len(p) ] ) == pFreq ]
        
 # https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/222640/Python%3A-Simple-Window-Slider-Beat-96-O(N)       
class Solution:
	def findAnagrams(self, s, p):
		"""
		:type s: str
		:type p: str
		:rtype: List[int]
		"""
		if len(s) < len(p):
			return []

		alphabets = 'abcdefghijklmnopqrstuvwxyz'
		map_a = {c:0 for c in alphabets}
		map_p = {c:0 for c in alphabets}

		res = []

		for i, c in enumerate(p):
			map_p[c] += 1

			if i < len(p) -1:
				map_a[s[i]] += 1

		lead = len(p) - 1
		lag = 0

		while lead < len(s):
			map_a[s[lead]]+=1

			if map_a == map_p:
				res.append(lag)

			map_a[s[lag]] -= 1

			lead+=1
			lag+=1

		return res