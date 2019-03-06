public class dequeue {
    private var head = 0
    public var deq: [Int]
    
    init(_ length: Int) {
        deq = [Int](0..<length)
    }
    
    //don't use removeFirst() since it's a O(n) operation
    //here we don't really remove head element from the array,
    //instead we just record the new head index
    //in this problem this method will waste approx. one time of the memory required by the original array which is acceptable
    //(without considering dynamic allocation process)
    //if we want to use this deque class elsewhere, we need to occasionally removeFirst(head)
    public func pop() -> Int {
        print(deq.count)
        /**
         //we can change the number 2 to other larger number to reduce memory consumption
        if (2*head/deq.count == 1) {
            deq.removeFirst(head)
            head = 0
        }
        **/
        defer{
            head += 1
        }
        return deq[head]
    }
    
    public func notEmpty() -> Bool {
        return head < deq.count
    }
}

//simulate revealing process
//ref: https://leetcode.com/problems/reveal-cards-in-increasing-order/solution/
class Solution {
    func deckRevealedIncreasing(_ deck: [Int]) -> [Int] {
        let deck = deck.sorted()
        let length = deck.count
        let index = dequeue(length)
        var ans = [Int](repeating: 0, count: length)
        
        for card in deck {
            ans[index.pop()] = card
            if index.notEmpty() {
                index.deq.append(index.pop())
            }
        }
        
        return ans
    }
}
