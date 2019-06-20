class Solution {
    func fourSumCount(_ A: [Int], _ B: [Int], _ C: [Int], _ D: [Int]) -> Int {
        var dict = [Int:Int](); var ans = 0
        
        for numberA in A {
            for numberB in B {
                dict[numberA+numberB, default: 0] += 1
            }
        }
        
        for numberC in C {
            for numberD in D {
                if let tmpSum = dict[-numberC-numberD] {
                    ans += tmpSum
                }
            }
        }
        
        return ans
    }
}
