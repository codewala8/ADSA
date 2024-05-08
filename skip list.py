import random

class node(object):
    def __init__(self, key, level):
        self.key = key
        self.forward = [None] * (level + 1)

class skiplist(object):
    def __init__(self, max_lvl, p):
        self.MAXLVL = max_lvl
        self.p = p
        self.header = self.createnode(self.MAXLVL, -1)
        self.level = 0

    def createnode(self, lvl, key):
        n = node(key, lvl)
        return n

    def randomlevel(self):
        lvl = 0
        while random.random() < self.p and lvl < self.MAXLVL:
            lvl += 1
        return lvl

    def insertelement(self, key):
        update = [None] * (self.MAXLVL + 1)
        current = self.header
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current
        current = current.forward[0]
        if current is None or current.key != key:
            rlevel = self.randomlevel()
            if rlevel > self.level:
                for i in range(self.level + 1, rlevel + 1):
                    update[i] = self.header
                self.level = rlevel
            n = self.createnode(rlevel, key)
            for i in range(rlevel + 1):
                n.forward[i] = update[i].forward[i]
                update[i].forward[i] = n
            print("successfully inserted key {}".format(key))

    def displaylist(self):
        print("\n*******skip list*******")
        head = self.header
        for level in range(self.level + 1):
            print("level {}: ".format(level), end="")
            node = head.forward[level]
            while node is not None:
                print(node.key, end=" ")
                node = node.forward[level]
            print("")

def main():
    lst = skiplist(3, 0.5)
    lst.insertelement(3)
    lst.insertelement(6)
    lst.insertelement(7)
    lst.insertelement(9)
    lst.insertelement(12)
    lst.insertelement(19)
    lst.insertelement(17)
    lst.insertelement(3)
    lst.insertelement(26)
    lst.insertelement(21)
    lst.insertelement(25)
    lst.displaylist()

main()