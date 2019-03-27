class Solution1 {
    func customSortString(_ S: String, _ T: String) -> String {
        var T = T.reduce(into: [:]){$0[$1, default:0] += 1}
        var ans = String()
        
        for char in S where (T[char] != nil) {
            ans.append(String(repeating: char, count: T[char]!))
            T[char] = 0
        }
        
        for (key, value) in T where (value != 0) {
            ans.append(String(repeating: key, count: value))
        }
        
        return ans
    }
}

class Solution2 {
    func customSortString(_ S: String, _ T: String) -> String {
        let S = S.enumerated().reduce(into: [:]){$0[$1.element] = $1.offset}
        return String(T.sorted(by: {S[$0] ?? 0 < S[$1] ?? 0}))
    }
}
