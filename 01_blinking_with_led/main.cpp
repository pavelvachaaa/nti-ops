
#include "mbed.h"
#include "./morse.h"


int main() {  
    std::string input = "jakub";
    std::string morseCode = getMorseCode(input);
    
    doBlink(morseCode);

}
 