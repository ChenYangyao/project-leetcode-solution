import Dispatch

public func cross_prod(_ p1: [Int], _ p2: [Int], _ p3: [Int]) -> Int {
    return (p2[0]*p3[1]-p2[0]*p1[1]-p1[0]*p3[1]-p2[1]*p3[0]+p2[1]*p1[0]+p1[1]*p3[0])
}

//Andrew's monotone chain convex hull algorithm (ref: https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain with bug fixed)
public func monotone(_ points: [[Int]]) -> [[Int]] {
    if (points.count < 3) {
        return points
    }
    let points = points.sorted{p1, p2 in p1[0] < p2[0] || p1[0] == p2[0] && p1[1] < p2[1]}
    var upper = [[Int]]()
    var lower = [[Int]]()
    
    for point in points {
        while (upper.count >= 2) {
            if (cross_prod(upper[upper.count-2],upper[upper.count-1],point) < 0) {
                break
            } else {
                upper.removeLast()
            }
        }
        upper.append(point)
    }
    
    for point in points.reversed() {
        while (lower.count >= 2) {
            if (cross_prod(lower[lower.count-2],lower[lower.count-1],point) < 0) {
                break
            } else {
                lower.removeLast()
            }
        }
        lower.append(point)
    }
    
    upper.removeLast()
    lower.removeLast()
    
    return (upper+lower)
}

class Solution1 {
    func largestTriangleArea(_ points: [[Int]]) -> Double {
        let length = points.count
        if (length < 3) {
            return 0.0
        }
        
        var maxArea = 0
        
        for p1 in 0..<(length-2) {
            for p2 in (p1+1)..<(length-1) {
                for p3 in (p2+1)..<length {
                    maxArea = max(maxArea,abs(cross_prod(points[p1],points[p2],points[p3])))
                }
            }
        }
        return Double(maxArea)/2.0
    }
}

class Solution2 {
    func largestTriangleArea(_ points: [[Int]]) -> Double {
        let points = monotone(points)
        let length = points.count
        if (length < 3) {
            return 0.0
        }
        
        var maxArea = 0
        
        for p1 in 0..<(length-2) {
            for p2 in (p1+1)..<(length-1) {
                for p3 in (p2+1)..<length {
                    maxArea = max(maxArea,abs(cross_prod(points[p1],points[p2],points[p3])))
                }
            }
        }
        return Double(maxArea)/2.0
    }
}

protocol sol {
    func largestTriangleArea(_ points: [[Int]]) -> Double
}
extension Solution1: sol{}
extension Solution2: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.largestTriangleArea(all_points)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

var all_points = Array(repeating: [0,0], count: 1000)

for i in 0..<1000 {
    for j in 0...1 {
        all_points[i][j] = Int.random(in: -10000...10000)
    }
}

time_consuming(Solution1(),"brute force",10)
time_consuming(Solution2(),"monotone",10)
