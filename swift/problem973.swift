class Solution1 {
    func kClosest(_ points: [[Int]], _ K: Int) -> [[Int]] {
        let squareDis = {(x: Int, y: Int) in x*x + y*y}
        let points = points.sorted{squareDis($0[0],$0[1]) < squareDis($1[0],$1[1])}
        
        return Array(points[0..<K])
    }
}

//ref: https://leetcode.com/problems/k-closest-points-to-origin/discuss/220326/Python3-Solution-using-QuickSelect-O(NlogN)
class Solution2 {
    private var points = [[Int]]()
    private var K = 0
    
    func kClosest(_ points: [[Int]], _ K: Int) -> [[Int]] {
        self.points = points; self.K = K
        quickSelect(0, points.count - 1)
        return Array(self.points[0..<K])
    }
    
    private func squareDis(_ index: Int) -> Int {
        return {x, y in x*x + y*y}(points[index][0], points[index][1])
    }
    
    private func quickSelect(_ i: Int, _ j: Int) {
        if (i < j) {
            let pivot = partition(i, j)
            var left = i; var right = j - 1
            while (left < right) {
                left += 1
                while (squareDis(left) < pivot) {
                    left += 1
                }
                right -= 1
                while (squareDis(right) > pivot) {
                    right -= 1
                }
                if (left < right) {
                    points.swapAt(left, right)
                }
            }
            
            points.swapAt(left, j - 1)
            
            if (K <= left) {
                quickSelect(i, left - 1)
            } else if (K > left + 1) {
                quickSelect(left + 1, j)
            }
        }
    }
    
    private func partition(_ i: Int, _ j: Int) -> Int {
        let centre = (i + j)/2
        if (squareDis(i) > squareDis(centre)) {
            points.swapAt(i, centre)
        }
        if (squareDis(i) > squareDis(j)) {
            points.swapAt(i, j)
        }
        if (squareDis(centre) > squareDis(j)) {
            points.swapAt(centre, j)
        }
        
        points.swapAt(centre, j - 1)
        
        return squareDis(j - 1)
    }
}
