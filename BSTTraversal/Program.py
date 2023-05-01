def inOrderTraverse(tree, array):
    # Write your code here.
    if tree == None:
        return array
    if tree.left is None and tree.right is None:
        array.append(tree.value)
    elif tree.left is not None:
        array = inOrderTraverse(tree.left, array)
        array.append(tree.value)
        array = inOrderTraverse(tree.right, array)
    else:
        array.append(tree.value)
        array = inOrderTraverse(tree.right, array)

    return array
    


def preOrderTraverse(tree, array):
    # Write your code here.
    if tree is not None:
        array.append(tree.value)

    if tree.left is not None:
        array = preOrderTraverse(tree.left, array)

    if tree.right is not None:
        array = preOrderTraverse(tree.right, array)

    return array
    


def postOrderTraverse(tree, array):
    # Write your code here.
    if tree.left is not None:
        array = postOrderTraverse(tree.left, array)

    if tree.right is not None:
        array = postOrderTraverse(tree.right, array)

    array.append(tree.value)

    return array


