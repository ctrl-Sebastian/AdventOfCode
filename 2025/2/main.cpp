#include <bits/stdc++.h>
using namespace std;

bool is_invalid(long id) {
        // TODO: check if ID is invalid
        return true;
}

long analyse_id_range(string id_range) {
        // input ex: "385350926-385403705"
        long id_1, id_2;
        char dash;
        stringstream ss(id_range);

        ss >> id_1 >> dash >> id_2;

        for (long i = id_1; i < id_2; i++)
        {
                if(is_invalid(i)){
                        return i;
                }
                return 0;
        }


        return 0;
}

int main()
{
        unsigned long result = 0;

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
                result += analyse_id_range(id_range);
        }


        cout << "Result: " << result << endl;
        input_file.close();

        return 0;
}