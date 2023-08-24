# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def removeDuplicatesFromLinkedList(linkedList):
    # Write your code here.
    if linkedList is None or linkedList.next is None:
        return linkedList
    modifierNode = linkedList
    while(modifierNode.next is not None and modifierNode is not None):
        if modifierNode.value == modifierNode.next.value:
            modifierNode.next = modifierNode.next.next
        else:
            modifierNode = modifierNode.next
    return linkedList
