#include<iostream>

using namespace std;



class PokeMon {

	int number;
	string name;
	string nick_name;
	string type;
	int strength;

private :
	void set_nickname(string nick_name) {
		this->nick_name = nick_name;

		cout << name << "의 이름은 " << this->nick_name << "입니다.";
	}

protected:	
	int get_strenth() {
		return strength;
	}

	void set_strenth(int range1, int range2) {
		this->strength = 3 * (rand() % range2 + range1) ;
	}

	void Attack() {
		cout << type << "속성 공격" << endl;
	}

public: 
	PokeMon(string name, int number, string type) {
		cout << "포켓몬 생성자";
		this->name = name;
		this->number = number;
		this->type = type;
	}

	string get_name() {
		return this->name;
	}

	void set_newNickname() {
		string nickname;

		cout << "새로운 이름을 입력하세요 ";
		cin >> nickname;

		this->set_nickname(nickname);
	}
};



class Bulbasaur : public PokeMon {

public:
	Bulbasaur() :PokeMon("이상해씨", 1, "풀") {
		this->set_strenth(4, 9);

		cout << this->get_name() << "이/가 알에서 부화했습니다."<<endl;

		this->cry();

		string answer;
		cout << "새로 이름을 지워주겠습니까?";
		cin >> answer;

		if (answer == "y") {
			this->set_newNickname();
		}
	};

	void cry() {
		cout << "해씨 씨~";
	}

	void use_skill() {
		this->Attack();
		cout << "잎날 가르기!" << endl;
		cout << "위력 : " << this->get_strenth();
	}
};

class Charmander : public PokeMon {
	
public :
	Charmander() :PokeMon("파이리", 4, "불") {
		
		cout << "파이리 생성자";
		this->set_strenth(5, 7);

		cout << this->get_name() << "이/가 알에서 부화했습니다."<<endl;

		this->cry();

		string answer;
		cout << "새로 이름을 지워주겠습니까?";
		cin >> answer;

		if (answer == "y") {
			this->set_newNickname();
		}

	};

	void cry() {
		cout << "파이 파이~"<<endl;
	}

	void use_skill() {
		this->Attack();
		cout << "화염 방사!" << endl;
		cout << "위력 : " << this->get_strenth();
	}

};

class Squirtle : public PokeMon {

public:
	Squirtle() :PokeMon("꼬부기", 7, "물") {
		this->set_strenth(1, 10);

		cout << this->get_name() << "이/가 알에서 부화했습니다."<<endl;

		this->cry();

		string answer;
		cout << "새로 이름을 지워주겠습니까?";
		cin >> answer;

		if (answer == "y") {
			this->set_newNickname();
		}

	};

	void cry() {
		cout << "꼬부 꼬부~";
	}

	void use_skill() {
		this->Attack();
		cout << "물대포!" << endl;
		cout << "위력 : " << this->get_strenth() << endl;
	}
};


int main() {
	Charmander c1;
	c1.use_skill();

	Bulbasaur b1;
	b1.use_skill();

}