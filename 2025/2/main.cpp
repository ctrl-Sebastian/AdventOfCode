#include <bits/stdc++.h>
using namespace std;

bool is_invalid(string id) {
        // way of thinking: an id is invalid only if it has a sequence repeated twice
        // for that to happen, the id must ve of even length, and a sequence repeated once, meaning, the same sequence two times.
        // if the id has an odd length, it cannot be invalid
        // if the id has an even length, it can be invalid if the first half is equal to the second half
        if (id.length() % 2 != 0) {
                return false;
        }
        string first_half = id.substr(0, id.length() / 2);
        string second_half = id.substr(id.length() / 2);
        return first_half == second_half;
}

unsigned long long analyse_id_range(string id_range, unsigned long long &result) {
        // input ex: "385350926-385403705"
        unsigned long long id_1, id_2;
        char dash;
        stringstream ss(id_range);

        ss >> id_1 >> dash >> id_2;

        for (unsigned long long i = id_1; i <= id_2; i++)
        {
                if(is_invalid(to_string(i))){

                        result += i;
                }
        }


        return 0;
}

int main()
{
        unsigned long long result = 0;

        ifstream input_file;
        input_file.open("input.txt");

        string input_line;
        getline(input_file, input_line);

        stringstream ss(input_line);
        vector<string> id_ranges;

        while (ss.good())
        {
                string substr;
                getline(ss, substr, ',');
                id_ranges.push_back(substr);
        }

        for (auto &&id_range : id_ranges)
        {
                analyse_id_range(id_range, result);
        }


        cout << "Result: " << result << endl;
        input_file.close();

        return 0;
}