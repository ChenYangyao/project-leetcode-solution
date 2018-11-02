class Solution {
    func isOneBitCharacter(_ bits: [Int]) -> Bool {
        var index = 0
        let length = bits.count - 1
        while (index < length) {
            index += (bits[index] == 1) ? 2 : 1
        }
        return (index == length) ? true : false
    }
}
