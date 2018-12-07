class Solution1 {
    func maxProfit(_ prices: [Int]) -> Int {
        var min = Int.max; var profit = 0
        
        for price in prices {
            if (price < min) {
                min = price
            } else {
                profit = max(profit, price - min)
            }
        }
        
        return profit
    }
}

//sorting the price together with date
class Solution2 {
    func maxProfit(_ prices: [Int]) -> Int {
        let length = prices.count
        let prices = prices.enumerated().sorted{$0.element < $1.element}
        var res = 0; var prev = Int.max
        
        for i in 0..<length {
            var j = length - 1
            if (prices[i].offset > prev) {
                prev = prices[i].offset
                continue
            }
            prev = prices[i].offset
            while (j > i) {
                if (prev < prices[j].offset) {
                    res = max(prices[j].element - prices[i].element, res)
                    break
                }
                j -= 1
            }
        }
        
        return res
    }
}
