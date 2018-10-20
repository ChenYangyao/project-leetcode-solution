//recursive
class Solution1 {
    func getSum(_ a: Int, _ b: Int) -> Int {
        if (b == 0) {
            return a
        }
        return getSum(a^b,(a&b) << 1)
    }
}

//iterations
class Solution2 {
    func getSum(_ a: Int, _ b: Int) -> Int {
        var sum = a^b
        var carry = (a&b) << 1
        var tmp = 0
        
        while (carry != 0) {
            tmp = carry
            carry = (sum&tmp) << 1
            sum = sum^tmp
        }
        return sum
    }
}
