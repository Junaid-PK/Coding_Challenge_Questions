# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def middleNode(linkedList):
    # Write your code here.
    temp = linkedList
    count = 0
    while temp is not None:
        count+=1
        temp = temp.next
    middleNode = linkedList
    for _ in range(count // 2):
        middleNode = middleNode.next
    return middleNode

