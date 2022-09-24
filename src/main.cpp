#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
        std::string line;
        std::ifstream milfCode(argv[argc-1]); //open file

        if (!milfCode) {
                std::cerr << "File not found" << std::endl;
        }

        //read line by line 
        while (getline (milfCode, line)) {
                std::cout << line << std::endl;
        }

        return 0;
}
