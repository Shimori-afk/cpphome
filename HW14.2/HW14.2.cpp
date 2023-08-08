#include <iostream>
#include <string>

class Weapon
{
public:
    Weapon(const std::string& name, int damage, int range) : name(name), damage(damage), range(range) {}

    std::string getName() const 
	{
        return name;
    }

    int getDamage() const
	{
        return damage;
    }

    int getRange() const
	{
        return range;
    }

private:
    std::string name;
    int damage;
    int range;
};

class Player 
{
public:
    Player(const std::string& name, int health, const std::string& playerClass) : name(name), health(health), playerClass(playerClass), weapon(nullptr) {}

    void addWeapon(const Weapon& weapon) 
	{
        this -> weapon = &weapon;
    }

    void showWeapons() const 
	{
        if (weapon != nullptr) 
		{
            std::cout << name << "'s Weapon:\n";
            std::cout << " - " << weapon -> getName() << " (Damage: " << weapon -> getDamage() << ", Range: " << weapon -> getRange() << ")\n";
        } else
		{
            std::cout << name << " has no weapon.\n";
        }
    }

private:
    std::string name;
    int health;
    std::string playerClass;
    const Weapon* weapon;
};

int main() 
{
    Player player1("John", 100, "assault");
    Player player2("Emily", 90, "sniper");

    Weapon weapon1("AK-47", 30, 200);
    Weapon weapon2("M16", 25, 180);
    Weapon weapon3("AWP", 70, 500);
    Weapon weapon4("Medkit", 0, 0);

    player1.addWeapon(weapon1);
    player1.addWeapon(weapon2);
    player2.addWeapon(weapon3);
    player2.addWeapon(weapon4);

    player1.showWeapons();
    player2.showWeapons();

    return 0;
}
