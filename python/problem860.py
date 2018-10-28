class Solution:
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        dic={5:0,10:0,20:0}
        for i in bills:
            dic[i]+=1
            if i ==10:
                dic[5]-=1
                if dic[5] <0:
                    return False
            if i ==20:
                if (dic[5]-1<0 or dic[10]-1<0):
                    if dic[5]-3 <0:
                        return False
                    else:
                        dic[5]-=3
                else:
                    dic[5]-=1 
                    dic[10]-=1
        return True
                    