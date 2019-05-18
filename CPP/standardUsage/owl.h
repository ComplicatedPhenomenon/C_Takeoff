#ifndef OWL_H
#define OWL_H
#include<string>
class owl
{
private:
    bool is_lower(char letter);
    bool is_upper(char letter);
    bool is_alphabet(char letter);
public:
    bool detectCapital(std::string word);
};
#endif
