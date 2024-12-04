
inputFile = open("C:/Users/sebas/Desktop/Coding/AdventOfCode/2024/1/input.txt", "rt")
fileContent = inputFile.read()

leftList = []
rightList = []

sum = 0

for line in fileContent.strip().split('\n'):
    col1, col2 = map(int, line.split())
    leftList.append(col1)
    rightList.append(col2)

leftList.sort()
rightList.sort()

for i in range(len(leftList)):
    sum += abs(leftList[i] - rightList[i])


print("the total distances between the list is: ", sum)
inputFile.close()