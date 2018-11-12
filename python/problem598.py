class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        if not ops:
            return n*m
        minx=ops[0][0]
        miny=ops[0][1]
        for i in ops:
            if i[0]<minx:
                minx=i[0]
            if i[1]<miny:
                miny=i[1]
        return minx*miny