#include <iostream>
#include <queue>
using namespace std;

// This is a declaration. The details come later.
// class Enemy;

/*
Token System:
If an enemy wants to attack, they need a "token"
If there are five enemies available and only two tokens,
    two of the five enemies can attack the player.
    The other three enemies get into a "queue."
    Once the initial enemies attack, the token is freed,
    which means the next enemy in line can attack.
    In DOOM (2016), higher difficulties result in more
    available tokens.
Tokens are handled with a "Queue" variable!
    A first in, first out system.
    (A "Stack" variable is a first in, last out system.)
We'll need some variable for tracking tokens:
    An integer to determine token availability/difficulty
        Also the maximum tokens potentially available
        at any point.
    A queue for the token priority system.
*/

// This is the definition that the declaration references.
class Enemy {
public:
  string EnemyName;
  int EnemyDamage;

  Enemy(string GivenName = "Demigorgon", int EnemyDamage = 5) {
    EnemyName = GivenName;
    EnemyDamage = EnemyDamage;
  }

  // void Attack(Player& Player){
  //    cout << "I have a token. Take " << EnemyDamage << " damage.\n";
  //}

}; // End of Enemy class

// Classes are our own variable type.
class Player {
public:
  string Name = "DOOMSLAYER";
  int CurrentTokens = 2;
  int MaxTokens = 2;

  queue<Enemy> EnemiesWaiting;

  // A constructor runs when the instance is created.
  // A constructor needs to be named the same as the class
  Player() {}

  Player(string GivenName, int GivenMaxTokens) {
    cout << "Creating a new player: " << GivenName << ".\n";

    Name = GivenName;
    MaxTokens = GivenMaxTokens;
    CurrentTokens = MaxTokens;
  }

  void GetAttacked(Enemy &Attacker) {
    if (CurrentTokens > 0) { // Do we have tokens?
      CurrentTokens--;       // Yes, but now we have less.
      cout << Attacker.EnemyName << " does " << Attacker.EnemyDamage
           << " damage.\n"; // Lose one token, get one attack.
    } else {
      // Add the tokens to the queue.
      EnemiesWaiting.push(Attacker);
    }
  }

  void TokenRefresh() {
    if (EnemiesWaiting.size() > 0) {
        Enemy temp = EnemiesWaiting.front();
        GetAttacked(temp);
        EnemiesWaiting.pop();
    }
  }

}; // End of Player class

int main() {
  std::cout << "Hello World!\n";

  int MyAge = 21;
  string MyName = "Jackson";
  cout << "My name has " << MyName.size() << " letters.\n";

  Player PlayerOne;
  cout << "Welcome " << PlayerOne.Name << ". RIP and TEAR.\n";

  Player PlayerTwo("Link", 4);
  cout << "Welcome " << PlayerTwo.Name << ". Hope you can save us.\n";

  Enemy EnemyOne("Witch King", 1);
  cout << "Oh no, it's " << EnemyOne.EnemyName << "!\n";

  PlayerTwo.GetAttacked(EnemyOne);
}