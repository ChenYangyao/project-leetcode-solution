class Solution {
    func escapeGhosts(_ ghosts: [[Int]], _ target: [Int]) -> Bool {
        let dist = {(_ pt: [Int]) in
            abs(pt[0] - target[0]) + abs(pt[1] - target[1])
        }
        
        let orig = dist([0,0])
        
        for ghost in ghosts {
            if (dist(ghost) >= orig) {
                return false
            }
        }
        
        return true
    }
}
