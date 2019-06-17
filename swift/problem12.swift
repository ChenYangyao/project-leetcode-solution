class Solution {
    private let converter = [["","I","II","III","IV","V","VI","VII","VIII","IX"],["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"],["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"],["","M","MM","MMM"]]
    
    func intToRoman(_ num: Int) -> String {
        var ans = ""; var num = num
        
        for idx in 0..<4 {
            ans = converter[idx][num%10] + ans
            num /= 10
        }
        
        return ans
    }
}
