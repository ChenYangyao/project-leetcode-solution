class Solution {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        if (s.count != t.count) {
            return false
        }
        
        let s = s.map{$0}; let t = t.map{$0}
        var mapping = [Character:Character]()
        
        for i in 0..<s.count {
            let sTmp = s[i]; let tTmp = t[i]
            if (mapping[sTmp] != nil) {
                if (tTmp != mapping[sTmp]!) {
                    return false
                }
            } else if mapping.values.contains(tTmp) {
                return false
            } else {
                mapping[sTmp] = tTmp
            }
        }
        return true
    }
}
