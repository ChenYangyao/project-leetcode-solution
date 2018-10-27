class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
        if (s.count != t.count) {
            return false
        }
        
        var dic_s = [Unicode.Scalar:UInt]()
        var dic_t = [Unicode.Scalar:UInt]()
        
        for char in s.unicodeScalars {
            dic_s[char, default: 0] += 1
        }
        for char in t.unicodeScalars {
            dic_t[char, default: 0] += 1
        }
        
        return (dic_s == dic_t)
    }
}
