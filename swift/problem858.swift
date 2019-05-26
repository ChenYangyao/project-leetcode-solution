//ref: https://leetcode.com/problems/mirror-reflection/solution/
//Approach 2
class Solution {
    func mirrorReflection(_ p: Int, _ q: Int) -> Int {
        var m = p; var n = q
        let g = gcd(&m, &n)
        let p = p/g%2; let q = q/g%2
        
        if (p == 1 && q == 1) {
            return 1
        }
        
        return p == 1 ? 0 : 2
    }

    private func gcd(_ m: inout Int, _ n: inout Int) -> Int {
        var remainder = 1
        
        while (remainder != 0) {
            remainder = m % n
            m = n
            n = remainder
        }
        
        return m
    }
}
