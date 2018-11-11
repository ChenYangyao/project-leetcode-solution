class Solution {
    func findContentChildren(_ g: [Int], _ s: [Int]) -> Int {
        let g = g.sorted(by: >)
        let s = s.sorted(by: >)
        var i = 0; var j = 0
        
        while (i < s.count && j < g.count) {
            if (s[i] >= g[j]) {
                i += 1
            }
            j += 1
        }
        return i
    }
}
