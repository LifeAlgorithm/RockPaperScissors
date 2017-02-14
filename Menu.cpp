/****************************************************************
** Program Name: Group10 - Paper,Rock,Scissors
**    Group #10 Members
**      Sam Chew - 933191613
**      Riley Harrison
**      Patrick Huarng
**      Susan Onesky
**      Armand Parajon
**      Peter Yetti
**      Nathan Zimmerman
**
** 2017/02/26
** CS162_400_W2017
**
** Desc: 
**
**
**
** Execution Instructions: Utilize included makefile and run the
**    resulting playgame.exe. (There will be *.txt files created 
**    within the working directory, but the make clean should 
**    remove them.)
****************************************************************/

#include "Menu.hpp"
#include "chewsValidation_v5.hpp"

void menuSetupGame()
{
	//Call Utility Function for Menu_MainOpts file creation
	createMenu_StartOpts();
	int userMenu_start = 0;
	
	//Utility Function for Menu_MainOpts Operation
	userMenu_start = menuListOptions("./Menu_StartOpts.txt");
	
			if (userMenu_start == 1)
			{
				std::cout << "\nThe default tool values will be used.\n" << std::endl;
			}
			else if (userMenu_start == 2)
			{
				std::cout << "\nCustom tool values need to be set and used.\n" << std::endl;
			}
			else
			{
				std::cout << "\nThere was an illegal Menu Selection.\n" << std::endl;
			}
	
}


void menuGamePlay()
{
	//Call Utility Function for Menu_MainOpts file creation
	createMenu_PlayOpts();
	int userMenu_Play = 0;
	//main menu operation loop
	do
	{
		//Utility Function for Menu_MainOpts Operation
		userMenu_Play = menuListOptions("./Menu_PlayOpts.txt");
		
		//Respond to User's Selection
		switch (userMenu_Play)
		{
			case 1: std::cout << "\nPlay Rock\n" << std::endl;  //call rock function;
					break;
			case 2: std::cout << "\nPlay Paper\n" << std::endl;  //call paper function;
					break;
			case 3: std::cout << "\nPlay Scissors\n" << std::endl;  //call scissors function;
					break;
			case 4: //quit
					std::cout << "\nThe program is closing...\n" << std::endl;
					std::cin.get();
					break;
			default: //Uknown value, try again
					std::cout << "Please try another choice..." << std::endl;
		}
		
	} while (userMenu_Play!=4);
}



//Utility Function to build the Menu_MainOpts.txt file
void createMenu_StartOpts()
{
	//Create the Menu_AddQty file
	std::ofstream outputfile;
	outputfile.open("./Menu_StartOpts.txt");
	
	//Add Menu Title line
	outputfile << "Do you want to choose different strengths for the tools:" << std::endl;
	
	//Add each option line
	outputfile << "   1) No, use default strengths for each tool type" << std::endl;
	outputfile << "   2) Yes, use custom strengths for each tool type" << std::endl;
	
	//Close open file object
	outputfile.close();
}


//Utility Function to build the Menu_MainOpts.txt file
void createMenu_PlayOpts()
{
	//Create the Menu_AddQty file
	std::ofstream outputfile;
	outputfile.open("./Menu_PlayOpts.txt");
	
	//Add Menu Title line
	outputfile << "Make your next choice:" << std::endl;
	
	//Add each option line
	outputfile << "   1) Play Rock" << std::endl;
	outputfile << "   2) Play Paper" << std::endl;
	outputfile << "   3) Play Scissors" << std::endl;
	outputfile << "   4) Quit" << std::endl;
	
	//Close open file object
	outputfile.close();
}


