class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        return nums.reduce(into: [:]){$0[$1, default: 0] += 1}.sorted{$0.value > $1.value}[0..<k].map{$0.key}
    }
}
