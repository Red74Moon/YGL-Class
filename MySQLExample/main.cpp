#include <iostream>

#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"

#pragma comment(lib, "debug/mysqlcppconn.lib")

using namespace std;

int main()
{
	sql::Driver* driver;
	sql::Connection* connection;
	sql::Statement* statement;
	sql::ResultSet* resultset;

	//Workbanch 켜기
	driver = get_driver_instance(); // 엔진 생성
	
	//연결 버튼 누르기
	connection = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
	if (connection == nullptr)
	{
		cout << "connection error!" << endl;
		exit(-1);
	}

	//use Database
	connection->setSchema("ygl");

	//Quarry
	statement = connection->createStatement();
	resultset = statement->executeQuery("SELECT 'Hello Word' AS message");

	//Display
	while (resultset->next())
	{
		cout << resultset->getString("message") << endl;
	}

	delete resultset;
	delete statement;
	delete connection;

	return 0;
}