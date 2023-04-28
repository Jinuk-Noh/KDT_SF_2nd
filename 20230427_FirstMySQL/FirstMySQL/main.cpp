#include <iostream>
#include <string>
#include <mysql/jdbc.h>

using std::cout;
using std::endl;
using std::string;

const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "root"; // �����ͺ��̽� �����
const string password = "abc123"; // �����ͺ��̽� ���� ��й�ȣ

int main()
{
    // MySQL Connector/C++ �ʱ�ȭ
    sql::mysql::MySQL_Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

    sql::ResultSet* result;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException& e) {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        exit(1);
    }

    // �����ͺ��̽� ����
    con->setSchema("codingon2");

    // db �ѱ� ������ ���� ���� 
    stmt = con->createStatement();
    stmt->execute("set names euckr");
    if (stmt) { delete stmt; stmt = nullptr; }

#pragma region Create Insert
    // �����ͺ��̽� ���� ����
    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS inventory"); // DROP
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);"); // CREATE
    cout << "Finished creating table" << endl;
    delete stmt;

    //�Է� ���� ���߿� ������ �� �ִ�.
    pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)"); // INSERT

    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "orange");
    pstmt->setInt(2, 154);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "���");
    pstmt->setInt(2, 100);
    pstmt->execute();
    cout << "One row inserted." << endl;

    // MySQL Connector/C++ ����
    delete pstmt;
    delete con;
#pragma endregion

#pragma region  SELECT
 /*   pstmt = con->prepareStatement("SELECT * FROM inventory;");
    result = pstmt->executeQuery();
    bool a = pstmt->execute();

    while (result->next()) {
        printf("Reading from table(%d, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getInt(3));
    }
    
    delete result;
    delete pstmt;
    delete con;*/
#pragma endregion

#pragma region UPDATE
    //pstmt = con->prepareStatement("UPDATE inventory SET quantity = ? WHERE name = ?");
    //pstmt->setInt(1, 500);
    //pstmt->setString(2, "banana");
    //bool a = pstmt->execute();

    //cout << "���� ���� : " <<  a <<endl;
    //printf("Row updated\n");

    //delete con;
    //delete pstmt; 
#pragma endregion

#pragma region DELETE
    /*pstmt = con->prepareStatement("DELETE FROM inventory  WHERE name = ?");
    pstmt->setString(1, "orange");
    pstmt->executeQuery();
    printf("Row deleted\n");

    delete pstmt;
    delete con;*/
#pragma endregion

    return 0;
}