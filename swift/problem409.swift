class Solution {
    func longestPalindrome(_ s: String) -> Int {
        let dic = s.reduce(into: [:]){$0[$1, default: 0] += 1}
        var haveOdd = false
        for decom in dic.values where (decom%2 == 1){
            haveOdd = true
            break
        }
        return dic.values.reduce(0,{$0+$1/2})*2 + (haveOdd ? 1 : 0)
    }
}
