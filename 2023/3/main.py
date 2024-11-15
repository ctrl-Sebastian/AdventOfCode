inputFile = open("C:/Users/sebas/Desktop/Coding/AdventOfCode/2023/3/input.txt", "rt")
fileContent = inputFile.read()

# enter each char in the matrix, when a new line found, enter in the next y position of matrix
matrix = [[]]

def checkAdj(matrix, x, y):
    if matrix[y-1][x-1] :

for i in range(len(fileContent)):
    if fileContent[i] == '\n':
        matrix.append([])
    else:
        matrix[len(matrix) - 1].append(fileContent[i])

for i in range(len(matrix)):
    print(matrix[i])


inputFile.close()