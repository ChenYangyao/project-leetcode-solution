class Solution {
    func reverseStr(_ s: String, _ k: Int) -> String {
        var s = Array(s)
        let n_max = s.count/(2*k)
        
        if (n_max == 0) {
            s[0..<min(s.count,k)].reverse()
            return String(s)
        }
        
        for n in 0..<n_max {
            s[2*n*k..<(2*n+1)*k].reverse()
        }
        
        if ((s.count%(2*k)) < k) {
            s[(2*n_max*k)...].reverse()
        } else {
            s[(2*n_max*k)..<(2*n_max+1)*k].reverse()
        }
        
        return String(s)
    }
}
