#include <bits/stdc++.h>
#include <fstream>
using namespace std;

bool is_accessable(const vector<vector<char>>& map, size_t i, size_t j) {
        int counter = 0;
        int max_col = map.size() -1;
        int max_row = map[i].size() -1;

        // center case
        if (i > 0 && j > 0 && i < max_col && j < max_row) {
                if(map[i-1][j-1] == '@') counter++;
                if(map[i-1][j] == '@') counter++;
                if(map[i-1][j+1] == '@') counter++;
                if(map[i][j+1] == '@') counter++;
                if(map[i+1][j+1] == '@') counter++;
                if(map[i+1][j] == '@') counter++;
                if(map[i+1][j-1] == '@') counter++;
                if(map[i][j-1] == '@') counter++;
        }

        // corner cases
                // upper left           // lower left           // upper right          // lower right
        if((i == 0 && j == 0) || (i == max_col && j == 0) || (i == 0 && j == max_row) || (i == max_col && j == max_row)) return true;

        // edge cases

        // lower edge
        if (i == max_col && j > 0 && j < max_row){
                if(map[i][j-1] == '@') counter++;
                if(map[i-1][j-1] == '@') counter++;
                if(map[i-1][j] == '@') counter++;
                if(map[i-1][j+1] == '@') counter++;
                if(map[i][j+1] == '@') counter++;

        }

        // upper edge
        if (i == 0 && j > 0 && j < max_row) {
                if(map[i][j-1] == '@') counter++;
                if(map[i+1][j-1] == '@') counter++;
                if(map[i+1][j] == '@') counter++;
                if(map[i+1][j+1] == '@') counter++;
                if(map[i][j+1] == '@') counter++;
        }

        // left edge
        if (j == 0 && i > 0 && i < max_col) {
                if(map[i-1][j] == '@') counter++;
                if(map[i-1][j+1] == '@') counter++;
                if(map[i][j+1] == '@') counter++;
                if(map[i+1][j+1] == '@') counter++;
                if(map[i+1][j] == '@') counter++;
        }

        // right edge
                if (j == max_row && i > 0 && i < max_col) {
                if(map[i-1][j] == '@') counter++;
                if(map[i-1][j-1] == '@') counter++;
                if(map[i][j-1] == '@') counter++;
                if(map[i+1][j-1] == '@') counter++;
                if(map[i+1][j] == '@') counter++;
        }

        if (counter < 4) return true;

        return false;
}

void printInColor(const char& text, const string& color) {
    // ANSI escape codes for text color
    const string WHITECOLOR = "\033[1;37m";
    const string GREENCOLOR = "\033[0;32m";
    const string RESETCOLOR = "\033[0m";
if (color == "white") {
    cout << WHITECOLOR << text << RESETCOLOR;
} else if (color == "green") {
    cout << GREENCOLOR << text << RESETCOLOR;
} else {
    throw invalid_argument("Invalid color specified.");
}
}

void print_map(const vector<vector<char>>& map){
        for (int i = 0; i < map.size(); i++)
        {
                for (int j = 0; j < map[i].size(); j++)
                {
                        if (map[i][j] != '@') {
                                cout << map[i][j];
                                continue;
                        }
                        if (is_accessable(map, i, j)){
                                printInColor(map[i][j], "green");
                        } else {
                                cout << map[i][j];
                        }
                }
                cout << endl;

        }
}

int main()
{
        ifstream input_file;
        input_file.open("input.txt");

        int total_rolls = 0;
        vector<vector<char>> map;

        string line;
        while (getline(input_file, line)) {
                vector<char> row(line.begin(), line.end());
                map.push_back(row);
        }

        for (size_t i = 0; i < map.size(); ++i) {
                for (size_t j = 0; j < map[i].size(); ++j) {
                        if (map[i][j] != '@') {
                                continue;
                        }
                        if (is_accessable(map, i, j)){
                                total_rolls++;
                        }
                }
        }

        print_map(map);

        cout << "Total rolls of paper: " << total_rolls << endl;
        input_file.close();
        int a;
        cin >> a;
        return 0;
}