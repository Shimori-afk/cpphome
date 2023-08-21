#include <iostream>
#include <string>

class Team;

class Player {
public:
    Player(const std::string& name, int health, const std::string& playerClass, const std::string& weapon)
        : name(name), health(health), playerClass(playerClass), weapon(weapon), team(nullptr) {}

    void setTeam(Team* team);

    void printPlayerInfo() const;

private:
    std::string name;
    int health;
    std::string playerClass;
    std::string weapon;
    Team* team;
};

class Team {
public:
    Team(const std::string& name, int maxPlayers) : name(name), maxPlayers(maxPlayers), numPlayers(0) {
        players = new Player*[maxPlayers];
    }

    ~Team() {
        delete[] players;
    }

    const std::string& getName() const {
        return name;
    }

    void addPlayer(Player* player) {
        if (numPlayers < maxPlayers) {
            players[numPlayers++] = player;
            player->setTeam(this);
        } else {
            std::cout << "Team is full. Cannot add more players.\n";
        }
    }

    void removePlayer(Player* player) {
        for (int i = 0; i < numPlayers; ++i) {
            if (players[i] == player) {
                player->setTeam(nullptr);
                players[i] = nullptr;
                for (int j = i; j < numPlayers - 1; ++j) {
                    players[j] = players[j + 1];
                }
                players[numPlayers - 1] = nullptr;
                --numPlayers;
                break;
            }
        }
    }

    void printTeamInfo() const {
        std::cout << "Team: " << name << "\n";
        std::cout << "Number of Players: " << numPlayers << "\n";
        for (int i = 0; i < numPlayers; ++i) {
            players[i]->printPlayerInfo();
            std::cout << "\n";
        }
    }

private:
    std::string name;
    int maxPlayers;
    int numPlayers;
    Player** players;
};

void Player::setTeam(Team* team) {
    this->team = team;
}

void Player::printPlayerInfo() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Class: " << playerClass << "\n";
    std::cout << "Weapon: " << weapon << "\n";
    if (team) {
        std::cout << "Team: " << team->getName() << "\n";
    } else {
        std::cout << "Team: None\n";
    }
}

int main() {
    Player player1("John", 100, "Warrior", "Sword");
    Player player2("Jane", 90, "Mage", "Staff");

    Team teamA("Team A", 2);
    Team teamB("Team B", 2);

    teamA.addPlayer(&player1);
    teamB.addPlayer(&player2);

    player1.printPlayerInfo();
    std::cout << "\n";
    player2.printPlayerInfo();
    std::cout << "\n";

    teamA.printTeamInfo();
    std::cout << "\n";
    teamB.printTeamInfo();

    return 0;
}
