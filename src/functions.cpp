#include <iostream>

void F_PRINT(std::string string){

		std::cout << "test" << std::endl;

        std::string::size_type i = string.find("print");
        if (i != std::string::npos)
                string.erase(i, 5);

        std::cout << string << std::endl; 
}
