class Solution1 {
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

//swift implementation of cpp version
class Solution2 {
    func isPowerOfFour(_ num: Int) -> Bool {
        return (num > 0) && (num & (num - 1) == 0) && (num & 0x5555555555555555 != 0)
    }
}
