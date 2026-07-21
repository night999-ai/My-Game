#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <cstring>
#include <cstdlib>

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

void Economy() {
  
   int gold = 400;
   int maxWeight = 15;
  
  
   int potionCost = 50;
   int potionWeight = 1;
  
   int swordCost = 300;
   int swordWeight = 10;
  
   int shieldCost = 250;
   int shieldWeight = 8;
  
  
   int needPotions = 2;
   int needSwords = 1;
   int needShields = 0;
  
   int totalCost = needPotions * potionCost + needSwords * swordCost;
   int totalWeight = needPotions * potionWeight + needSwords * swordWeight;
  
   cout << "=== Проверка покупки: 2 зелья и меч ===" << endl;
   cout << "Нужно денег: " << totalCost << " (есть " << gold << ")" << endl;
   cout << "Нужно веса: " << totalWeight << " (макс " << maxWeight << ")" << endl;
  
   if (totalCost <= gold && totalWeight <= maxWeight) {
       cout << "Да, хватит и денег, и места!" << endl;
   }
   else {
       cout << "Нет, не хватит:" << endl;
       if (totalCost > gold) cout << "- Не хватает золота!" << endl;
       if (totalWeight > maxWeight) cout << "- Слишком тяжело!" << endl;
   }
  
   cout << endl;
  
   // ===== Задание 2: оптимизация – потратить максимум денег в пределах веса =====
   int maxPotionsByWeight = maxWeight / potionWeight; // 15/1 = 15
   int maxPotionsByGold = gold / potionCost;          // 400/50 = 8
   int maxPotions = maxPotionsByWeight < maxPotionsByGold ? maxPotionsByWeight : maxPotionsByGold; // 8
  
   int maxSwordsByWeight = maxWeight / swordWeight;  // 15/10 = 1
   int maxSwordsByGold = gold / swordCost;           // 400/300 = 1
   int maxSwords = maxSwordsByWeight < maxSwordsByGold ? maxSwordsByWeight : maxSwordsByGold; // 1
  
   int maxShieldsByWeight = maxWeight / shieldWeight; // 15/8 = 1
   int maxShieldsByGold = gold / shieldCost;          // 400/250 = 1
   int maxShields = maxShieldsByWeight < maxShieldsByGold ? maxShieldsByWeight : maxShieldsByGold; // 1
  
   int bestCost = 0;
   int bestPotions = 0;
   int bestSwords = 0;
   int bestShields = 0;
  
   for (int p = 0; p <= maxPotions; p++) {
       for (int s = 0; s <= maxSwords; s++) {
           for (int sh = 0; sh <= maxShields; sh++) {
               int cost = p * potionCost + s * swordCost + sh * shieldCost;
               int weight = p * potionWeight + s * swordWeight + sh * shieldWeight;
  
  
               if (weight <= maxWeight && cost <= gold && cost > bestCost) {
                   bestCost = cost;
                   bestPotions = p;
                   bestSwords = s;
                   bestShields = sh;
               }
           }
       }
   }
  
   cout << "=== Оптимальная покупка (максимум потраченных денег) ===" << endl;
   cout << "Куплено:" << endl;
   cout << "Зелий здоровья: " << bestPotions << " шт. (вес " << bestPotions * potionWeight
       << ", цена " << bestPotions * potionCost << ")" << endl;
   cout << "Мечей: " << bestSwords << " шт. (вес " << bestSwords * swordWeight
       << ", цена " << bestSwords * swordCost << ")" << endl;
   cout << "Щитов: " << bestShields << " шт. (вес " << bestShields * shieldWeight
       << ", цена " << bestShields * shieldCost << ")" << endl;
   cout << "Общий вес: " << (bestPotions * potionWeight + bestSwords * swordWeight + bestShields * shieldWeight)
       << " (лимит " << maxWeight << ")" << endl;
   cout << "Потрачено золота: " << bestCost << " (было " << gold << ")" << endl;
   cout << "Осталось золота: " << gold - bestCost << endl;
  

  
}
void Tree() {

    struct Skill {
        string name;
        string desc;
        int branch;// 1 -  2 - 3 -
        int cost;
        int level;
    };
    vector<Skill> AllSkills;
    AllSkills.push_back({"Огненый_Шар","Создаёт испепеляющий шар огня",3,1,1});// Магия
    AllSkills.push_back({ "Пламенная_стрела","Выпускает стрелу пламени уничтожающую всё на своём пути",3,2 });
    AllSkills.push_back({ "Шторм_пламени","призывает шторм пламени сжигающий всё и вся",5,3 });

    AllSkills.push_back({ "Магия_Воды","позволяет призывать воду и контроллировать её",1,1 });
    AllSkills.push_back({ "Продвинутаямагия_Воды","Углубляет понимание в магии позволяя создавать больше воды и проще её контролировать",2,2 });
    AllSkills.push_back({ "Струя_воды","Создаёт струю воды под высоким давлением способную разрезать даже сталь",3,3 });
    AllSkills.push_back({ "Копья_Льда","Создаёт и запускает множество копий изо льда",3,3 });
    AllSkills.push_back({ "Посейдон!","призывает аватар бога морей!Что сметает всех врагов творих",5,4 });
    AllSkills.push_back({ "глыба_льда","Создаёт гигантскую глыбу льда,что летит на врагов",5,4 });


  

}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    //RPG();
    //Economy();
}
