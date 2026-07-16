#include <iostream>
#include <string>

using namespace std;

// Unit structure
struct Unit {
    string name;
    int dmg;
}; 

void RPG() {

    struct Ruler {
        int HP=500;
    };

    Ruler KingPlayer;
    Ruler KingBot;

    const int UNIT_COUNT = 4;
    Unit units[UNIT_COUNT];

    units[0].name = "Swordsman";
    units[0].dmg = 100;

    units[1].name = "Horseman";
    units[1].dmg = 100;

    units[2].name = "Archer";
    units[2].dmg = 100;

    units[3].name = "Spearman";
    units[3].dmg = 100;

    // Balance table (4x4 matrix)
    // 1 = first unit is stronger against second unit
    int balance[UNIT_COUNT][UNIT_COUNT] = {
        //           Swordsman  Horseman  Archer  Spearman
        /*Swordsman*/ {0,        0,        1,      1},    // Swordsman > Archer and Spearman
        /*Horseman*/  {1,        0,        0,      0},    // Horseman > Swordsman
        /*Archer*/    {0,        1,        0,      1},    // Archer > Horseman and Spearman
        /*Spearman*/  {0,        1,        0,      0}     // Spearman > Horseman
    };

    // Unit names array
    string unitNames[UNIT_COUNT];
    for (int i = 0; i < UNIT_COUNT; i++) {
        unitNames[i] = units[i].name;
    }

    // Show rules
    cout << "=== GAME RULES ===" << endl;
    cout << "4 units: Swordsman, Horseman, Archer, Spearman" << endl;
    cout << endl;

    // Show balance from table
    cout << "Balance:" << endl;
    for (int i = 0; i < UNIT_COUNT; i++) {
        cout << units[i].name << " is strong against: ";
        bool hasAdvantage = false;
        for (int j = 0; j < UNIT_COUNT; j++) {
            if (balance[i][j] == 1) {
                cout << units[j].name << " ";
                hasAdvantage = true;
            }
        }
        if (!hasAdvantage) cout << "none";
        cout << endl;
    }
    cout << endl;

    for (int z = 0; z < 5; z++) {

        // Show all units with stats
        cout << "=== UNITS ===" << endl;
        for (int i = 0; i < UNIT_COUNT; i++) {
            cout << i + 1 << ". " << units[i].name << "\t";
            cout << "Damage: " << units[i].dmg << endl;
        }
        cout << endl;

        // Player selects unit
        cout << "Select your unit (enter number 1-4): ";
        int playerChoice;
        cin >> playerChoice;
        playerChoice--; // convert to 0-based index

        if (playerChoice < 0 || playerChoice >= UNIT_COUNT) {
            cout << "Invalid choice!" << endl;
            return;
        }


        // Bot selects random unit
        int botChoice = rand() % UNIT_COUNT;
        cout << "Bot selected: " << botChoice + 1 << " " << units[botChoice].name << "\n\n";


        // Check balance table to find winner
        int playerIdx = playerChoice;
        int botIdx = botChoice;

        // Determine result using balance table
        if (balance[playerIdx][botIdx] == 1) {
            // Player is stronger
            units[playerIdx].dmg *= 1.5;
            cout << "YOUR Unit!\n " << units[playerIdx].name << " is stronger against\n "
                << units[botIdx].name << "!" << endl;
            cout << "Damage boosted to: " << units[playerIdx].dmg << endl;
        }
        else if (balance[botIdx][playerIdx] == 1) {
            // Bot is stronger
            units[botIdx].dmg *= 1.5;
            cout << "BOT Unit!\n " << units[botIdx].name << " is stronger against "
                << units[playerIdx].name << "!" << endl;
            cout << "Bot damage boosted to: " << units[botIdx].dmg << endl;
        }

        if (units[botIdx].dmg >= KingPlayer.HP && units[playerIdx].dmg >= KingBot.HP) {
            KingPlayer.HP -= units[botIdx].dmg;
            KingBot.HP -= units[playerIdx].dmg;
            KingPlayer.HP = 0;
            KingBot.HP = 0;
        }
        else if (units[botIdx].dmg >= KingPlayer.HP) {
            KingBot.HP -= units[playerIdx].dmg;
            KingPlayer.HP = 0;
        }
        else if (units[playerIdx].dmg >= KingBot.HP) {
            KingPlayer.HP -= units[botIdx].dmg;
            KingBot.HP = 0;
        }
        else {
        
            KingPlayer.HP -= units[botIdx].dmg;
            KingBot.HP -= units[playerIdx].dmg;

        }

        units[botIdx].dmg = 100;
        units[playerIdx].dmg = 100;

        cout << "Player health\t " << KingPlayer.HP << "\n";
        cout << "Bot health\t " << KingBot.HP << "\n";


        if (KingPlayer.HP <= 0 && KingBot.HP <= 0) {
            cout << "DRAW! Equal strength!" << endl;
            
            break;
        }
        else if (KingPlayer.HP <= 0 || z == 5 && KingPlayer.HP < KingBot.HP) {
            cout << "Bot win!H@H@H@";
           
            break;

        }
        else if (KingBot.HP <= 0 || z== 5 && KingPlayer.HP > KingBot.HP) {
            cout << "you win!Great Job!";
           
            break;
        }
    }


    // Проверка на итоги игры 
    
    // Show final stats
    cout << endl << "=== FINAL STATS ===" << endl;
    for (int i = 0; i < UNIT_COUNT; i++) {
        cout << units[i].name << " - Damage: " << units[i].dmg << endl;
    }
}

int main() {
    srand(time(0));
    //RPG();

}

void Economy() {
    struct Player {
        int inventory = 15;
        int money = 400;
    };

    struct loot {

        int cost;
        int weight;
        string name;
    };

    loot Shop[3];

    Shop[0].name = "Potion";
    Shop[0].cost = 50;
    Shop[0].weight = 1;

    Shop[1].name = "Sword";
    Shop[1].cost = 300;
    Shop[1].weight = 10;

    Shop[2].name = "Shield";
    Shop[2].cost = 250;
    Shop[2].weight = 8;

    // Сделать логику покупки с выводом всех параметров
}