// Description: count the frequency of char in S
#include <string>
#include <iostream>
using namespace std;

int Frequency[26];

int hashFunc(char c){
    return (c - 'a');
}

void countFre(string S){
    for(int i = 0; i < S.length(); ++i){
        int index = hashFunc(S[i]);
        Frequency[index]++;
    }
    for(int i = 0;i < 26; ++i){
        cout << (char)(i+'a') << ' ' << Frequency[i] << endl;
    }
}

int main(){
    string S = "ababcd";
    countFre(S);
    return 0;
}
