#include <iostream>       // For talking to console
#include <string>         // For strings
#include <vector>         // For variable size arrays (called vectors)
#include <ctime>          // For seeding the random number generator
#include <cstdlib>        // For random numbers
using namespace std;      // No more std::cout

// For debugging our code
// This is a global variable
bool debug = true;

void something(){
    string name = "Jackson";     // A local variable stops existing at
                                 // end of function
}

// function declarations (definitions are at the bottom)
void AddFive(int givenNumber){
    // this is passing by value
    cout << "You gave me " << givenNumber << ".\n";
    cout << "I will add 5.\n";
    givenNumber += 5;

    if(debug) cout << "In the function, givenNumber = " << givenNumber << ".\n";
}

void RefAddFive(int& givenNumber){    // this is a reference to an integer
    cout << "You gave me " << givenNumber << ".\n";
    cout << "I will add 5.\n";
    givenNumber += 5;

    if(debug) cout << "In the function, givenNumber = " << givenNumber << ".\n";
}

// * dereference operator
void AddFiveByPointer(int* givenNumber){
    cout << "You gave me " << *givenNumber << ".\n";
    cout << "the memory address of givenNumber is " << givenNumber << ".\n";
    cout << "I am adding 5.\n";
    *givenNumber += 5;
    if(debug) cout << "In the Pointer Function, givenNumber = " << *givenNumber << ".\n";
}

int main() {
    int damage = 0;
    
    cout << "calling AddFive().\n";
    AddFive(damage);
    cout << "Damage = " << damage << ".\n";    // final damage

    cout << "calling RefAddFive().\n";
    RefAddFive(damage);
    cout << "Damage = " << damage << ".\n";

    cout << "calling AddFiveByPointer().\n";
    AddFiveByPointer(&damage);    // & address-of operator
    cout << "Damage = " << damage << ".\n";
    
    // seed the random num generator
    srand(time(0));

    string name = "Jackson";     // A local variable stops existing at 
                                 // end of function

    // peudocode
    // I want player to be greeted by program
    cout << "Hello player.\n";
    
    // start loop
    // while, do-while, and a for loop
    vector<string> friends;    //list of player's friends
    string input = "";
    
    do{
        // ask player for name of friend
        cout <<"Please give me the first name of one of your friends.\n";
        cout <<"Or type 'no' to finish.\n";
        cin >> input;    //no spaces
        
        if(input == "no" || input == "NO" || input == "No"){
            break;
        }

        // add name of friends to vector of names
        friends.push_back(input);
        
    // as long as "input" is not "no", "No", or "NO", keep looping
    // keep looping until player says "no"
    }while(true);


    // not ask for more names than we have. names.size();
    // loop that picks a random name, but what if same name twice?
    // just delete names as we use them
    if(debug) cout << "You have provided " << friends.size() << " names.\n";

    int partySize = rand() % 3 + 1;    // range of 1 to 3

    if (debug){
        cout << "How many people should we have?\n";
        cin >> partySize;

        if(partySize > friends.size()){
            partySize = friends.size();
        }
    }
    
    if(debug) cout << "We're having a party with " << partySize << " people.\n";

    // for (initialization, test, action) {code}
    for(int i = 0; i < partySize; i++){
        int guest = rand() % friends.size();
        
        cout << "You should invite " << friends[guest] << ".\n";
        
        friends.erase(friends.begin() + guest);
    }

    // references
    // pointers
    // passing variables to other functions
    // passing by value
    // passing by reference
}