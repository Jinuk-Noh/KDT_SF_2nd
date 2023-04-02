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

	Sword() :Weapon(5,3, "검") {

	}

	void attack() {
		cout << "찌르기" << endl;
	}
};

class Gun: public Weapon {
public:
	Gun() :Weapon(10, 1,"총") {

	}

	void attack() {
		cout << "총 쏘기" << endl;
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
			cout << "무기를 가지고 있지 않습니다." << endl;
			return;
		}

		if (have_weapon->get_attack_cnt() == 0) {
			cout << "무기 내구도가 없어 공격할 수없습니다." << endl;
		}
		else {
			have_weapon->attack();
		}
	}

	void getWeapone(Weapon* weapon) {
		if (have_weapon != nullptr) {
			delete have_weapon;
			cout << "기존 무기를 버립니다."<<endl;
		}

		cout << "무기 줍기"<<endl;
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
		cout << "현재 HP : " << this->hp << endl;
	}

	void show_main_ch_info() {
		cout << "현재 HP : " << this->hp << endl;

		if (have_weapon != nullptr) {
			cout << "현재 무기 : " << this->get_have_weapon()->get_name() << endl;
			cout << "무기 내구도 : " << this->get_have_weapon()->get_attack_cnt() << endl;
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
		cout << endl<<"1 : 적생성/ 2 : 무기 선택/ 3 : 공격/ 4 : 적 상태/ 5 :현재 내 상태 / 6 : 도움말 / 0 : 종료" << endl;
		cin >> action;

		switch (action)
		{
		case 1:
			cout << enemies.size() + 1 << "번 적을 생성합니다." << endl;
			enemies.push_back(new Character());
			cout << "현재 적의 숫자 입니다. : " << enemies.size() << "명" << endl;
			break;
		case 2:
			while (true) {
				cout << "무기를 선택해 주세요 (1 : 검, 2 : 총) : ";
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
					cout << "1번 또는 2번을 입력하세요."<<endl;
				}
			}
			break;
		case 3:
			if (enemies.size() > 0) {
				cout << "공격할 대상을 입력하세요 1 ~" << enemies.size() << endl;
	
				cin >> target;
				if (target < 1 || target > enemies.size()) {
					cout << "공격 대상이 없습니다.";
				}
				else {
					mainCh.attack();
					enemies[target - 1]->attacked(mainCh.get_have_weapon());
					mainCh.get_have_weapon()->used();
				}
			}
			else {
				cout << "공격 대상이 없습니다. 1을 입력하여 적을 생성하세요" << endl;
			}
			break;
		case 4:
			if(enemies.size() > 0) {
				cout << "확인할 대상을 입력하세요 1 ~" << enemies.size() << endl;

				cin >> target;
				if (target < 1 || target > enemies.size()) {
					cout << "확인 대상이 없습니다.";
				}
				else {
					
					enemies[target - 1]->show_info();
				}
			}
			else {
				cout << "확인 대상이 없습니다. 1을 입력하여 적을 생성하세요" << endl;
			}
			break;
		case 5:
			mainCh.show_main_ch_info();
			break;
		case 6: cout << "1 : 적생성/ 2 : 무기 선택/ 3 : 공격/ 4 : 적 상태/ 5 :현재 내 상태 / 6 : 도움말 / 0 : 종료" << endl << endl;
			break;
		case 0:
			break;
		default: cout << "6을 입력하여 명령어를 확인하세요" << endl;
			break;
		}


		if (action == 0) {
			cout << "종료" << endl;
			break;
		}

	}




}