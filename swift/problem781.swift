//ref: https://leetcode.com/problems/rabbits-in-forest/discuss/291987/Simple-solution
class Solution {
    func numRabbits(_ answers: [Int]) -> Int {
        var counter = [Int:Int]()
        var ans = 0
        
        for answer in answers {
            if (counter[answer, default: 0] == 0) {
                counter[answer] = answer
                ans += (answer + 1)
            } else {
                counter[answer]! -= 1
            }
        }
        
        return ans
    }
}
