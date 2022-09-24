#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
        std::string line;
        std::ifstream milfCode("Code.milf"); //open file
        //read line by libe 
        while (getline (milfCode, line)) {
                std::cout << line << std::endl;
        }
        milfCode.close(); //close file

        std::cout << "This is going to be a compiler at some point" << std::endl;
        return 0;
}
