class Solution {
    func frequencySort(_ s: String) -> String {
        let sortResult = s.reduce(into: [:]){$0[$1, default: 0] += 1}.sorted{$0.value > $1.value}
        return sortResult.reduce(into: String()){$0 += String(repeating: $1.key, count: $1.value)}
    }
}
