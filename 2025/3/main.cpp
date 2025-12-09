#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int turn_on_batteries(string bank)
{
        int biggest = bank[0] - '0';
        int biggest_index = 0;
        for (int i = 1; i < bank.length() - 1; i++)
        {
                if ((bank[i] - '0') > biggest)
                {
                        biggest = (bank[i] - '0');
                        biggest_index = i;
                }
        }
        int second_biggest = 0;

        for (int j = biggest_index + 1; j < bank.length(); j++)
        {
                if ((bank[j] - '0') > second_biggest)
                {
                        second_biggest = (bank[j] - '0');
                }
        }
        return (biggest * 10) + second_biggest;
}

int main()
{
        ifstream input_file;
        input_file.open("input.txt");

        unsigned int total_jolts = 0;

        for (string line; getline(input_file, line);)
        {

                total_jolts += turn_on_batteries(line);
        }

        cout << "Total Jolts: " << total_jolts << endl;
        input_file.close();
        return 0;
}