#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void Pass() {

	
	int money;
	int honesty = 90;
	int random = 1 + rand() % 100;

	int bribePrice = 500;

	string name;
	string hasPassAnswer;

	cout << "Как тебя зовут, Сталкер?\n";
	cin >> name;

	cout << "Привет." << name << "есть пропуск? (да/нет)\n";

	cin >> hasPassAnswer;

	if (hasPassAnswer == "Да" || hasPassAnswer == "да") {

		cout << "проходи," << name << "!" << endl;

	}
	else {
		if (random <= honesty) {
			cout << "пропуска нет. Сколько у тебя денег?\n";
			cin >> money;

			if (money >= bribePrice) {
				cout << "Ты заплатил " << bribePrice << " Монет. Охранник пропускает." << endl;

			}
			else {
				cout << "не хватает денег. Охранник закрывает проход" << endl;

			}
		}
		else {

			cout << "пропуска нет, уходи.";
		}

	}

}

void Randomizer() {

	int number;
	int random = 1 + rand() % 100;
	int honestran = 1 + rand() % 100;
	for (int i = 0; i < 5;i++) {
		int honesty = 30;
		cout << "Введите проверочное число,чтобы потвердить личность\n";
		cin >> number;
		if (honestran >= honesty) {

			if (number == random) {
				cout << "Личность потверждена. Добро пожаловать!\n";
				break;
			}
			else if (number < random) {

				cout << "Не верно.Число больше указанного вами\n";

			}
			else if (random < number) {

				cout << "Не верно.Число меньше указанного вами\n";
			}
		}
		else if (honestran <= honesty) {

			if (number == random) {
				cout << "Личность потверждена. Добро пожаловать!\n";
				break;
			}
			else if (number < random) {

				cout << "Не верно.Число меньше указанного вами\n";

			}
			else if (random < number) {

				cout << "Не верно.Число больше указанного вами\n";
			}

		}
	
	}
	cout << "Число терминала: "<< random;

}

void RPG() {
	
	struct Unit {
		string name;
		int HP;
		int dmg;
	};

	//Иницализация данных

	Unit character[3];
	character[0].name = "Sworder";
	character[0].dmg = 10;
	character[0].HP = 100;

	character[1].name = "Horseman";
	character[1].dmg = 10;
	character[1].HP = 100;

	character[2].name = "Archer";
	character[2].dmg = 10;
	character[2].HP = 100;

	//Логика даных

	
	cout << "Правила игры:\n В игре 3 юнита: Мечник, Лучник, Всадник.\nМечник силен против Лучника\nЛучник силен против Всадника.\nВсадник силен против Мечника\n\n";
		

	for (int i = 0; i < 3;i++) {

		cout << character[i].name << "\t";
		cout << "Урон: " << character[i].dmg << "\t";
		cout << "Здоровье: " << character[i].HP << "\n";
	}

	cout << "Выберите персонажа для дальнейшей игры\n\n";
	string name;
	cin >> name;
	int random = rand()% 3;
	string bot = character[random].name;
	cout << bot << "\n";

	if (name == character[0].name && bot == character[2].name) {

		character[0].dmg *= 1.5f;
	}
	else if (name == character[0].name && bot == character[1].name) {

		character[1].dmg *= 1.5f;
	}
	else if (name == character[1].name && bot == character[0].name) {

		character[1].dmg *= 1.5f;
	}

	else if (name == character[2].name && bot == character[0].name) {
		character[0].dmg *= 1.5f;
	}
	else if (name == character[1].name && bot == character[2].name) {
		character[2].dmg *= 1.5f;
	}
	
	else if (name == character[2].name && bot == character[1].name) {
		character[2].dmg *= 1.5f;
	}

	cout << "Урон мечника" << character[0].dmg << "\n";
	cout << "Урон всадника" << character[1].dmg << "\n";
	cout << "Урон лучника" << character[2].dmg << "\n";


}

int main()  {
	system("chcp 65001");
	setlocale(LC_ALL, "ru_RU.UTF-8");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));
	//Randomizer();
	//Pass();
	RPG();
}