class Solution {
    func findLUSlength(_ a: String, _ b: String) -> Int {
        return a == b ? -1 : max(a.count, b.count)
    }
}

var test = Solution()
print(test.findLUSlength("test","tset"))
