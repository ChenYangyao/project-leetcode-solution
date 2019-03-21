public class Interval {
  public var start: Int
  public var end: Int
  public init(_ start: Int, _ end: Int) {
    self.start = start
    self.end = end
  }
}

class Solution1 {
    func intervalIntersection(_ A: [Interval], _ B: [Interval]) -> [Interval] {
        var A = A; var B = B
        var ans = [Interval]()
        var idxA = 0; var idxB = 0
        
        while idxA < A.count {
            while (idxB < B.count && A[idxA].end >= B[idxB].end) {
                let Astart = A[idxA].start
                let Bend = B[idxB].end
                if (Astart <= Bend) {
                    ans.append(Interval(max(Astart,B[idxB].start),Bend))
                }
                idxB += 1
            }
            swap(&A,&B)
            swap(&idxA,&idxB)
        }
        
        return ans
    }
}

//ref: https://leetcode.com/problems/interval-list-intersections/solution/
class Solution2 {
    func intervalIntersection(_ A: [Interval], _ B: [Interval]) -> [Interval] {
        var ans = [Interval]()
        var idxA = 0; var idxB = 0
        let lengthA = A.count; let lengthB = B.count
        
        while (idxA < lengthA && idxB < lengthB) {
            let left = max(A[idxA].start,B[idxB].start)
            let right = min(A[idxA].end,B[idxB].end)
            
            if (left <= right) {
                ans.append(Interval(left,right))
            }
            
            if (A[idxA].end < B[idxB].end) {
                idxA += 1
            } else {
                idxB += 1
            }
        }
        
        return ans
    }
}
