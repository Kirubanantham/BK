
//Author: Kirubanantham. K

#include <iostream>
#include <string>
#include "sqlite3.h" 

//Callback function to print data
static int callback(void* data, int argc, char** argv, char** clmn)
{
	std::cout << argv[0] << " " << argv[1];
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
	int sts = sqlite3_open("RetailDB.db", &DB);	//DB Name = RetailDB and Table Name = RETAIL

	//Check and delete if table already has the data
	std::string sqldel = "DELETE FROM RETAIL;";
	sts = sqlite3_exec(DB, sqldel.c_str(), NULL, 0, &errmsg);
	errormessage(sts, errmsg, "Delete");

	//Insert data to table
	std::string sql("INSERT INTO RETAIL VALUES(1, 'Frances White', 'USA', 200350);"
		"INSERT INTO RETAIL VALUES(2, 'Carolyn Bradley', 'UK', 15354);"
		"INSERT INTO RETAIL VALUES(3, 'Annie Fernandez', 'France', 359200);"
		"INSERT INTO RETAIL VALUES(4, 'Ruth Hanson', 'Albania', 1060);"
		"INSERT INTO RETAIL VALUES(5, 'Paula Fuller', 'USA', 14789);"
		"INSERT INTO RETAIL VALUES(6, 'Bonnie Johnston', 'China', 100243);"
		"INSERT INTO RETAIL VALUES(7, 'Ruth Gutierrez', 'USA', 998999);"
		"INSERT INTO RETAIL VALUES(8, 'Ernest Thomas', 'Canada', 500500);"
		"INSERT INTO RETAIL VALUES(9, 'Joe Garza', 'UK', 18782);"
		"INSERT INTO RETAIL VALUES(10, 'Anne Harris', 'USA', 158367);"

		"INSERT INTO RETAIL VALUES(11, 'Ruth Hanson', 'Albania', 1061);"	//Added to demonstrate same name
	);
	sts = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errmsg);
	errormessage(sts, errmsg, "Insertion");

	//Sorting and fetch (sort w.r.t to multiple column). Name in descending order & ID in ascending order
	std::string query = "SELECT * FROM RETAIL ORDER BY NAME DESC , ID ASC";
	sts = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	errormessage(sts, errmsg, "Sorting");

	sqlite3_close(DB);
	return (0);
}