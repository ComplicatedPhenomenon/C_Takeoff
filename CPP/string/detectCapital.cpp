#include <iostream>
#include <string>
using namespace std;

class owl{
private:
    bool is_lower(char letter){
        return letter >= 'a' && letter <= 'z';
    }

    bool is_upper(char letter){
        return letter >= 'A' && letter <= 'Z';
    }

    bool is_alphabet(char letter){
        return is_lower(letter) || is_upper(letter);
    }
public:
    bool detectCapital(string word){
        bool all_upper = true, all_lower = true, first = is_upper(word[0]);
        for (int i = 1; i < word.size(); i++){
            if (is_upper(word[i])) all_lower = false ;
            if (is_lower(word[i])) all_upper = false ;

        }
        return all_lower || (first &&  all_upper);
    }
};

int main(){
    string mystr;
    cout << "Input your string" << endl;
    getline (cin, mystr);
    owl xx;
    cout << mystr << " is capital world: " << xx.detectCapital(mystr)<< endl;

    return 0;
}
