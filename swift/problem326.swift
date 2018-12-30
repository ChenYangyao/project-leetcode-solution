//ref: https://leetcode.com/problems/power-of-three/solution/
//Approach #4 Integer Limitations
//Noted that for swift, Int means Int64 by default, so we need use 3^39 instead of 3^19
class Solution {
    func isPowerOfThree(_ n: Int) -> Bool {
        return n > 0 && (4052555153018976267 % n) == 0
    }
}
