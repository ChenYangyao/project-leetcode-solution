class Solution1 {
    func toHexDig(_ dig: Int) -> String {
        var ans = String()
        switch dig {
        case 10:
            ans = "a"
        case 11:
            ans = "b"
        case 12:
            ans = "c"
        case 13:
            ans = "d"
        case 14:
            ans = "e"
        case 15:
            ans = "f"
        default:
            ans = String(dig)
        }
        return ans
    }
    
    func toHex(_ num: Int) -> String {
        var num = num
        var ans = String()
        if (num < 0) {
            num = 4294967296+num
        } else if (num == 0) {
            return "0"
        }
        
        while (num > 0) {
            ans = toHexDig(num%16) + ans
            num /= 16
        }

        return ans
    }
}

//ref: sample 8 ms submission
class Solution2 {
    func toHexDig(_ dig: Int) -> String {
        var ans = String()
        switch dig {
        case 10:
            ans = "a"
        case 11:
            ans = "b"
        case 12:
            ans = "c"
        case 13:
            ans = "d"
        case 14:
            ans = "e"
        case 15:
            ans = "f"
        default:
            ans = String(dig)
        }
        return ans
    }
    
    func toHex(_ num: Int) -> String {
        if num == 0 {
            return "0"
        }
        
        var ans = String();var num = num
        
        for _ in 0..<8 {
            if num == 0 {
                break
            }
            ans = toHexDig(num&15) + ans
            num >>= 4
        }
        return ans
    }
}
