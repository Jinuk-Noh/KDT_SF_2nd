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

		cout << name << "�� �̸��� " << this->nick_name << "�Դϴ�.";
	}

protected:	
	int get_strenth() {
		return strength;
	}

	void set_strenth(int range1, int range2) {
		this->strength = 3 * (rand() % range2 + range1) ;
	}

	void Attack() {
		cout << type << "�Ӽ� ����" << endl;
	}

public: 
	PokeMon(string name, int number, string type) {
		cout << "���ϸ� ������";
		this->name = name;
		this->number = number;
		this->type = type;
	}

	string get_name() {
		return this->name;
	}

	void set_newNickname() {
		string nickname;

		cout << "���ο� �̸��� �Է��ϼ��� ";
		cin >> nickname;

		this->set_nickname(nickname);
	}
};



class Bulbasaur : public PokeMon {

public:
	Bulbasaur() :PokeMon("�̻��ؾ�", 1, "Ǯ") {
		this->set_strenth(4, 9);

		cout << this->get_name() << "��/�� �˿��� ��ȭ�߽��ϴ�."<<endl;

		this->cry();

		string answer;
		cout << "���� �̸��� �����ְڽ��ϱ�?";
		cin >> answer;

		if (answer == "y") {
			this->set_newNickname();
		}
	};

	void cry() {
		cout << "�ؾ� ��~";
	}

	void use_skill() {
		this->Attack();
		cout << "�ٳ� ������!" << endl;
		cout << "���� : " << this->get_strenth();
	}
};

class Charmander : public PokeMon {
	
public :
	Charmander() :PokeMon("���̸�", 4, "��") {
		
		cout << "���̸� ������";
		this->set_strenth(5, 7);

		cout << this->get_name() << "��/�� �˿��� ��ȭ�߽��ϴ�."<<endl;

		this->cry();

		string answer;
		cout << "���� �̸��� �����ְڽ��ϱ�?";
		cin >> answer;

		if (answer == "y") {
			this->set_newNickname();
		}

	};

	void cry() {
		cout << "���� ����~"<<endl;
	}

	void use_skill() {
		this->Attack();
		cout << "ȭ�� ���!" << endl;
		cout << "���� : " << this->get_strenth();
	}

};

class Squirtle : public PokeMon {

public:
	Squirtle() :PokeMon("���α�", 7, "��") {
		this->set_strenth(1, 10);

		cout << this->get_name() << "��/�� �˿��� ��ȭ�߽��ϴ�."<<endl;

		this->cry();

		string answer;
		cout << "���� �̸��� �����ְڽ��ϱ�?";
		cin >> answer;

		if (answer == "y") {
			this->set_newNickname();
		}

	};

	void cry() {
		cout << "���� ����~";
	}

	void use_skill() {
		this->Attack();
		cout << "������!" << endl;
		cout << "���� : " << this->get_strenth() << endl;
	}
};


int main() {
	Charmander c1;
	c1.use_skill();

	Bulbasaur b1;
	b1.use_skill();

}