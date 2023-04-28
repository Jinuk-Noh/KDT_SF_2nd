#include <iostream>
#include <string>
#include <mysql/jdbc.h>

using std::cout;
using std::endl;
using std::string;

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "root"; // 데이터베이스 사용자
const string password = "abc123"; // 데이터베이스 접속 비밀번호

int main()
{
    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
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

    // 데이터베이스 선택
    con->setSchema("codingon2");

    // db 한글 저장을 위한 셋팅 
    stmt = con->createStatement();
    stmt->execute("set names euckr");
    if (stmt) { delete stmt; stmt = nullptr; }

#pragma region Create Insert
    // 데이터베이스 쿼리 실행
    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS inventory"); // DROP
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);"); // CREATE
    cout << "Finished creating table" << endl;
    delete stmt;

    //입력 값을 나중에 지정할 수 있다.
    pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)"); // INSERT

    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "orange");
    pstmt->setInt(2, 154);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "사과");
    pstmt->setInt(2, 100);
    pstmt->execute();
    cout << "One row inserted." << endl;

    // MySQL Connector/C++ 정리
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

    //cout << "수정 여부 : " <<  a <<endl;
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