#include"owl.h"

bool owl::is_lower(char letter){
    return letter >= 'a' && letter <= 'z';
}

bool owl::is_upper(char letter){
    return letter >= 'A' && letter <= 'Z';
}

bool owl::is_alphabet(char letter){
    return is_lower(letter) || is_upper(letter);
}

bool owl::detectCapital(std::string word){
    bool all_upper = true, all_lower = true, first = is_upper(word[0]);
    for (int i = 1; i < word.size(); i++){
        if (is_upper(word[i])) all_lower = false ;
        if (is_lower(word[i])) all_upper = false ;
    }
    return all_lower || (first &&  all_upper);
}
