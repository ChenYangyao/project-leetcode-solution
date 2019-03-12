class Solution {
    func partitionLabels(_ S: String) -> [Int] {
        let S = S.map{$0}
        var dict = [Character:Int]()
        
        var index = 0
        for char in S {
            dict[char] = index
            index += 1
        }
        
        var ans = [Int]()
        var maxIndex = 0; var tmpIndex = -1
        index = 0
        for char in S {
            maxIndex = max(maxIndex, dict[char]!)
            if (index == maxIndex) {
                ans.append(index - tmpIndex)
                tmpIndex = index
            }
            index += 1
        }
        
        return ans
    }
}
