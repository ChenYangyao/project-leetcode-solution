//swift implementation of cpp version
//no need to change original flowerbed array
class Solution {
    private var size = 0
    
    func canPlaceFlowers(_ flowerbed: [Int], _ n: Int) -> Bool {
        size = flowerbed.count; var flowerbed = flowerbed
        var i = -1
        _ = nextFlower(&flowerbed, &i) //first planted flower
        
        if (i == size) {
            return (i+1)>>1 >= n
        }
        
        var nget = (i>>1); var j = i
        
        while (nget < n && nextFlower(&flowerbed, &j) != size) {
            nget += ((j-i-2)>>1)
            i = j
        }
        
        if (nget >= n) {
            return true
        }
        
        return (nget + (size-i-1)>>1) >= n
    }
    
    private func nextFlower(_ flowerbed: inout [Int], _ i: inout Int) -> Int {
        repeat {
            i += 1
        } while (i < size && flowerbed[i] == 0)
        
        return i
    }
}
