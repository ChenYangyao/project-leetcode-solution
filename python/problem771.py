# Library needed by solutions shoube be imported by hand.
# Although these are automatically imported in Leetcode.
import time


class Solution:
    """Solution by linear search.
    Description:
     - linearly search the stone in jewels sequential list.
     - time complexity Theta(len(J)*len(S)).
     - space complexity Theta(1).
    Creat: Yangyao, date 20181003
    References: none. (always put the references here, e.g. leetcode official solution, leetcode user's solution)
    Modify: Yangyao, date 20181003
     - add some notes.
    """
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        count = 0
        for s in S:
            if self.isJewel(J,s): count += 1
        return count
    def isJewel(self, J, s):
        """Determine if a stone is jewel.
        :type J: str - sequential list of jewels.
        :type S: str with single character - stone to be judged.
        :rtype: bool - true if it is jewel, false if else.
        """
        return True if s in J else False


class Solution2:
    """Solution by hash table
    Description:
     - use unordered set to speed up searching.
     - time complexity is reduced to Theta(len(S))
     - extra space Theta(len(J))
    Creat: Yangyao, date 20181003
    Reference: none.
    """
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        count = 0
        set_J = set(J)
        for s in S:
            if s in set_J: count += 1
        return count



# Driver calls to test solutions
J = "aAbcefoOpPsSdD"
S = "aAAbbbbsdfgrtyytuyiuiusdfsdfhfhfhhbsdfjsjfuaewyf";
sol = Solution()
sol2 = Solution2()
repeat = 1000000

# test the time for linear searching
total = 0
t1 = time.clock()
for i in range(repeat):
    total += sol.numJewelsInStones(J,S)
t2 = time.clock()
print( "total stone", total )
print( "time by linear searching ", t2-t1 )

# test the time for hash searching
total = 0
t1 = time.clock()
for i in range(repeat):
    total += sol2.numJewelsInStones(J,S)
t2 = time.clock()
print( "total stone", total )
print( "time by hash searching ", t2-t1 )
