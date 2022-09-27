#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

/*! \enum token
 *
 *  list of valid supported tokens
 */
enum token { 
        PRINT = 1,
        HI = 2,
};

token getToken (std::string const& inString) {
    if (inString == "print") return PRINT;
    if (inString == "hi") return HI;
}

int main(int argc, char *argv[]) {
        
        if (argc < 2) {
                fprintf(stderr, "Please provide a path\n" );
                return -1;
        }

        std::string line;
        char *filePath{argv[argc-1]};
        std::ifstream milfCode(filePath); //open file
        std::string kw;

        if (!milfCode) {
                fprintf(stderr, "File path %s is not valid\n", filePath);
                return -1;
        }
		
        //read line by line 
        while (getline (milfCode, line, ';')) {
                token TOKEN{};
                TOKEN = getToken(line);

                std::cout << "Line: " << line << std::endl;
                
                if (TOKEN == PRINT){
                        F_PRINT(line);
                }
                else if (TOKEN == HI){
                        printf("Hello!\n");
                }
        };
        return 0;
}

// vim:filetype=cpp 
