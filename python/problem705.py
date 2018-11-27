class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.li=[[False *100000] for i in range(100000)]
        

    def add(self, key):
        """
        :type key: int
        :rtype: void
        """
        bus=key%100000
        pos=key//100000
        self.li[bus][pos]=True
        
        

    def remove(self, key):
        """
        :type key: int
        :rtype: void
        """
        bus=key%100000
        pos=key//100000
        self.li[bus][pos]=False
        

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        bus=key%100000
        pos=key//100000
        return self.li[bus][pos]==1