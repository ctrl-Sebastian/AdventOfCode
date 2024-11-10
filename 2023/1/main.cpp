#include <iostream>
#include <fstream>

int main()
{
    int total = 0;
    int numbers[10] ={0,1,2,3,4,5,6,7,8,9};
    std::ifstream file("input.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << std::stoi(line);
            
        }
        file.close();
        std::cout << "Total: " << total << std::endl;
    }

    return 0;
}
