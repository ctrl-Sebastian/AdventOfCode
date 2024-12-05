
inputFile = open("C:/Users/sebas/Desktop/Coding/AdventOfCode/2024/1/input.txt", "rt")
fileContent = inputFile.read()

leftList = []
rightList = []


for line in fileContent.strip().split('\n'):
    col1, col2 = map(int, line.split())
    leftList.append(col1)
    rightList.append(col2)

leftList.sort()
rightList.sort()


def partOne():
    sum = 0
    for i in range(len(leftList)):
        sum += abs(leftList[i] - rightList[i])
    print("the total distances between the list is: ", sum)


def partTwo():
    score = 0
    element_dict = {}
    for n in rightList:
        if n in element_dict:
            element_dict[n] += 1
        else:
            element_dict[n] = 1

    for n in leftList:
        if n in element_dict:
            score += (n * element_dict[n])
    
    print("similarity score: ", score)

partTwo()

inputFile.close()