class Solution {
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
