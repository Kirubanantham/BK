
//Author: Kirubanantham. K

#include <iostream>
#include <string>
#include <algorithm>

bool findpalindrome(std::string str)
{
	//To avoid checking for case sensitive all the charecters are coverted to upper charecter  
	std::transform(str.begin(), str.end(), str.begin(), toupper);

	std::string first = str;				//Collecting the initial string value
	std::reverse(str.begin(), str.end());	//Reversing the string
	int rslt = str.compare(first);			//compare the reversed string to intial value - return value : 0=Same
	return rslt == 0 ? true : false;
}

int main()
{
	//Case 1
	std::string str = "1881";
	if (findpalindrome(str)) {
		std::cout << str << " : is palindrome" << std::endl;
	}
	else {
		std::cout << str << " : is not palindrome" << std::endl;
	}
	//Case 2
	str = "Dad";
	if (findpalindrome(str)) {
		std::cout << str << " : is palindrome" << std::endl;
	}
	else {
		std::cout << str << " : is not palindrome" << std::endl;
	}
	//Case 3
	str = "Step on no pets";
	if (findpalindrome(str)) {
		std::cout << str << " : is palindrome" << std::endl;
	}
	else {
		std::cout << str << " : is not palindrome" << std::endl;
	}

	//Case 4 to show not a palindrome
	str = "Step on no pet";
	if (findpalindrome(str)) {
		std::cout << str << " : is palindrome" << std::endl;
	}
	else {
		std::cout << str << " : is not palindrome" << std::endl;
	}
	return 0;
}