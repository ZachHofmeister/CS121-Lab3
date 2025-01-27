/*
	Zach Hofmeister		2/21/19
	Lab 3: Classes		Virtual Pet: Program demonstrates understanding and use of classes.
						Player takes care of a megasloth until it dies of old age or neglect.
*/

#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class Megasloth {
	private: //Megasloth stats are private
		string name;
		int hunger, clean, happy, health, age;
	public: //Public constructor and functions
		Megasloth(string n) { //Constructor
			name = n;
			age = 0;
			hunger = rand() % 5 + 1;
			clean = rand() % 5 + 1;
			happy = rand() % 5 + 1;
			health = rand() % 5 + 1;
		}
		int getAge() { //getter for age
			return age;
		}
		void displayAttributes() { //Prints attributes
			cout << endl << endl;
			cout << "--" << name << "'s stats--" << endl;
			cout << "Hunger: " << hunger << endl;
			cout << "Cleanliness: " << clean << endl;
			cout << "Happiness: " << happy << endl;
			cout << "Health: " << health << endl;
			cout << "Age: " << age << endl;
		}
		void feed() { //Increase hunger
			age++;
			hunger++;
			switch ((int)(rand() % 2)) { //Decreases a stat at random each action
				case 0:
					clean--;
					break;
				case 1:
					happy--;
					break;
				case 2:
					health--;
					break;
			}
			cout << name << " eats a big bowl of leaves." << endl;
		}
		void wash() { //Increase cleanliness
			age++;
			clean++;
			switch ((int)(rand() % 2)) { //Decreases a stat at random each action
				case 0:
					hunger--;
					break;
				case 1:
					happy--;
					break;
				case 2:
					health--;
					break;
			}
			cout << name << " splashes in the bath." << endl;
		}
		void play() { //Increase happiness
			age++;
			happy++;
			switch ((int)(rand() % 2)) { //Decreases a stat at random each action
				case 0:
					clean--;
					break;
				case 1:
					hunger--;
					break;
				case 2:
					health--;
					break;
			}
			cout << name << " plays happily." << endl;
		}
		void heal() { //Increases health
			age++;
			health++;
			switch ((int)(rand() % 2)) { //Decreases a stat at random each action
				case 0:
					clean--;
					break;
				case 1:
					happy--;
					break;
				case 2:
					hunger--;
					break;
			}
			cout << name << " takes their vitamins reluctantly." << endl;
		}
		bool isAlive() { //Checks if megasloth's stats are at the right levels for life.
			if (age >= 5 || hunger <= 0 || clean <= 0 || happy <= 0 || health <= 0) {
				return false;
			} else {
				return true;
			}
		}
};

void displayMenu(Megasloth&); //Displays choices and takes player's selection for interaction. Pass sloth by reference to change original values.

int main() {
	srand(time(0));
	cout << "===================" << endl;
	cout << "=Virtual Megasloth=" << endl;
	cout << "===================" << endl;

	cout << "Please enter a name for your pet Megasloth: " << endl;
	string name;
	getline(cin, name);
	Megasloth sloth(name); //Creates object with constructor.

	do { //Loop for menu.
		sloth.displayAttributes();
		displayMenu(sloth);
	} while (sloth.isAlive()); //Game ends when megasloth dies.

	sloth.displayAttributes();
	if (sloth.getAge() >= 5) {
		cout << name << " has died of old age.";
	} else {
		cout << name << " has died tragically.";
	}

	return 0;
}

void displayMenu(Megasloth &sloth) { //Displays choices and takes player's selection for interaction. Pass sloth by reference to change original values.
	int choice;
	cout << "Main menu:" << endl;
	cout << "1. Feed" << endl;
	cout << "2. Wash" << endl;
	cout << "3. Play" << endl;
	cout << "4. Health" << endl;

	cout << "Enter a number (1-4): ";
	cin >> choice;

	if (choice == 1) {
		sloth.feed();
	} else if (choice == 2) {
		sloth.wash();
	} else if (choice == 3) {
		sloth.play();
	} else if (choice == 4) {
		sloth.heal();
	} else { //Invalid input
		cout << "Please enter a number 1-4." << endl << endl;
		displayMenu(sloth);
	}
}

/*
=========================================================
SAMPLE OUTPUT 1
=========================================================

===================
=Virtual Megasloth=
===================
Please enter a name for your pet Megasloth:
Henry


--Henry's stats--
Hunger: 5
Cleanliness: 3
Happiness: 2
Health: 3
Age: 0
Main menu:
1. Feed
2. Wash
3. Play
4. Health
Enter a number (1-4): 3
Henry plays happily.


--Henry's stats--
Hunger: 5
Cleanliness: 2
Happiness: 3
Health: 3
Age: 1
Main menu:
1. Feed
2. Wash
3. Play
4. Health
Enter a number (1-4): 2
Henry splashes in the bath.


--Henry's stats--
Hunger: 4
Cleanliness: 3
Happiness: 3
Health: 3
Age: 2
Main menu:
1. Feed
2. Wash
3. Play
4. Health
Enter a number (1-4): 4
Henry takes their vitamins reluctantly.


--Henry's stats--
Hunger: 4
Cleanliness: 2
Happiness: 3
Health: 4
Age: 3
Main menu:
1. Feed
2. Wash
3. Play
4. Health
Enter a number (1-4): 2
Henry splashes in the bath.


--Henry's stats--
Hunger: 4
Cleanliness: 3
Happiness: 2
Health: 4
Age: 4
Main menu:
1. Feed
2. Wash
3. Play
4. Health
Enter a number (1-4): 3
Henry plays happily.


--Henry's stats--
Hunger: 3
Cleanliness: 3
Happiness: 3
Health: 4
Age: 5
Henry has died of old age.
C:\Users\zachh\Documents\GitHub\CS121 Lab3\Debug\CS121 Lab3.exe (process 13200) exited with code 0.
Press any key to close this window . . .
=========================================================
SAMPLE OUTPUT 2
=========================================================

===================
=Virtual Megasloth=
===================
Please enter a name for your pet Megasloth:
Henry II


--Henry II's stats--
Hunger: 5
Cleanliness: 1
Happiness: 4
Health: 1
Age: 0
Main menu:
1. Feed
2. Wash
3. Play
4. Health
Enter a number (1-4): 1
Henry II eats a big bowl of leaves.


--Henry II's stats--
Hunger: 6
Cleanliness: 1
Happiness: 3
Health: 1
Age: 1
Main menu:
1. Feed
2. Wash
3. Play
4. Health
Enter a number (1-4): 1
Henry II eats a big bowl of leaves.


--Henry II's stats--
Hunger: 7
Cleanliness: 0
Happiness: 3
Health: 1
Age: 2
Henry II has died tragically.
C:\Users\zachh\Documents\GitHub\CS121 Lab3\Debug\CS121 Lab3.exe (process 16864) exited with code 0.
Press any key to close this window . . .
*/