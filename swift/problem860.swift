class Solution {
    func lemonadeChange(_ bills: [Int]) -> Bool {
        var count_five = 0; var count_ten = 0
        for number in bills {
            if (number == 5) {
                count_five += 1
            } else if (number == 10) {
                count_five -= 1
                count_ten += 1
            } else if (number == 20) {
                if (count_ten > 0) {
                    count_ten -= 1
                    count_five -= 1
                } else {
                    count_five -= 3
                }
            }
            if (count_five < 0 || count_ten < 0) {
                return false
            }
        }
        return true
    }
}
