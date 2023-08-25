# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def middleNode(linkedList):
    # Write your code here.
    fastpointer = linkedList
    slowpointer = linkedList
    while(fastpointer and fastpointer.next):
        fastpointer = fastpointer.next.next
        slowpointer = slowpointer.next
    return slowpointer
