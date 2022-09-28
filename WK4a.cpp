#include <iostream>
#include <string>;
#include <ctime>; //seeding the random number generator
#include <cstdlib>; //generate random numbers
using namespace std;

bool debug = true; // make this false to get rid of debug statements

// return type, name of the function, (parameters/input variables)
int GetRandomNumber(int range = 6, int min = 1){
    return rand() % range + min;
}

// create a function that returns a random name.
// create function that returns a string named GetName()
// optionally, don't pick the same name twice

string GetName(string badName = ""){
    // an array of names
    // use a collection initializer to populate the array
    // {curly braces} [brackets] <angle brackets> (parentheticals)
    // 'single quotes' "quotations" ~tilde
    // forward slash/ back slash\ vertical bar|
    string names[5] = {"Luke", "Han", "Leia", "Darth Vader", "Lando"};

    string name = names [GetRandomNumber(5,0)];
    while(name == badName){
        name = names[GetRandomNumber(5,0)];
    }
    return name;
}

int main() {
    //seeding random number generator
    srand(time(0));    
    
    cout << "I am alive?\n";
    string aiName = GetName();
    cout << "My name is " << GetName() << ".\n";

    int randomNumber = rand();
    cout << "Here's a random numbrer: " <<randomNumber << ".\n";

    cout << "37 divided by 5 is " << 37/5 << ".\n";
    cout << "Oh, and a remainder of " << 37 % 5 << ".\n";

    cout << "Here's a random number between 0 and 10: " << rand() % 10 << ".\n";

    cout << "Your dice roll is " << GetRandomNumber() << ".\n";

    bool inGoodMood;
    int moodNumber = GetRandomNumber(100);

    if (debug == true) cout <<"moodNumber: " << moodNumber << ".\n";
    
    if (moodNumber > 50) inGoodMood = true;
    else inGoodMood = false;
    if (moodNumber < 20) cout << "Demons in hell...\n";
    if (moodNumber > 80) cout << "Gavin or Google?\n";
    if (moodNumber > 95) cout << "CRITICAL ROLL!!\n";
    if (moodNumber < 5) cout << "CRITICAL FAIL??\n";

    if (inGoodMood) cout << "I'm feelin' lucky.\n";
    else cout << "I have only known defeat.\n";

    cout << "My best friend is " << GetName(aiName) << ".\n";
    }