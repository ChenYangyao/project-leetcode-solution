class Solution1 {
    func maxProfit(_ prices: [Int]) -> Int {
        var buy = 0; var profit = 0
        var flag = true //after purchasing stocks, we set flag to false. (true after selling)
        var index = 1
        
        //we only record the last purchasing price
        while (index < prices.count) {
            if flag {
                if (prices[index] > prices[index - 1]) {
                    buy = prices[index - 1]
                    flag = false
                }
            } else {
                if (prices[index] < prices[index - 1]) {
                    profit += (prices[index - 1] - buy)
                    flag = true
                }
            }
            index += 1
        }
        
        //if we purchased at the second to last point, or we purchased at the first point
        //and the price is always increasing, then we haven't sold out it within the while loop
        if !flag {
            profit += (prices.last! - buy)
        }
        return profit
    }
}

//ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/
//approach 3
class Solution2 {
    func maxProfit(_ prices: [Int]) -> Int {
        var profit = 0
        var index = 1
        while (index < prices.count) {
            if (prices[index] > prices[index - 1]) {
                profit += (prices[index] - prices[index - 1])
            }
            index += 1
        }
        return profit
    }
}
