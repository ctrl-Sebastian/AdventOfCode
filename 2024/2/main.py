
inputFile = open("C:/Users/sebas/Desktop/Coding/AdventOfCode/2024/2/input.txt", "rt")
fileContent = inputFile.read()



def partOne():
    count = 0
    def analyze_asc(numbers):
        for i in range(len(numbers) - 1):
            if numbers[i]<numbers[i+1]:
                continue
            else:
                return False
        return True

    def analyze_desc(numbers):
        for i in range(len(numbers) - 1):
            if numbers[i]>numbers[i+1]:
                continue
            else:
                return False
        return True

    def check_adj_lvl(numbers):
        for i in range(len(numbers) - 1):
            if 1 <= abs(numbers[i] - numbers[i+1]) <= 3:
                continue
            else:
                return False
        return True

    def analyze_line(line):
        numbers = list(map(int, line.split()))

        if check_adj_lvl(numbers):
            if numbers[1] > numbers[0]:
                return analyze_asc(numbers)
            elif numbers[1] < numbers[0]:
                return analyze_desc(numbers)
            else:
                return False
        else:
            return False
        

    for line in fileContent.strip().split("\n"):
        if analyze_line(line) == True:
            count += 1

    print(count, " reports are valid")


def partTwo():
    count = 0

    def analyze_asc(numbers):
        for i in range(len(numbers) - 1):
            if numbers[i] < numbers[i + 1]:
                continue
            else:
                return False
        return True

    def analyze_desc(numbers):
        for i in range(len(numbers) - 1):
            if numbers[i] > numbers[i + 1]:
                continue
            else:
                return False
        return True

    def check_adj_lvl(numbers):
        for i in range(len(numbers) - 1):
            if 1 <= abs(numbers[i] - numbers[i + 1]) <= 3:
                continue
            else:
                return False
        return True

    def is_valid(numbers):
        if check_adj_lvl(numbers):
            if numbers[1] > numbers[0]:
                return analyze_asc(numbers)
            elif numbers[1] < numbers[0]:
                return analyze_desc(numbers)
            else:
                return False
        else:
            return False

    def analyze_line(line):
        numbers = list(map(int, line.split()))

        if is_valid(numbers):
            return True

        for i in range(len(numbers)):
            modified_numbers = numbers[:i] + numbers[i+1:]
            if is_valid(modified_numbers):
                return True
        return False

    for line in fileContent.strip().split("\n"):
        if analyze_line(line):
            count += 1

    print(count, " reports are valid")


partTwo()

inputFile.close()