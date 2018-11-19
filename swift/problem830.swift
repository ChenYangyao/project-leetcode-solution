class Solution {
    func largeGroupPositions(_ S: String) -> [[Int]] {
        let S = S.unicodeScalars
        var deb = 0; var fin = 0; var index = 0
        var last_char = S.first
        var ans = [[Int]]()
        
        for char in S {
            if (last_char != char) {
                if (fin - deb > 1) {
                    ans.append([deb,fin])
                }
                deb = index
            } else {
                fin = index
            }
            index += 1
            last_char = char
        }
        
        //if the last few characters form large group, it should be added to the ans
        if (fin - deb > 1) {
            ans.append([deb,fin])
        }
        
        return ans
    }
}
