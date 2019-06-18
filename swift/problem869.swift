class Solution {
    private let lowerBoundary = [0,4,7,10,14,17,20,24,27,30,30]
    
    func reorderedPowerOf2(_ N: Int) -> Bool {
        let NS = String(N).sorted()
        let length = NS.count
        
        for power in lowerBoundary[length-1]...lowerBoundary[length] {
            if (NS == String(1 << power).sorted()) {
                return true
            }
        }
        
        return false
    }
}
