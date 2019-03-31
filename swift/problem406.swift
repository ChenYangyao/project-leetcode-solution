//ref: https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89350/Java-solution-using-Arrays.sort()-and-%22insert-sorting%22-idea
class Solution {
    func reconstructQueue(_ people: [[Int]]) -> [[Int]] {
        return people.sorted{p1, p2 in p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1]}.reduce(into: [[Int]]()){$0.insert($1, at: $1[1])}
    }
}
