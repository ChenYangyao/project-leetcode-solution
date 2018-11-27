# Time Limit Exceeded
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        ma=0

        for i in range(0,len(prices)):
            for k in range(i+1,len(prices)):
                if prices[k]-prices[i]>ma:
                    ma=prices[k]-prices[i]
        return ma


# from solution
class Solution2:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        try:
            mi=prices[0]
            ma=0

            for i in range(0,len(prices)):
                if prices[i]<mi:
                    mi=prices[i]


                elif prices[i]-mi>ma:
                        ma=prices[i]-mi
            return ma
        except:
            return 0      # input:[]  