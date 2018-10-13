extension Int {
    var array: [Int] {
        return String(self).compactMap{Int(String($0))}
    }
}

class Solution1 {
    func addDigits(_ num: Int) -> Int {
        var output = num.array
        while (output.count != 1) {
            output = output.reduce(0,+).array
        }
        return output[0]
    }
}

//ref: https://en.wikipedia.org/wiki/Digital_root
class Solution2 {
    func addDigits(_ num: Int) -> Int {
        return (num-1)%9+1
    }
}

print(Solution1().addDigits(1209409185989203))
print(Solution2().addDigits(1209409185989203))
