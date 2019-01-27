import math
class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        num = 0
        firstmax = 0
        for i in range(len(seats)):
            if seats[i] == 0:
                firstmax+=1
            if seats[i] == 1:
                num = i
                break
            
        max_dis = 0
        tempmax = 0
        for i in range(num,len(seats)):
            
            if seats[i] == 0:
                tempmax+=1
            if seats[i] == 1:
                if math.ceil(tempmax/2) > max_dis:
                    max_dis = math.ceil(tempmax/2)
                tempmax=0
        
        return max(max_dis,tempmax,firstmax)
