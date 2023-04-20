#include <iostream>
#include <vector>
#include <cstring>

int main(int argc, char** argv) {
    // read the input string from the terminal
    std::string inputString = argv[1];
    // std::getline(argv[1], inputString);

    std::vector<int> numbers;
    char* token = std::strtok(const_cast<char*>(inputString.c_str()), " ");

    // iterate over the tokens and store the integers in the vector
    // while (token != NULL) {
    while (token != NULL)
    {
        int n = std::atoi(token);
        std::cout << "token values: " << n << "\n";
            // numbers.push_back(n);
        token = std::strtok(NULL, " ");
        int n = std::atoi(token);
        std::cout << "token values: " << n << "\n";
    }
    // }
    // print the contents of the vector
    // for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        // std::cout << *it << " ";
    // }

    return 0;
}