class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        if (strs.count == 0) {
            return ""
        }
        
        var shortestLength = strs[0].count
        var shortestStr = strs[0]
        
        for str in strs {
            while !str.hasPrefix(shortestStr) {
                shortestStr.removeLast(1)
                shortestLength -= 1
                if (shortestLength == 0) {
                    return ""
                }
            }
        }
        
        return shortestStr
    }
}
