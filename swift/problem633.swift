class Solution {
    func judgeSquareSum(_ c: Int) -> Bool {
        var c = c; var i = 2
        while (i*i <= c) {
            var multi = 0
            if (c % i == 0) {
                while (c % i == 0) {
                    multi += 1
                    c /= i
                }
                if (i % 4 == 3 && multi % 2 != 0) {
                    return false
                }
            }
            i += 1
        }
        return c % 4 != 3
    }
}
