class Solution {
    func maxDistToClosest(_ seats: [Int]) -> Int {
        var prevIndex = -1; var maxDistance = 0
        let length = seats.count
        
        for i in 0..<length {
            if (seats[i] == 1) {
                if (prevIndex == -1) {
                    maxDistance = i
                } else {
                    maxDistance = max(maxDistance,(i-prevIndex)/2)
                }
                prevIndex = i
            }
        }
        
        if (prevIndex != length-1) {
            maxDistance = max(maxDistance,length-1-prevIndex)
        }
        
        return maxDistance
    }
}
