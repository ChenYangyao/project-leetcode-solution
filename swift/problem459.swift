import Foundation

class Solution {
    func repeatedSubstringPattern(_ s: String) -> Bool {
        return ((s+s).dropFirst().range(of: s)!.lowerBound.encodedOffset != s.count)
    }
}
