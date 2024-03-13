#include <iostream>
#include <iomanip>
using namespace std;

// addition is 1
// suntraction is 2
// multiplication is 3
// division is 4

int num_1;
int num_2;
int answer;

int calculator() {

    cout << "pick a number ";
    cin >> num_1;
    cout << "pick a second number ";
    cin >> num_2; 
    cout << "pick a operator ";
    cin >> answer;
    
        switch(answer) {

        case 1: 
        cout << num_1 + num_2  << endl;
        break;

        case 2:
        cout << num_1 - num_2  << endl;
        break;

        case 3:
        cout << num_1 * num_2  << endl;
        break;

        case 4:
        cout << num_1 / num_2 << endl;
        break;

    };
}

int main() {

    calculator();

    return 0;
}