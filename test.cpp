#include <iostream>
using namespace std;


void greet();

int main() {
    auto add=[](int a, int b) {
        return a+b;
    };

    
    cout << "Sum: " << add(5,3) << endl;


    greet();

    return 0;
}


void greet() {
    cout << "hello, world" << endl;
}