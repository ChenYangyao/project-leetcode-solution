class Solution {
    func trailingZeroes(_ n: Int) -> Int {
        if (n < 1) {
            return 0
        }
        
        var n = n; var ans = 0
        
        while (n != 0) {
            ans += n/5
            n /= 5
        }
        
        return ans
    }
}
