class Solution {
    func romanToInt(_ s: String) -> Int {
        let converter: [Character:Int] = ["I": 1,
                                          "V": 5,
                                          "X": 10,
                                          "L": 50,
                                          "C": 100,
                                          "D": 500,
                                          "M": 1000]
        var pre = 1001; var cur = 0; var result = 0
        
        for char in s {
            cur = converter[char]!
            if (cur > pre) {
                result -= 2*pre
            }
            result += cur
            pre = cur
        }
        return result
    }
}
