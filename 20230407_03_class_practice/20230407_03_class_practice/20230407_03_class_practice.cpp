#include <iostream>
#include <vector>
#include<string>
#include<ctime>


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
		this->attack_cnt = this->attack_cnt - 1 < 0 ? 0 : this->attack_cnt - 1;
	}

	virtual void attack() {

	}

	virtual ~Weapon() {

	};

};

class Sword : public Weapon {
public:

	Sword() :Weapon(5, 3, "검") {

	}

	void attack() {
		cout << "찌르기" << endl;
	}
};

class Gun : public Weapon {
public:
	Gun() :Weapon(10, 1, "총") {

	}

	void attack() {
		cout << "총 쏘기" << endl;
	}
};


class Character {
	int hp;
	int level;
	string name;
	Weapon* have_weapon;
	Character* target;
	bool haveTarget;

public:
	Character(string name) {
		this->hp = 20;
		this->level = 1;
		this->name = name;
	}

	~Character() {
		if (have_weapon != nullptr)
			delete have_weapon;

		if (this->target != nullptr)
			this->target = nullptr;

		delete this->target;
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
			cout << this->name << "이(가)" << this->target->get_name() << "을(를) 공격했습니다." << endl;
		}
	}

	void getWeapone(Weapon* weapon) {
		if (have_weapon != nullptr) {
			delete have_weapon;
			cout << "기존 무기를 버립니다." << endl;
		}

		cout <<weapon->get_name()<< " 무기 줍기" << endl;
		this->have_weapon = weapon;
	}

	Weapon* get_have_weapon() {
		return this->have_weapon;
	}

	void attacked(Weapon* weapon) {

		if (weapon == nullptr) {
			return;
		}

		if (weapon->get_attack_cnt() > 0) {
			this->hp = this->hp - weapon->get_power();
			cout << this->name << "의 hp가 -" << weapon->get_power() << "만큼 감소합니다." << endl;
			weapon->used();
			/*cout << this->name << "의 남은 hp : " << this->hp << endl;*/

			if (this->hp <= 0) {
				cout << this->name << "이(가) 죽었습니다." << endl;
			}
		}
		else {
			cout << "무기의 내구도가 없습니다." << endl;
		}
	}

	int getHP() {
		return this->hp;
	}

	void do_action(bool isComputer = false) {

		cout << endl << "[" << this->name << " turn" << "]" << endl;

		int action;

		if (isComputer) {
			srand(time(NULL));
			action = rand() % 2 + 1;
		}
		else {
			cout << "어떤 동작을 하겠습니까? (1. 무기 줍기 2. 공격) : ";
			cin >> action;
		}

		switch ((action))
		{

		case 1:
			if(isComputer) {
				srand(time(NULL));
				action = rand() % 2 + 1;
			}
			else {
				cout << "어떤 무기를 줍겠습니까? (1. 칼 2. 총) : ";
				cin >> action;
				}
			
			if (action == 1) {
				this->getWeapone(new Sword());
			}
			else if (action == 2) {
				this->getWeapone(new Gun());
			}
			else {
				cout << "무기를 줍는데 실패하였습니다." << endl;
			}

			break;
		case 2:
			this->attack();
			this->target->attacked(this->get_have_weapon());

			break;
		default:
			cout << "아무 행동도 하지 않습니다." << endl;
			break;
		}
	}

	void setTarget(Character* target) {
		this->target = target;
	}

	string get_name() {
		return this->name;
	}

	bool isDead() {
		bool isDead = this->hp <= 0 ? true : false;

		if (isDead) {
			cout << this->target->get_name() << "이(가) 승리 !!" << endl;
		}

		return isDead;
	}

	/* // 사용 안함
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
	*/
};

int main() {

	string name;
	cout << "캐릭터 이름 입력 : ";
	cin >> name;

	Character mainCh = Character(name);
	Character comChar = Character("computer");

	mainCh.setTarget(&comChar);
	comChar.setTarget(&mainCh);

	int action = 0;

	while (mainCh.getHP() > 0 &&
		comChar.getHP() > 0) {
	
		mainCh.do_action();

		if (comChar.isDead()) {
			break;
		}

		comChar.do_action(true);

		if (mainCh.isDead()) {
			break;
		}
	}
}