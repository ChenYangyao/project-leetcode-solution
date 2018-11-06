class Solution {
    func s_distance(_ pt1: [Int], _ pt2: [Int]) -> Int {
        return (pt1[0] - pt2[0])*(pt1[0] - pt2[0]) + (pt1[1] - pt2[1]) * (pt1[1] - pt2[1])
    }
    
    func numberOfBoomerangs(_ points: [[Int]]) -> Int {
        let length = points.count
        
        if (length < 3) {
            return 0
        }
        
        var d_count = [Int:Int]()
        var dist = Array(repeating: Array(repeating: 0, count: length), count: length)
        var result = 0
        
        for id1 in 0..<(length - 1) {
            for id2 in (id1 + 1)..<length {
                dist[id1][id2] = s_distance(points[id1],points[id2])
                dist[id2][id1] = dist[id1][id2]
            }
        }
        
        for i in 0..<length {
            d_count.removeAll()
            for dis in dist[i] where (dis != 0) {
                d_count[dis, default: 0] += 1
            }
            for value in d_count.values where (value > 1) {
                result += value*(value - 1)
            }
        }
        
        return result
    }
}
