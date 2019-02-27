class Solution {
    private let upperBound = [9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889]
    private let res = [0, 9, 108, 1107, 11106, 111105, 1111104, 11111103, 111111102]
    
    func findNthDigit(_ n: Int) -> Int {
        let power = upperBound.firstIndex(where: {$0 > n})!
        var lowerBound = (n + res[power])/(power + 1)
        var left = n - lowerBound*(power + 1) + res[power]
        
        if (left == 0) {
            return lowerBound%10
        }
        
        lowerBound += 1
        
        for _ in 1...(power+1-left) {
            lowerBound /= 10
        }
        
        return lowerBound%10
    }
}
