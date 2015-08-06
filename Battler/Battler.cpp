#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main()
{
	int menuSelect;

	menuSelect = 2;

	cout << "Enter 1-3 to choose a class" << endl;
	cout << "1) Warrior" << endl;
	cout << "2) Mage" << endl;
	cout << "3) Monster" << endl;

	cin >> menuSelect;

	if (menuSelect == 1)
	{
		cout << "You have Selected: Warrior";
		cout << endl;
		cout << "sub-classes:" << endl;
		cout << "1) Knight" << endl;
		cout << "2) Assasin" << endl;
		cout << "3) Ranger" << endl;
		cin >> menuSelect;
	}
	else if (menuSelect == 2)
	{
		cout << "You have selected: Mage" << endl;
		cout << "sub-classes:" << endl;
		cout << "1) Magician" << endl;
		cout << "2) Wizard" << endl;
		cout << "3) Enchanter" << endl;
		cin >> menuSelect;
	}
	else if (menuSelect == 3)
	{
		cout << "You have selected: Demon" << endl;
		cout << "sub-classes:" << endl;
		cout << "1) Demon" << endl;
		cout << "2) Wraith" << endl;
		cout << "3) Wyrm" << endl;
		cin >> menuSelect;
	}
	else
	{
		cout << "Code cannot handle this input" << endl;
	}
	cout << endl;

	srand(time(NULL));

	int playerHP = 20;
	int enemyHP = 20;

	int attackDamage[3] = { 4, 5, 2 };
	int attackHitChance[3] = { 50, 40, 100 };

	while (true)
	{
		int playerChoice;
		int hitRoll = rand() % 100;
		cout << "Choose an attack 1-3:" << endl;
		cout << "1) Sword Strike" << endl;
		cout << "2) wind Blade" << endl;
		cout << "3) Luminous Slash" << endl;

		cin >> playerChoice;

		switch (playerChoice)
		{
		case 1:
			cout << "You swing your sword expertly and strike at the center with all your might!" << endl;
			break;
		case 2:
			cout << "You swing your sword, as you swing it seems your swords grows in length and sharpens by 50%" << endl;
			break;
		case 3:
			cout << "Your Sword sucks in light til you stand ontop a patch of darkened grass, your sword begins to glow, then you swing your sword and it lets out a wave of energy!" << endl;
			break;
		default:
			cout << "You trip over your own feet and end up losing your turn!" << endl;
		}

		if (attackHitChance[playerChoice - 1] < hitRoll)
		{
			cout << "your enemy was hit!" << endl;
			enemyHP -= attackDamage[playerChoice - 1];
		}
		else
		{
			cout << "You missed!" << endl;
		}

		int enemyChoice = rand() % 3;
		hitRoll = rand() % 100;

		switch (enemyChoice)
		{
		case 0:
			cout << "Your enemy recklessly runs at your screaming as he raises his sword" << endl;
			break;
		case 1:
			cout << "Your enemy shoots a weak fireball at you." << endl;
			break;
		case 2:
			cout << "Your enemy suddenly uses an advanced magic to disapear and reapear beside you." << endl;
			break;
		}

		if (attackHitChance[enemyChoice] < hitRoll)
		{
			cout << "He hits you!" << endl;
			playerHP -= attackDamage[enemyChoice];
		}
		else
		{
			cout << "He misses!" << endl;
		}

		cout << endl;
		cout << "your health is currently " << playerHP << "/20" << endl;
		cout << "Enemy health is currently " << enemyHP << "/20" << endl;
		if (playerHP < 1)
		{
			cout << "You lose!" << endl;
			break;
		}
		if (enemyHP < 1)
		{
			cout << "You Win!" << endl;
			break;
		}
	}
	return 0;
}