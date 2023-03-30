#include <iostream>
#include <vector>
#include<fstream>

using namespace std;


class Cat {
	string name ="고양이";
	int age;

	public: 
	Cat(string name, int age) {
		this->name = name;
		this->age = age;
		cout << "고양이가 태어났습니다.\n";
	}

	void mew() {
		cout << "냐옹\n";
	}
};

class Rectangle {
	float width;
	float height;

public:
	//Rectangle(float width, float height) {
	//	this->width = width;
	//	this->height = height;
	//}

	float area() {
		return width * height;
	}

	float getWidth(){
		return width;
	}

	float getHeight() {
		return height;
	}

	void setWidth(float width) {
		this->width = width;
	}

	void setHeight(float height) {
		this->height = height;
	}
};


class Character {
	string id;

	string name;
	int level;
	int item_num;

	int hp;
	int damage;

	Character* target;

	public:
	Character(string name, string id) {
		this->name = name;
		this->level = 0;
		this->item_num = 0;

		this->hp = 10;
		this->damage = 2;
		this->id = id;
	}


	void doIt(int action) {		

		if (this->hp <= 0) {
			cout << "해당 캐릭터는 hp가 0이기 때문에 행동할 수 없습니다." << endl;
			return;
		}
			

		switch (action)
		{
		case 0:
			break;
		case 1:
			
			cout << "새 이름을 입력해주세요 : ";
			cin >> this->name;
			cout << "이름이 변경되었씁니다." << endl;
			cout << "new name : " << this->name << endl;

			break;
		case 2:
			this->level++;
			cout << "level up!"<<endl;
			cout << "현재 레벨 : "<<this->level << endl;
			break;
		case 3:
			this->item_num++;
			cout << "아이템을 얻었습니다." << endl;
			cout << "현재 아이템 개수 : "<< this->item_num << endl;
			break;
		case 4:
			if (this->item_num == 0) {
				cout << "사용할 수 있는 아이템이 없습니다." << endl;
				cout << "현재 아이템 개수 : "<< this->item_num << endl;
			}
			else {
				this->item_num--;
				cout << "아이템을 사용했습니다." << endl;
				cout << "현재 아이템 개수 : " << this->item_num << endl;
			}
			break;
		case 5:
			cout << "이름 : " << this->name << endl
				<< "레벨 : " << this->level << endl
				<< "현재 아이템 개수 : " << this->item_num << endl;
			break;
		case 6:
			attack();
			break;
		case 7:
			SaveInfo();
			break;
		default:
			cout << "정의 되지 않은 행동입니다. 입력 가능 동작 (0~6)";
			break;
		}
	}

	void SetTarget(Character* target) {
		this->target = target;
	}

	void attack() {
		if (target->getHp() <= 0) {
			cout <<this->getName()<< "hp가 0이기 때문에 공격할 수 없습니다."<<endl;
		}

		cout << target->getName() << "을/를 공격" <<endl;
		cout << "입힌 피해 "<< this->damage << endl;
		this->target->damaged(this->damage);
	}

	void SaveInfo() {
		cout << "ID :" << this->id << "정보 저장 중....";
		ofstream saveStream(this->id+"Info.txt");

		if (saveStream.is_open()) {
			saveStream << "ID : " << id << endl
				<< "Name : " << name << endl
				<< "Level : " << level << endl
				<< "Item Num : " << item_num << endl
				<< "HP : " << hp << endl
				<< "Damage : " << damage;


			cout << "ID :" << this->id << "저장 완료.";

			saveStream.close();
		}
		else {
			cout << "ID :" << this->id << "저장 실패";
		}
	}

	string getName() {
		return this->name;
	}

	string getID() {
		return this->id;
	}

	int getHp() {
		return this->hp;
	}

	void damaged(int damage) {
		this->hp = this->hp - damage;

		if (this->hp <= 0) {
			cout << this->name << "이/가 사망했습니다."<<endl;
		}
		else {
			cout << this->name << "의 현재 체력 : " << this->hp <<endl;
		}
	}


};

int main()
{
	/*int width;
	int height;
	cout << "사각형의 가로와 세로 길이를 입력해주세요(띄어쓰기 구분) : ";
	cin >> width >> height;

	Rectangle ret(width, height);

	cout << "넓이 : " << ret.area();*/

	/*int width;
	int height;
	cout << "사각형의 가로와 세로 길이를 입력해주세요(띄어쓰기 구분) : ";
	cin >> width >> height;

	Rectangle ret;

	ret.setHeight(height);
	ret.setWidth(width);

	cout << "넓이 : " << ret.area();*/
	string name;
	cout << "이름을 입력하세요 : ";
	cin >> name;
	Character c(name,"1");

	cout << "이름을 입력하세요 : ";
	cin >> name;
	Character t(name,"2");

	vector<Character*> targets;
	targets.push_back(&c);
	targets.push_back(&t);

	int action = 0;
	for (auto character : targets) {

		cout << "ID : " << character->getID() << "플레이 중"<<endl;
		do {
			cout << "어떤 동작을 실행하시겠습니까? (0: 종료) ";
			cin >> action;

			bool isTarget = false;

			if (action == 6) {
				cout << "대상을 입력하세요 : ";
				cin >> name;
				for (auto temp : targets) {
					if (((*temp).getName() == name) && temp != character) {
						character->SetTarget(temp);
						isTarget = true;
						break;
					}
				}

				if (isTarget == false) {
					cout << "대상이 없습니다." << endl;
					continue;
				}
			}

			character->doIt(action);

			
		} while (action != 0);

		for (auto tempC : targets) {
			tempC->doIt(7);
		}

		cout << "ID : " << character->getID() << "플레이 종료"<<endl
			;
	}

 }

