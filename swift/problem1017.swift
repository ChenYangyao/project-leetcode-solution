//ref: https://leetcode.com/problems/convert-to-base-2/discuss/265507/JavaC%2B%2BPython-2-lines-Exactly-Same-as-Base-2
class Solution {
    func baseNeg2(_ N: Int) -> String {
        if (N == 0) {
            return "0"
        }
        
        var N = N; var ans = String()
        
        while (N != 0) {
            ans = String(N&1) + ans
            N = -(N >> 1)
        }
        
        return ans
    }
}
