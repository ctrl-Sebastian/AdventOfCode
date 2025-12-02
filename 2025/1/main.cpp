#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Direction {
        LEFT,
        RIGHT
};

Direction get_direction(char dir) {
        if (dir == 'L') {
                return LEFT;
        } else {
                return RIGHT;
        }
}

int move_dial(Direction dir, int amount, int &current_position) {
        if (dir == LEFT) {
                current_position -= amount % 100;
                if (current_position < 0) {
                        current_position += 100;
                }
        } else {
                current_position += amount % 100;
                if (current_position >= 100) {
                        current_position -= 100;
                }
        }
        cout << "Current Position: " << current_position << endl;
        if (current_position == 0) {
                return 1;
        }
        return 0;
}


int main() {
        int counter  = 0;
        int current_postition = 50;
        ifstream input;
        input.open("input.txt");
        for(string line; getline(input, line);) {
                char dir = line[0];
                Direction direction = get_direction(dir);
                int amount = stoi((string)line.substr(1));
                counter += move_dial(direction, amount, current_postition);

        }
        cout << "Password: " << counter << endl;
        input.close();
        return 0;
}