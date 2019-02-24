class Solution1 {
    func findRadius(_ houses: [Int], _ heaters: [Int]) -> Int {
        var maxDist = 0; var i = 0; let heaterNum = heaters.count
        let houses = houses.sorted(); let heaters = heaters.sorted()
        for ps in houses {
            while (i < heaterNum && heaters[i] < ps) {
                i += 1
            }
            switch i {
            case 0:
                maxDist = heaters[0]-houses[0]
            case heaterNum:
                return max(maxDist,abs(houses.last!-heaters.last!))
            default:
                maxDist = max(maxDist,min(heaters[i]-ps,ps-heaters[i-1]))
            }
        }
        return maxDist
    }
}

//ref: cpp version
//prevent switching of i
class Solution2 {
    func findRadius(_ houses: [Int], _ heaters: [Int]) -> Int {
        var maxDist = 0; var i = 1
        let houses = houses.sorted()
        let heaters = (heaters + [-1_000_000_000_000,1_000_000_000_000]).sorted()
        for ps in houses {
            while (heaters[i] < ps) {
                i += 1
            }
            maxDist = max(maxDist,min(heaters[i]-ps,ps-heaters[i-1]))
        }
        return maxDist
    }
}
