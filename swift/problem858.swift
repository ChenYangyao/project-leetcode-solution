//ref: https://leetcode.com/problems/mirror-reflection/discuss/146336/Java-solution-with-an-easy-to-understand-explanation
//Approach 2
class Solution {
    func mirrorReflection(_ p: Int, _ q: Int) -> Int {
        var m = p; var n = q
        gcd(&m, &n)
        let p = p/m%2; let q = q/m%2
        
        if (p == 1 && q == 1) {
            return 1
        }
        
        return p == 1 ? 0 : 2
    }
    
    //after calculation, gcd is m
    private func gcd(_ m: inout Int, _ n: inout Int) {
        var remainder = 1
        
        while (remainder != 0) {
            remainder = m % n
            m = n
            n = remainder
        }
    }
}
