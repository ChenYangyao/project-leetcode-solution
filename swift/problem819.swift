class Solution {
    private let punctuation = Set("!?',;. ")
    
    func mostCommonWord(_ paragraph: String, _ banned: [String]) -> String {
        var ans = String(); var freq = 0; var dict = [String:Int]()
        
        let banned = Set(banned)
        var word = String()
        for char in paragraph {
            if punctuation.contains(char) {
                if (!banned.contains(word) && word != "") {
                    dict[word, default: 0] += 1
                    if (dict[word]! > freq) {
                        freq = dict[word]!
                        ans = word
                    }
                }
                word = String()
            } else {
                word += String(char).lowercased()
            }
        }
        
        if dict.isEmpty {
            return word
        }
        
        return ans
    }
}
