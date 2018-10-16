class Solution {
    func detectCapitalUse(_ word: String) -> Bool {
        if (word.count <= 1) {
            return true
        }
        
        var index = word.startIndex
        let end = word.index(before: word.endIndex)
        
        if (word[index] > "Z") {
            while (index < end) {
                word.formIndex(after: &index)
                if (word[index] < "a") {
                    return false
                }
            }
        } else {
            word.formIndex(after: &index)
            if (word[index] > "Z") {
                while (index < end) {
                    word.formIndex(after: &index)
                    if (word[index] < "a") {
                        return false
                    }
                }
            } else {
                while (index < end) {
                    word.formIndex(after: &index)
                    if (word[index] > "Z") {
                        return false
                    }
                }
            }
        }
        
        return true
    }
}

print(Solution().detectCapitalUse("USA"))
