import Foundation

class Solution {
    private let heures = [[UInt8]]([[0],[1,2,4,8],[3,5,6,9,10],[7,11]])
    private let minutes = [[UInt8]]([[0],[1,2,4,8,16,32],[3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48],[7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56],[15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58],[31, 47, 55, 59]])
    
    func readBinaryWatch(_ num: Int) -> [String] {
        var ans = [String]()
        for minute in 0...min(5,num) { //minute.max == 5
            let heure = num - minute
            if (heure < 4) { //heure.max == 3
                for i in heures[heure] {
                    for j in minutes[minute] {
                        ans.append(String(format:"%d",i)+":"+String(format:"%02d",j))
                    }
                }
            }
        }
        return ans
    }
}
