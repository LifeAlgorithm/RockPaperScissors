/****************************************************************
** Utility Functions: User Input Validation
**
** Sam Chew       933191613
** 2017/02/11
** 
** Desc: This collection of utility functions provide modular
**    input validation. Intended for ongoing use for class projects
**
*****************************************************************/

#include "chewsValidation_v5.hpp"

/***************************************
** Desc: checks that the input string is
**    a valid integer candidate
** 
** Input: A string as input by user
** Output: bool if valid candidate for 
**    conversion into integer
**
**Citations:
**Concepts for numeric string validation
**   www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
***************************************/
bool validateIntegerString(std::string strUserInput){
	
	bool probFound = false;
	bool firstDigit = false;
	bool negFound = false;
	
	//Loop through the characters of input string
	for (unsigned int i=0; i < strUserInput.length(); i++){
		if (!probFound){//if no issues found yet
			if (!firstDigit){//if the 1st digit is not found yet
				if (!negFound){//if the negation operator is not found yet
					if (isdigit(strUserInput[i])){//if char is a digit
						firstDigit = true;//set 1st digit flag
					}
					else {//else (char is not a digit)
						if (strUserInput[i]==45){//if char is negation operator
							negFound = true;//set negation flag
						}
						else if (strUserInput[i]!=32){//if char is not a space
							probFound = true;//set problem flag
						}
					}
				}
				else {//negation operator is found
					if (isdigit(strUserInput[i])){//if char is a digit
						firstDigit = true;//set 1st digit flag
					}
					else if (strUserInput[i]!=32){//if char is not a space
						probFound = true;//set problem flag
					}
				}
			}
			else {//else (the 1st digit has been found)
				if (!isdigit(strUserInput[i])) {//if char is not a digit
					probFound = true;//set problem flag
				}
			}
			
		}
	}
	
	if (firstDigit!=true)
		probFound = true;
	
	return !probFound;
}


/***************************************
** Desc: checks a user input value is
**    a positive integer greater than 0
** 
** Input: A int byRef receive result value
** Output: 
**
***************************************/
void validatePositiveInt(int& refVar){
	
	//declare general variables
	std::string userIntStr;
	
	do
	{
		std::getline(std::cin,userIntStr);   //collect the entire line of characters
		
		if (!validateIntegerString(userIntStr)){     //if validateIntegerString is negative
			std::cout << "Invalid Entry. Please try again." << std::endl;
		}
		else  // if validateIntegerString is positive
		{
			refVar = std::stoi(userIntStr);   //convert str to int
			if (refVar < 0)    // if converted int is out of range
			{
				std::cout << "Please Enter an integer greater than or equal to 0." << std::endl;
			}
		}
	} while (refVar<0);
}



/***************************************
** Desc: imports a *.txt file to print
**    multiple lines of a List menu, then
**    determines the qty of options to 
**    validate user input.
** 
** Input: A string to identify filename
** Output: validated integer value
**
***************************************/
int menuListOptions(std::string filename)
{
	//Establish Operational Variable Identifiers
	std::string strFile;
	std::ifstream inputFile;
	std::string strDataLine;
	int intLineQty;
	int userChoice = -1;
	
	strFile = "./" + filename;
	inputFile.open(strFile);
	
	if (inputFile.fail())
	{
		std::cout << "Error opening menuListOptions file: " << filename << std::endl;
	}
	else
	{
		//get the first line
		std::getline(inputFile, strDataLine);
		
		//initialize the qty of lines (Negative because 1st line should be Menu Title)
		intLineQty = -1;
		
		while (inputFile)
		{
			//print to screen each line of the file
			std::cout << strDataLine << std::endl;
			
			//count the quantity of lines within the file
			intLineQty++;
			
			//get the next line
			std::getline(inputFile, strDataLine);
		}
		
		//Collect the User Inputs
		std::cout << "Please enter your menu choice:";
		do
		{
			//call the inputvalidation functions
			validatePositiveInt(userChoice);
			if ((userChoice <1) || (userChoice > intLineQty))
			{
				std::cout << "Invalid menu option. Please choose again: ";
			}
		} while ((userChoice <1) || (userChoice > intLineQty));
	}
	
	// Close the file
	inputFile.close();
	
	return userChoice;
}

/***************************************
** Desc: checks that the input string is
**    a valid double candidate
** 
** Input: A string as input by user
** Output: bool if valid candidate for 
**    conversion into double
**
**Citations:
**
***************************************/
bool validateDoubleString(std::string strUserInput)
{
	bool probFound = false;
	bool firstDigit = false;
	bool negFound = false;
	bool dotFound = false;
	
	//Loop through the characters of input string
	for (unsigned int i=0; i < strUserInput.length(); i++){
		if (!probFound){//if no issues found yet
			if (!firstDigit){//if the 1st digit is not found yet
				if ((!negFound) && (!dotFound)){//if the negation operator and the period are not found yet
					if (isdigit(strUserInput[i])){//if char is a digit
						firstDigit = true;//set 1st digit flag
					}
					else {//else (char is not a digit)
						if (strUserInput[i]==45){//if char is negation operator
							negFound = true;//set negation flag
						}
						else if (strUserInput[i]==46){//if char is a period
							dotFound = true;//set dot found flag
						}
						else if (strUserInput[i]!=32){//if char is not a space
							probFound = true;//set problem flag
						}
					}
				}
				else if ((negFound) && (!dotFound)){
					if (isdigit(strUserInput[i])){//if char is a digit
						firstDigit = true;//set 1st digit flag
					}
					else if (strUserInput[i]==46){//if char is a period
						dotFound = true;//set dot found flag
					}
					else if (strUserInput[i]!=32){//if char is not a space
						probFound = true;//set problem flag
					}
				}
				else {//negation operator and period are found OR period found w/out negation operator
					if (isdigit(strUserInput[i])){//if char is a digit
						firstDigit = true;//set 1st digit flag
					}
					else if (strUserInput[i]!=32){//if char is not a space
						probFound = true;//set problem flag
					}
				}
			}
			else {//else (the 1st digit has been found)
				if (!dotFound){	// if the period is not found yet
					if (strUserInput[i]==46){//if char is a period
						dotFound = true;//set dot found flag
					}
					else if (!isdigit(strUserInput[i])) {//if char is not a digit
						probFound = true;//set problem flag
					}
				}
				else {	//the period has been found
					if (!isdigit(strUserInput[i])) {//if char is not a digit
					probFound = true;//set problem flag
					}
				}
			}
			
		}
	}
	
	return !probFound;
}


/***************************************
** Desc: checks a user input value is
**    a positive double greater than 0
** 
** Input: A double byRef to receive result value
** Output: 
**
**
***************************************/
void validatePositiveDouble(double& refVar){
	
	//declare general variables
	std::string userIntStr;
	
	do
	{
		std::getline(std::cin,userIntStr);   //collect the entire line of characters
		
		if (!validateDoubleString(userIntStr)){     //if validateDoubleString is negative
			std::cout << "Invalid Entry. Please try again." << std::endl;
		}
		else  // if validateDoubleString is positive
		{
			refVar = std::stod(userIntStr);   //convert str to int
			if (refVar <= 0)    // if converted int is out of range
			{
				std::cout << "Please Enter a double greater than 0." << std::endl;
			}
		}
	} while (refVar<=0);
}


/* Testing Main 
int main()
{
	std::cout << "Press enter to continue.." << std::endl;
	std::cin.get();
	
	//Create the Menu_AddQty file
	std::ofstream outputfile;
	outputfile.open("./testlist.txt");
	
	//Add Menu Title line
	outputfile << "Choose from the following Menu options:" << std::endl;
	
	//Add each option line
	outputfile << "   1) First Option" << std::endl;
	outputfile << "   2) Second Option" << std::endl;
	outputfile << "   3) Third Option" << std::endl;
	outputfile << "   4) Quit" << std::endl;
	
	//Close open file object
	outputfile.close();
	
	int testOption = menuListOptions("./testlist.txt");
	std::cout << "Your choice was: " << testOption << std::endl;
	return 0;
}
*/

