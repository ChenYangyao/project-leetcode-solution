class Solution1 {
    func convertToBase7(_ num: Int) -> String {
        if (num == 0) {
            return "0"
        }
        var result = num > 0 ? String() : "-"
        var num = abs(num); var flag = true
        let pow = [5764801, 823543, 117649, 16807, 2401, 343, 49, 7, 1]
        
        for i in pow {
            if (flag && num < i) {
                continue
            }
            flag = false
            result.append(String(num/i))
            num = num%i
        }
        
        return result
    }
}

//use built-in function
class Solution2 {
    func convertToBase7(_ num: Int) -> String {
        return String(num,radix:7)
    }
}
