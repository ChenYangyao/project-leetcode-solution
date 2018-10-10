import Foundation

public func cross(_ o: CGPoint, _ a: CGPoint, _ b: CGPoint) -> CGFloat {
    let lhs = (a.x - o.x) * (b.y - o.y)
    let rhs = (a.y - o.y) * (b.x - o.x)
    return lhs - rhs
}

/// Calculate and return the convex hull of a given sequence of points.
///
/// - Remark: Implements Andrew’s monotone chain convex hull algorithm.
///
/// - Complexity: O(*n* log *n*), where *n* is the count of `points`.
///
/// - Parameter points: A sequence of `CGPoint` elements.
///
/// - Returns: An array containing the convex hull of `points`, ordered
///   lexicographically from the smallest coordinates to the largest,
///   turning counterclockwise.
///
public func convexHull(_ points: [CGPoint]) -> [CGPoint] {
    // Exit early if there aren’t enough points to work with.
    guard points.count > 2 else { return points}
    
    // Create storage for the lower and upper hulls.
    var lower = [CGPoint]()
    var upper = [CGPoint]()
    
    // Sort points in lexicographical order.
    let points = points.sorted { a, b in
        a.x < b.x || a.x == b.x && a.y < b.y
    }
    
    // Construct the lower hull.
    for point in points {
        while lower.count >= 2 {
            let a = lower[lower.count - 2]
            let b = lower[lower.count - 1]
            if cross(a, b, point) > 0 { break }
            lower.removeLast()
        }
        lower.append(point)
    }
    
    // Construct the upper hull.
    for point in points.lazy.reversed() {
        while upper.count >= 2 {
            let a = upper[upper.count - 2]
            let b = upper[upper.count - 1]
            if cross(a, b, point) > 0 { break }
            upper.removeLast()
        }
        upper.append(point)
    }
    
    // Remove each array’s last point, as it’s the same as the first point
    // in the opposite array, respectively.
    lower.removeLast()
    upper.removeLast()
    
    // Join the arrays to form the convex hull.
    return lower + upper
}

let all_points = [CGPoint(x:0,y:0),CGPoint(x:1,y:2),CGPoint(x:6,y:8),CGPoint(x:-1,y:6),CGPoint(x:4,y:6),CGPoint(x:11,y:9),CGPoint(x:-3,y:2),CGPoint(x:1,y:7),CGPoint(x:9,y:-7)]
print(convexHull(all_points))
