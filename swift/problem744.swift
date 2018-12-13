class Solution {
    func nextGreatestLetter(_ letters: [Character], _ target: Character) -> Character {
        var tail = letters.count - 1
        if (letters[tail] <= target) {
            return letters[0]
        }
        var head = 0; var mid = 0
        
        while (head < tail) {
            mid = (head+tail)/2
            if (letters[mid] <= target) {
                head = mid+1
            } else {
                tail = mid
            }
        }
        
        return letters[head]
    }
}
