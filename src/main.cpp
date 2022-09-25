#include <iostream>
#include <fstream>
#include <string>

void F_PRINT(std::string string){

        std::string::size_type i = string.find("print");
        if (i != std::string::npos)
                string.erase(i, 5);

        std::cout << string << std::endl; 
}

/*! \enum tokens
 *
 *  list of valid supported tokens
 */
enum tokens { 
        PRINT = 1,
        HI = 2,
};

tokens getToken (std::string const& inString) {
    if (inString == "print") return PRINT;
    if (inString == "hi") return HI;
}

int count{};

auto iota(){
        count++;
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

        tokens TOKEN;
        //read line by line 
        while (getline (milfCode, line, ';')) {
                TOKEN = getToken(line);
        //TODO: Figure out why this doesn't detect the HI token

                printf("Line: %s\n", line);
                if (PRINT){
                        F_PRINT(line);
                        break;
                }
                else if (HI){
                        printf("Hello!\n");
                }
                iota();
        };
        iota();
        printf("%s\n", line);
        return 0;
}
//vim:filetype=cpp
