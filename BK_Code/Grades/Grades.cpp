
//Author: Kirubanantham. K

#include <iostream>
#include <string>
#include "sqlite3.h" 

//Callback function to print data
static int callback(void* data, int argc, char** argv, char** clmn)
{
	std::string grdstr;
	int marks = atoi(argv[2]);	//Collecting marks

	//Condition to decide on grade
	if (marks > 90) {
		grdstr = "A+";
	} else if (marks > 70) {
		grdstr = "A";
	} else if (marks > 50) {
		grdstr = "B";
	} else if (marks >= 40) {
		grdstr = "C";
	} else {
		grdstr = "Fail";
	}

	std::cout << argv[0] << " " << argv[1] << " " << argv[2] << " " << grdstr;
	std::cout << std::endl << std::endl;
	return 0;
}

//To display status of exec commands
void errormessage(int errcode, char *errmsg, std::string func)
{
	if (errcode != SQLITE_OK) {
		std::cout << func << " Failed" << std::endl;
		sqlite3_free(errmsg);
	}
	else {
		std::cout << func << " Successful" << std::endl;
	}
}

int main()
{
	sqlite3* DB;
	char* errmsg;
	int sts = sqlite3_open("Grades.db", &DB);	//DB Name = RetailDB and Table Name = RETAIL

	//Check and delete if table already has the data
	std::string sqldel = "DELETE FROM GRADES;";
	sts = sqlite3_exec(DB, sqldel.c_str(), NULL, 0, &errmsg);
	errormessage(sts, errmsg, "Delete");

	//Insert data to table
	std::string sql("INSERT INTO GRADES VALUES(1, 'Matt', 44);"
		"INSERT INTO GRADES VALUES(2, 'John', 57);"
		"INSERT INTO GRADES VALUES(3, 'Lucas', 78);"
	);
	sts = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errmsg);
	errormessage(sts, errmsg, "Insertion");

	//Fetch the data from table
	std::string query = "SELECT * FROM GRADES";
	sts = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	errormessage(sts, errmsg, "Fetch");

	sqlite3_close(DB);
	return (0);
}