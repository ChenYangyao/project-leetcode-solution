class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.li = []
        

    def push(self, x: int) -> None:
        self.li.append(x)
        

    def pop(self) -> None:
        self.li.pop()
        

    def top(self) -> int:
        return self.li[-1]
        

    def getMin(self) -> int:
        return min(self.li)
        
        
        
# https://leetcode.com/problems/min-stack/discuss/236242/Python3-52-ms-100-Deque
class MinStack:

    def __init__(self):
        self.dq = collections.deque([None])

    def push(self, x: 'int') -> 'None':
        if self.dq[0] == None or self.dq[0] >= x:
            self.dq.appendleft(x)
        self.dq.append(x)

    def pop(self) -> 'None':
        if self.dq[0] != None and self.dq[-1] <= self.dq[0]:
            self.dq.popleft()
        return self.dq.pop()

    def top(self) -> 'int':
        return self.dq[-1]

    def getMin(self) -> 'int':
        return self.dq[0]