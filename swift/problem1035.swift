class Solution {
    func maxUncrossedLines(_ A: [Int], _ B: [Int]) -> Int {
        let lengthA = A.count; let lengthB = B.count
        var cache = [[Int]](repeating: [Int](repeating: 0, count: lengthB+1), count: lengthA+1)
        
        for idxA in 0..<lengthA {
            for idxB in 0..<lengthB {
                if (A[idxA] == B[idxB]) {
                    cache[idxA+1][idxB+1] = 1 + cache[idxA][idxB]
                } else {
                    cache[idxA+1][idxB+1] = max(cache[idxA][idxB+1], cache[idxA+1][idxB])
                }
            }
        }
        
        return cache[lengthA][lengthB]
    }
}
