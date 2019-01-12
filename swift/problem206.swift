import Dispatch

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

//use array to store the list. space et time complexity O(N)
//seems space for original list is hard to release
class Solution1 {
    func reverseList(_ head: ListNode?) -> ListNode? {
        var head = head
        if (head == nil) {
            return head
        }
        var num = [Int]()
        while (head!.next != nil) {
            num.append(head!.val)
            head = head!.next
        }
        var cur = head
        for number in num.reversed() {
            let tmp = ListNode(number)
            cur!.next = tmp
            cur = tmp
        }
        return head
    }
}

//use two pointers to reverse the list
//constant space consuming.
class Solution2 {
    func reverseList(_ head: ListNode?) -> ListNode? {
        var head = head
        var next: ListNode? = nil
        var prev: ListNode? = nil
        while (head != nil) {
            next = head!.next //store next node
            head!.next = prev
            prev = head
            head = next
        }
        return prev
    }
}

//recursive solution. ref: https://blog.csdn.net/yunzhongguwu005/article/details/10350339
//large stack is needed if long list presents
class Solution3 {
    func reverseList(_ head: ListNode?) -> ListNode? {
        if (head == nil || head?.next == nil) {
            return head
        }
        let new = reverseList(head!.next)
        head!.next!.next = head //reverse the order
        head!.next = nil //point rear to nil
        return new
    }
}

protocol sol {
    func reverseList(_ head: ListNode?) -> ListNode?
}

extension Solution1: sol{}
extension Solution2: sol{}
extension Solution3: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int, _ l: Int) {
    var head = ListNode(0)
    var cur = head
    for i in 1...l {
        let tmp = ListNode(i)
        cur.next = tmp
        cur = tmp
    }
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        head = solution_class.reverseList(head)!
        head = solution_class.reverseList(head)!
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r*2) times")
}

time_consuming(Solution1(),"array",20,1000)
time_consuming(Solution2(),"2 pts",20,1000)//if r or l is huge, this will stop with Segmentation fault 11 after output
time_consuming(Solution3(),"recur",20,1000)
