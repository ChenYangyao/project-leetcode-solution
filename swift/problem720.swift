class Solution {
    func longestWord(_ words: [String]) -> String {
        let words = words.sorted{$0.count < $1.count}
        var longest_length = 1
        var records = Set<String>()
        var ans = "{" //larger than any small case string
        
        for var word in words {
            if (word.count == 1) {
                records.insert(word)
            } else {
                let tmp = word
                if (records.contains(word)) {
                    records.insert(tmp)
                    longest_length = max(longest_length,tmp.count)
                }
            }
        }
        
        for word in records where (word.count == longest_length) {
            ans = min(word,ans)
        }
        
        return ans
    }
}
