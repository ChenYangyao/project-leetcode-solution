class Solution {
    func longestPalindrome(_ s: String) -> Int {
        var dic = [Unicode.Scalar:Int]()
        for char in s.unicodeScalars {
            dic[char, default: 0] += 1
        }
        
        var haveOdd = false
        for decom in dic.values where (decom%2 == 1){
            haveOdd = true
            break
        }
        
        return dic.values.reduce(0,{$0+$1/2})*2 + (haveOdd ? 1 : 0)
    }
}
