# 12 red cubes, 13 green cubes, and 14 blue cubes
# sum of the id of possible games

inputFile = open("C:/Users/sebas/Desktop/Coding/AdventOfCode/2023/2/input.txt", "rt")
fileContent = inputFile.read()

sum = 0

for line in fileContent.split("\n"):
    isPossible = True
    index = line[5:line.find(":")]
    print("game: " + index)
    games = line[line.find(":")+2:]
    for game in games.split(";"):
        red = 0
        green = 0
        blue = 0
        sets = game.split(",")
        for x in sets:
            if x.find("red") != -1:
                red += int(x[0:x.find("red")-1])
            elif x.find("green") != -1:
                green += int(x[0:x.find("green")-1])
                
            elif x.find("blue") != -1:
                blue += int(x[0:x.find("blue")-1])
        
        if red > 12 or green > 13 or blue > 14:
            isPossible = False

    if isPossible:
        sum += int(index)

        

print("sum of all possible games: " + str(sum))
inputFile.close()