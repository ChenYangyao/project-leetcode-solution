class Solution {
    func arrangeCoins(_ n: Int) -> Int {
        return Int(((Double(n)*8+1).squareRoot()-1)/2)
    }
}
