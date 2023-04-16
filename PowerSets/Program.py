def powerset(array):
    # Write your code here
    subsets = [[]]
    for num in array:
        for i in range(len(subsets)):
            currentSubset= subsets[i]
            subsets.append(currentSubset + [num])
    return subsets

def main():
    array = [1, 2, 3]
    print(powerset(array))

if __name__ == "__main__":
    main()