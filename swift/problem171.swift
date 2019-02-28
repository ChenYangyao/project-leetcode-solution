class Solution1 {
    func pow(_ power: Int) -> Int {
        var result = 1
        for _ in 0..<power {
            result *= 26
        }
        return result
    }

    func titleToNumber(_ s: String) -> Int {
        let s = s.unicodeScalars
        var power = s.count - 1
        var result = 0
        
        for char in s {
            result += (Int(char.value) - 64)*pow(power)
            power -= 1
        }
        return result
    }
}

class Solution2 {
    func titleToNumber(_ s: String) -> Int {
        let s = s.unicodeScalars
        var result = 0
        
        for char in s {
            result *= 26
            result += (Int(char.value) - 64)
        }
        return result
    }
}
