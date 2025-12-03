#include <bits/stdc++.h>
using namespace std;

int count = 0;

int main()
{
    ifstream file("input.txt");

    if (!file.is_open())
    {
        cerr << "Error opening the file!";
        return 1;
    }

    string line;

    int countOfLines = 1;

    while (getline(file, line))
    {

    }

    file.close();

    cout << "The sum of the numbers is: " << count << endl;
    return 0;
}