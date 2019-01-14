class Solution {
    func isPowerOfFour(_ num: Int) -> Bool {
        if (num < 1) {
            return false
        } else if (num == 1) {
            return true
        } else if (4611686018427387904%num != 0) {
            return false
        }
        let lastDigit = String(num).last!
        return (lastDigit == "4" || lastDigit == "6") ? true : false
    }
}
