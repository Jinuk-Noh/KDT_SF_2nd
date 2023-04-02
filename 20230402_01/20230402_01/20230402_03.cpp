#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Weapon {
	int power;
	int attack_cnt;
	string name;
public:
	Weapon(int power, int attack_cnt, string name) {
		this->power = power;
		this->attack_cnt = attack_cnt;
		this->name = name;
	}

	int get_power() {
		return this->power;
	}

	int get_attack_cnt() {
		return this->attack_cnt;
	}

	string get_name() {
		return this->name;
	}

	void used() {
		this->attack_cnt = this->attack_cnt - 1 < 0 ? 0 : this->attack_cnt-1;
	}

	virtual void attack() {

	}

	virtual ~Weapon() {

	};

};

class Sword: public Weapon {
public:

	Sword() :Weapon(5,3, "��") {

	}

	void attack() {
		cout << "���" << endl;
	}
};

class Gun: public Weapon {
public:
	Gun() :Weapon(10, 1,"��") {

	}

	void attack() {
		cout << "�� ���" << endl;
	}
};


class Character {
	int hp;
	int level;

	Weapon* have_weapon;

public:
	Character() {
		this->hp = 100;
		this->level = 1;
	}

	~Character() {
		if (have_weapon != nullptr)
			delete have_weapon;
	}

	void attack() {

		if (have_weapon == nullptr) {
			cout << "���⸦ ������ ���� �ʽ��ϴ�." << endl;
			return;
		}

		if (have_weapon->get_attack_cnt() == 0) {
			cout << "���� �������� ���� ������ �������ϴ�." << endl;
		}
		else {
			have_weapon->attack();
		}
	}

	void getWeapone(Weapon* weapon) {
		if (have_weapon != nullptr) {
			delete have_weapon;
			cout << "���� ���⸦ �����ϴ�."<<endl;
		}

		cout << "���� �ݱ�"<<endl;
		this->have_weapon = weapon;
	}

	Weapon* get_have_weapon() {
		return this->have_weapon;
	}

	void attacked(Weapon* weapon) {
		if (weapon->get_attack_cnt() > 0) {
			hp = hp - weapon->get_power();
		}
	}

	void show_info() {
		cout << "���� HP : " << this->hp << endl;
	}

	void show_main_ch_info() {
		cout << "���� HP : " << this->hp << endl;

		if (have_weapon != nullptr) {
			cout << "���� ���� : " << this->get_have_weapon()->get_name() << endl;
			cout << "���� ������ : " << this->get_have_weapon()->get_attack_cnt() << endl;
		}

	}
};

int main() {

	int action = 0;
	int weapon = 0;
	int target = 0;
	vector<Character*> enemies;
	Character mainCh;

	while (true) {
		cout << endl<<"1 : ������/ 2 : ���� ����/ 3 : ����/ 4 : �� ����/ 5 :���� �� ���� / 6 : ���� / 0 : ����" << endl;
		cin >> action;

		switch (action)
		{
		case 1:
			cout << enemies.size() + 1 << "�� ���� �����մϴ�." << endl;
			enemies.push_back(new Character());
			cout << "���� ���� ���� �Դϴ�. : " << enemies.size() << "��" << endl;
			break;
		case 2:
			while (true) {
				cout << "���⸦ ������ �ּ��� (1 : ��, 2 : ��) : ";
				cin >> weapon;
				if (weapon == 1) {					
					mainCh.getWeapone(new Sword());
					break;
				}
				else if (weapon == 2) {
					mainCh.getWeapone(new Gun());
					break;
				}
				else {
					cout << "1�� �Ǵ� 2���� �Է��ϼ���."<<endl;
				}
			}
			break;
		case 3:
			if (enemies.size() > 0) {
				cout << "������ ����� �Է��ϼ��� 1 ~" << enemies.size() << endl;
	
				cin >> target;
				if (target < 1 || target > enemies.size()) {
					cout << "���� ����� �����ϴ�.";
				}
				else {
					mainCh.attack();
					enemies[target - 1]->attacked(mainCh.get_have_weapon());
					mainCh.get_have_weapon()->used();
				}
			}
			else {
				cout << "���� ����� �����ϴ�. 1�� �Է��Ͽ� ���� �����ϼ���" << endl;
			}
			break;
		case 4:
			if(enemies.size() > 0) {
				cout << "Ȯ���� ����� �Է��ϼ��� 1 ~" << enemies.size() << endl;

				cin >> target;
				if (target < 1 || target > enemies.size()) {
					cout << "Ȯ�� ����� �����ϴ�.";
				}
				else {
					
					enemies[target - 1]->show_info();
				}
			}
			else {
				cout << "Ȯ�� ����� �����ϴ�. 1�� �Է��Ͽ� ���� �����ϼ���" << endl;
			}
			break;
		case 5:
			mainCh.show_main_ch_info();
			break;
		case 6: cout << "1 : ������/ 2 : ���� ����/ 3 : ����/ 4 : �� ����/ 5 :���� �� ���� / 6 : ���� / 0 : ����" << endl << endl;
			break;
		case 0:
			break;
		default: cout << "6�� �Է��Ͽ� ��ɾ Ȯ���ϼ���" << endl;
			break;
		}


		if (action == 0) {
			cout << "����" << endl;
			break;
		}

	}




}