class Solution1 {
    func isPowerOfTwo(_ n: Int) -> Bool {
        if (n <= 0) {
            return false
        }
        var rencontre = false
        for digit in String(n, radix: 2) {
            if (digit == "1") {
                if rencontre {
                    return false
                } else {
                    rencontre = true
                }
            }
        }
        
        return true
    }
}

class Solution2 {
    func isPowerOfTwo(_ n: Int) -> Bool {
        var n = n; var rencontre = false
        while (n > 0) {
            if (n & 1 == 1) {
                if rencontre {
                    return false
                } else {
                    rencontre = true
                }
            }
            n >>= 1
        }
        
        return rencontre
    }
}
