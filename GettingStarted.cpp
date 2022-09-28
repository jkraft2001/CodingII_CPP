#include <iostream>
using namespace std;

int main() {

    // This is a comment ignored by the code.
    
    
    // An int is a whole number.
    // Floats are rational numbers.
    
    int age = 20;
    float pi = 3.14f;
    

    // A bool is a true or false statement.
    bool isHungry = true;


    // Strings are for text.
    string name = "Jackson Kraft";

    cout << "Hello " << name << "!\n";


    if(isHungry){
        cout << "You have eaten some food.\n";
        isHungry = false;
    }
    else{
        cout << "You starve in the miserable state of being you call life.\n";
    }

    int counter = 0;

    // While test is true, keep looping.
    while(counter < 5){
        counter++;
        cout << "Press the ENTER key...\n";
        string temp;
        cin >> temp;
    }


    string inventory[5];

    inventory[0] = "Iron dagger";
    inventory[1] = "Kitetsu III";
    inventory[2] = "Germa 66 Raid Suit 3";
}