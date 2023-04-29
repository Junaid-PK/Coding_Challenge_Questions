# This is an input class. Do not edit.
class BST:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def findKthLargestValueInBst(tree, k):
    # Write your code here.
    stack = []
    current= tree
    while stack or current:
        if current:
            stack.append(current)
            current = current.right
            continue
        current = stack.pop()
        k-=1
        if not k:
            return current.value
        current = current.left
        
# test case
tree = BST(15)
tree.left = BST(5)
tree.left.left = BST(2)
tree.left.left.left = BST(1)
tree.left.left.right = BST(3)
tree.left.right = BST(5)
tree.right = BST(20)
tree.right.left = BST(17)
tree.right.right = BST(22)
k = 3
print(findKthLargestValueInBst(tree, k))