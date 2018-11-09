class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var record = [Character:Int]()
        var index = 0
        for char in s {
            if (record[char] == nil) {
                record[char] = index
            } else {
                record[char] = -1
            }
            index += 1
        }
        
        var ans = s.count
        for index in record.values where (index != -1){
            ans = min(ans,index)
        }
        
        return (ans == s.count) ? -1 : ans
    }
}
