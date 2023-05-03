# This is an input class. Do not edit.
class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def validateBst(tree):
    # Write your code here.
    return validateHelper(tree, float("-inf"),float("inf"))

def validateHelper(tree, minVal, maxVal):
    if tree is None:
        return True

    if tree.value < minVal or tree.value >= maxVal:
        return False
    left= validateHelper(tree.left,minVal, tree.value)
    right= validateHelper(tree.right,tree.value, maxVal)
    return  left and right


# main
test1 = BST(10)
test1.left = BST(5)
test1.right = BST(15)
test1.left.left = BST(2)
test1.left.right = BST(5)
test1.left.left.left = BST(1)
test1.right.left = BST(13)
test1.right.right = BST(22)
test1.right.left.right = BST(14)

print(validateBst(test1))
