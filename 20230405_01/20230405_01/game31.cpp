#include <iostream>
#include<cstdlib>
#include<ctime> 
#include <vector>

using namespace std;

bool input_user(int* lastNum, string* winner);
void input_computer(int* lastNum, string* winner);

int main()
{
    bool isFirst = false;
    int pickNum = 0;
    int num = 0;
    int* lastNum = &num;
    string w = "";
    string* winner = &w;
    srand(time(NULL));

    while (true)
    {
        cout << "1~2 ���� ���� �Է����ּ��� ";
        cin >> pickNum;
        if (pickNum < 1 || pickNum > 2) continue;

        if (rand() % 2 + 1 == pickNum) {
            cout << "����ڰ� ���Դϴ�." << endl;
            isFirst = true;
        }
        else {
            cout << "��ǻ�Ͱ� ���Դϴ�." << endl;
            isFirst = false;
        }

        break;
    }


    while (*lastNum < 31) {

        if (isFirst) {
            while (true)
            {
                if (input_user(lastNum, winner)) {
                    break;
                }
            }

            input_computer(lastNum, winner);

            //���� ����
            if (*lastNum == 30) {
                *winner = "��ǻ��";
            }

            //��ǻ�Ͱ� �θ� �� ���ڰ� ��Ÿ������ Ȯ��
            if (*winner != "") break;
        }
        else {
            input_computer(lastNum, winner);

            //���� ����
            if (*lastNum == 30) {
                *winner = "��ǻ��";
            }

            //��ǻ�Ͱ� �θ� �� ���ڰ� ��Ÿ������ Ȯ��
            if (*winner != "") break;

            while (true)
            {
                if (input_user(lastNum, winner)) {
                    break;
                }
            }
        }
    }

    cout << "���� ����!" + *winner + "�� �¸��Դϴ�.";
}


bool input_user(int* lastNum, string* winner) {
    int cnt = 0;
    // ����� �Է�
    cout << "������ �Է��ϼ��� : ";
    cin >> cnt;

    if (cnt < 1 || cnt > 3) {
        cout << "1~3 ������ ���� �Է��ϼ���." << endl;
        return false;
    }

    cout << "����ڰ� �θ� ����!" << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ++ *lastNum << endl;
        if (*lastNum == 31) {
            *winner = "��ǻ��";
            break;
        }
    }

    cout << endl;

    return true;

    // ����� �Է� ��
}

void input_computer(int* lastNum, string* winner) {
    int cnt = 0;
    // ��ǻ�� �Է�
    if (*lastNum == 27) cnt = 3; // ����ڰ� 31�� �θ��� �ϱ�
    else if (*lastNum == 28) cnt = 2;
    else if (*lastNum == 29) cnt = 1;
    else cnt = rand() % 3 + 1; // �⺻ ����

    cout << "��ǻ�Ͱ� �θ� ����!" << endl;
    for (int i = 0; i < cnt; i++) {

        cout << ++ * lastNum << endl;

        // ���� ������� 31�̸� ��(����� �¸� ����)
        if (*lastNum == 31) {
            *winner = "�����";
            break;
        }
    }

    cout << endl;
    // ��ǻ�� �Է� ��
}