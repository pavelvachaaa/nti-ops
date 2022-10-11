
#include "mbed.h"
#include "./morse.h"
#include <string>
#include <cctype>

const char dot ='.';
const char *morse[ALPHABET_SIZE]={".-","-...","---.","-..",".","..-.","--.","....","..",".---","-.-",".-..","----","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","..--"};
const char aph[ALPHABET_SIZE]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};

DigitalOut myled(LED1);

 //Enkodování do morseovky
std::string getMorseCode(std::string &input) {
    std::string res = "";
    for (int i =0; i < input.length(); i++) {
        input[i] = std::tolower(input[i]);
        for(int j =0; j < ALPHABET_SIZE;j++) {
            if(input[i] == aph[j]) {
                res+=morse[j];
                break;
            }
        }
    }
    
    return res;
}


// Metoda co bliká
void doBlink(std::string &input) {
 
    for (int i =0; i < input.length(); i++) {
        
        if(input[i] == dot) {
          //  std::cout << ".";
            myled = 1;
            wait(DOT_DURATION);
            myled = 0;
            wait(DOT_DURATION);
        } else {
           // std::cout << "-";
            myled = 1;
            wait(DASH_DURATION);
            myled = 0;
             wait(DASH_DURATION);
        }
    }
    
}
