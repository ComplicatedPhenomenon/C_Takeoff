#include <iostream>
#include<string>
#include"owl.h"

int main(){
    std::string mystr;
    std::cout << "Input your string" << std::endl;
    getline (std::cin, mystr);
    owl xx;
    std::cout << mystr << " is capital word: " << xx.detectCapital(mystr)<< std::endl;

    return 0;
}
