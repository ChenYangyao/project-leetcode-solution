//simple math problem
class Solution {
    func reachNumber(_ target: Int) -> Int {
        var target = abs(target)
        var k = 0
        
        while (target > 0) {
            k += 1
            target -= k
        }
        
        return target&1 == 0 ? k : (k+1+(k&1))
    }
}
