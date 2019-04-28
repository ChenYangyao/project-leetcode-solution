//ref: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/278251/JavaC%2B%2BPython-O(N)Time-O(1)-Space
class Solution {
    func maxSumTwoNoOverlap(_ A: [Int], _ L: Int, _ M: Int) -> Int {
        var A = A
        for idx in 1..<A.count {
            A[idx] += A[idx-1]
        }
        
        var ans = A[L+M-1]; var Lmax = A[L-1]; var Mmax = A[M-1]
        
        for idx in (L+M)..<A.count {
            Lmax = max(Lmax, A[idx-M] - A[idx-L-M])
            Mmax = max(Mmax, A[idx-L] - A[idx-L-M])
            ans = max(ans, max(Lmax + A[idx] - A[idx-M], Mmax + A[idx] - A[idx-L]))
        }
        
        return ans
    }
}
