//brute force
//time limit exceeded
class Solution1 {
    func findAnagrams(_ s: String, _ p: String) -> [Int] {
        if (s.count < p.count) {
            return [Int]()
        }
        
        let pChar = p.reduce(into: [:]){$0[$1,default: 0] += 1}
        
        let s = Array(s); var ans = [Int]()
        let pLength = p.count - 1
        
        for i in 0..<(s.count-pLength) {
            if (s[i...(i+pLength)].reduce(into: [:]){$0[$1,default: 0] += 1} == pChar) {
                ans.append(i)
            }
        }
        
        return ans
    }
}

//slightly modified
class Solution2 {
    func findAnagrams(_ s: String, _ p: String) -> [Int] {
        if (s.count < p.count) {
            return [Int]()
        }
        
        let pLength = p.count-1; let s = Array(s)
        var pChar = p.reduce(into: [:]){$0[$1,default: 0] += 1}
        var sChar = s[0..<pLength].reduce(into: [:]){$0[$1,default: 0] += 1}
        var ans = [Int]()
        
        for i in 0..<(s.count-pLength) {
            sChar[s[i+pLength],default: 0] += 1
            if (sChar == pChar) {
                ans.append(i)
            }
            let cur = s[i]
            sChar[cur]! -= 1
            if (sChar[cur] == 0 && pChar[cur] == nil) {
                //we don't remove cur from sChar since it is an O(n) operation
                pChar[cur] = 0
            }
        }
        
        return ans
    }
}
