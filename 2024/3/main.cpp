#include <bits/stdc++.h>

using namespace std;

int sum = 0;

bool isValidNumber(const string &str)
{
    if (str.empty() || str.size() > 3) return false; 
    return all_of(str.begin(), str.end(), ::isdigit);
}


void analyze(string line)
{
    int index = 0;
    while ((line.find("mul(", index)) != string::npos)
    {
        int start = line.find("mul(", index) + 4;
        int end = line.find(")", start);
        
        // Ensure the closing parenthesis is within the next 8 characters
        if (end == string::npos || end - start > 8)
        {
            cerr << "Error: Closing parenthesis is too far from mul(" << endl;
            index = start + 1; // Move forward to continue searching
            continue;
        }

        string numbers = line.substr(start, end - start);
        size_t commaPos = numbers.find(",");
        if (commaPos == string::npos) // Ensure ',' exists
        {
            cerr << "Error: Missing comma in mul(" << numbers << ")" << endl;
            index = end + 1; // Move forward to continue searching
            continue;
        }

        // Extract potential numbers
        string firstNumStr = numbers.substr(0, commaPos);
        string secondNumStr = numbers.substr(commaPos + 1);

        // Validate and parse numbers
        if (!isValidNumber(firstNumStr) || !isValidNumber(secondNumStr))
        {
            cerr << "Error: Invalid numbers in mul(" << numbers << ")" << endl;
            index = end + 1;
            continue;
        }

        int firstNumber = stoi(firstNumStr);
        int secondNumber = stoi(secondNumStr);

        // Perform calculations
        cout << "firstNumber: " << firstNumber << " secondNumber: " << secondNumber << endl;
        cout << "product: " << firstNumber * secondNumber << endl;
        sum += firstNumber * secondNumber;
        cout << "sum: " << sum << endl;

        // Move index forward to search for the next occurrence
        index = end + 1;
    }
}

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
        cout << "linea: " << countOfLines << endl;
        analyze(line);
        countOfLines++;
    }

    file.close();

    cout << "The sum of the numbers is: " << sum << endl;
    return 0;
}