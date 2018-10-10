class Solution {
    func fairCandySwap(_ A: [Int], _ B: [Int]) -> [Int] {
        let B_set = Set(B)
        let A_sum = A.reduce(0,+)
        let B_sum = B.reduce(0,+)
        let diff = (A_sum-B_sum)/2
        
        for bar in A {
            if (B_set.contains(bar-diff)) {
                return [bar,bar-diff]
            }
        }
        
        return [0]
    }
}
