#include <iostream>
#include <string>

using namespace std;

class Hero{

    private:
        // Define all the attributes here...
        // [ your code ]
        string name;
        int health;
        int armor;
        int power;
        string weapon;
    public:
        // Define the constructor and methods here ...
        Hero(string name, int health, int armor, int power, string weapon): name(name), health(health), armor(armor), power(power), weapon(weapon) {}
    void info(){
            // process display hero info here...
            // [ your code ]
            cout << "Name: " << name << endl;
            cout << "Health: " << health << endl;
            cout << "Armor: " << armor << endl;
            cout << "Power: " << power << endl;
            cout << "Weapon: " << weapon << endl;
            cout << endl;
        }
    void strike(Hero& enemy){
            // process the strike logic here...
            // you can add the narative text as well (optional)
            // [ your code ]
            int damage = power - enemy.armor;
            if (damage<0) damage = 0;

            bool armorIntact = enemy.armor>0;
            enemy.armor -= power;
            if (enemy.armor<0) enemy.armor = 0;
            bool armorBroken = (enemy.armor==0)&&armorIntact;
            
            enemy.health -= damage;
            if (enemy.health<0) enemy.health = 0;

            if (armorBroken) {
                cout << name << " has broken " << enemy.name << "'s armor and has dealt " << damage << " damage to " << enemy.name << "!\n" << endl;
            } else if (enemy.armor>0) {
                 cout << name << " has dealt " << power << " damage to " << enemy.name << "'s armor!\n"<< endl;
            } else {
                cout << name << " has hit " << enemy.name << " for " << damage << " damage!\n" << endl;
            }
            
        }
    string getName() {
            // this won't eerror when you create the name attribute
            return name;
        }
    // getter methods
        int getHealth() {
            // this won't error when you create the health attribute
            return health;
        }

        int getArmor() {
            // this won't error when you create the armor attribute
            return armor;
        }

        int getPower() {
            // this won't error when you create the power attribute
            return power;
        }
