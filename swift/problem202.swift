class Solution {
    private func sum_of_square(_ n: Int) -> Int {
        var n = n
        var ans = 0
        while (n != 0) {
            ans += (n%10)*(n%10)
            n /= 10
        }
        return ans
    }
    
    func isHappy(_ n: Int) -> Bool {
        var n = n
        var represent = Set<Int>()
        while (n != 1) {
            n = sum_of_square(n)
            if (represent.contains(n)) {
                return false
            } else {
                represent.insert(n)
            }
        }
        return true
    }
}
