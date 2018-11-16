class Solution1 {
    func findRestaurant(_ list1: [String], _ list2: [String]) -> [String] {
        let dic = Dictionary(uniqueKeysWithValues: zip(list1, 0..<list1.count))
        var index = 0
        var sum = Int.max
        var ans = [Int]()
        
        index = 0
        for rt in list2 {
            if let index_1 = dic[rt] {
                if (index + index_1 < sum) {
                    ans = [index]
                    sum = index + index_1
                } else if (index + index_1 == sum) {
                    ans.append(index)
                }
            }
            index += 1
        }
        
        return ans.compactMap{list2[$0]}
    }
}

class Solution2 {
    func findRestaurant(_ list1: [String], _ list2: [String]) -> [String] {
        let dic1 = Dictionary(uniqueKeysWithValues: zip(list1, 0..<list1.count))
        let dic2 = Dictionary(uniqueKeysWithValues: zip(list2, 0..<list2.count))
        var sum = Int.max
        var ans = [Int]()
        
        for rt in Set(list1).intersection(list2) {
            let i = dic1[rt]!
            let j = dic2[rt]!
            if (i+j < sum) {
                ans = [i]
                sum = i+j
            } else if (i+j == sum) {
                ans.append(i)
            }
        }
        
        return ans.compactMap{list1[$0]}
    }
}
