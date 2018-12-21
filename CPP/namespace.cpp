#include<iostream>
using namespace std;

//One namespace
namespace NameA{
    void FunctionA(){
      cout << "This is namespace A" << endl;
    }
}

// Second namespace
namespace NameB{
    void FunctionA(){
      cout << "This is namespace B" << endl;
    }
}

// nested namespace. different is namespace usage
namespace NameC{
    void FunctionA(){
        cout << "This is namespace C" << endl;
    }
    namespace NameD{
        void FunctionA(){
            cout << "This is namespace D" << endl;
        }
    }
}

//using namespace NameA;

int main(){
    NameA::FunctionA();
    NameB::FunctionA();
    NameC::FunctionA();
    NameC::NameD::FunctionA();

    return 0;
}
