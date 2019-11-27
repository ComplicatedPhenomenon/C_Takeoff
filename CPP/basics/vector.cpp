/** 
 *  method on vector
 **/

#include<iostream>
#include<vector>
#include<array>
#include <chrono>
#include <thread>
using namespace std;

void printOneDVector(vector<int> &v){
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    cout << "At time" << ctime(&t) << ", elements in vector v includes: ";
    for(const int &n : v){
        cout << n << " ";
    }
    cout << endl;

    cout << "v.size() is: " << v.size() << endl;
    cout << "v.capacity() is: " << v.capacity() << endl;

    this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main() {
    vector<int> v = {7, 5, 16, 8};
    // Add 2 more integers to vector
    v.push_back(25);
    v.push_back(13);

    printOneDVector(v);

    array<int, 3> array1 {4, 7, 9};
    for (const int &a : array1){
        v.push_back(a);
    } 
    printOneDVector(v);


    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    cout << "matrix has " << matrix.size() * matrix[0].size() << " elements" << endl; 

    return 0;
}
