#include <iostream>

#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"

#ifdef _DEBUG
#pragma comment(lib, "./debug/mysqlcppconn.lib")
#else
#pragma comment(lib, "./mysqlcppconn.lib")
#endif

using namespace std;

int main()
{
	sql::Driver* driver = nullptr;
	sql::Connection* connection = nullptr;
	sql::Statement* statement = nullptr;
	sql::ResultSet* resultset = nullptr;
	sql::PreparedStatement* preparedstatement = nullptr;

	string userid;
	string userpassword;
	bool isLogin = false;

	while (!isLogin)
	{
		cout << "유저아이디 : ";
		cin >> userid;
		cout << "유저비밀번호 : ";
		cin >> userpassword;


		//workbench 켜기
		driver = get_driver_instance();
		//연결 버튼 누르기
		connection = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
		if (connection == nullptr)
		{
			cout << "connection error." << endl;
			exit(-1);
		}

		//use ygl;
		connection->setSchema("ygl");
		//Query typing
		statement = connection->createStatement();
		//쿼리실행
		//resultset = statement->executeQuery("SELECT * from film_actor limit 10");

		//로그인 
		preparedstatement = connection->prepareStatement("SELECT * from member where user_id = ? and user_password = ?");
		preparedstatement->setString(1, userid);
		preparedstatement->setString(2, userpassword);
		preparedstatement->execute();
		resultset = preparedstatement->getResultSet();

		if (resultset && resultset->rowsCount() > 0)
		{
			cout << "로그인 성공" << endl;
			isLogin = true;
		}
		else
		{
			cout << "로그인 실패" << endl;
		}
	}

	//Display
	//for (;resultset->next();)
	//{
	//	cout << resultset->getString("film_id") << endl;
	//}

	//while (resultset->next())
	//{
	//	cout << resultset->getString("film_id") << endl;
	//	cout << resultset->getString("actor_id") << endl;
	//	cout << resultset->getString("last_update") << endl;
	//}

	delete resultset;
	delete statement;
	delete connection;


	return 0;
}