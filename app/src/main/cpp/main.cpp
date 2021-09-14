/*()()()()()()()()		Raan Saurav Bhuyan, BCA 6th Semester, Tihu College, 2021	()()()()()()()()*/

#include <iostream>
#include <stdlib.h>
#include <string>					/* Included to provide access to below functions:				 *
									 * 1. getline(),												 *
									 * 2. ignore()													 *
									 */

#include "country.h"				/* Included to provide access to below functions:				 *
									 * 1. int country(),											 *
									 * 2. void countrySelect(void)									 *
									 */

#include "covid.h"					/* Header is included to make the 'covid' class and other		 *
									 * functions accessible for the function calls.				     *
									 */

using namespace std;

int main(int argc, char* argv[]) {
	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Error checking block for command line arguments. Designated errors are:						 **
	 ** (1) if (argc > 3) [overloaded arguments]													 **
	 ** (2) if (argc == 2) [conditional]															 **
	 ** (3) if argv[1] doesn't satisfy any condition.												 **
	 **/
	if (argc > 3) {		/* More than two command line arguments are unsupported.					 *
						 */

		string ext3 = argv[3];

		cout << endl << "\nInvalid argument \"" << ext3 << "\"!\nTry again.\n" << endl;

		exit(0);
	}
	
	if (argc > 1) {

		string ext = argv[1];

		if (ext == "-c" || ext == "--country") {

			if (argc == 2) {	/* Country name must be passed as support parameter					 *
								 * such as "-c --<country name>".									 *
								 */

				cout << endl << "\nCountry name isn't passed as support argument for \"" << ext << "\"!";
				cout << endl << "Try again.\n" << endl;

				exit(0);
			} 
		} else if (ext == "-h" || ext == "--help");
				else {			/* If the fist command line argument mismatches,					 *
								 * it will cause exit.												 *
								 */

					cout << endl << "\nInvaild argument \"" << ext << "\"!\nTry again.\n" << endl;

					exit(0);
				}

	}
	//================================================================================================//

	cout << endl << "\n===================================================================";
	cout << "=====================================================" << endl;

	cout << "\t\t||\t\t    Covid-Analysis C++ Application\t\t\t||" << endl;
	cout << "\t\t||\tEstimating the COVID-19 Evolution Using the Logistic Model\t||" << endl;
	cout << "\t\t||\t\t   Raan Saurav Bhuyan, August, 2021\t\t\t||" << endl;

	cout << "===================================================================";
	cout << "=====================================================\n" << endl;

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 **                                Variable Declaration Section								     **
	 **/

			string whatif;		/* Just a character to hold the input of							 *
								 * selecting a country or configure manually.						 *
								 */

			int countryCode = 0;/* Variable to hold the unique country code							 *
								 * for each of the countries available to sharable data.			 *
								 */

			bool retManConfig;	/* Variable to hold the return value from							 *
								 * the manConfig() function.										 *
								 */
	//================================================================================================//

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** External command line arguments can be passed to the program which							 **
	 ** have been configured in the below section.													 **
	 **/

	if (argc == 1)
		goto labelStartOver;
		else {	//Operation block of the first command line argument

			string ext1 = argv[1];

			if (ext1 == "-c" || ext1 == "--country") {

				string ext2 = argv[2];

				if (ext2 == "-m" || ext2 == "--manual") {

					manConfig();

					return 0;
				}		else if (ext2 == "--india") {

							india();

							return 0;
						}		else if (ext2 == "--brazil") {

									brazil();

									return 0;
								}		else if (ext2 == "--china") {

											china();

											return 0;
										}		else if (ext2 == "--us") {

													us();

													return 0;
												}		else {

															cout << endl << "\n\tInvalid argument \"";
															cout << ext2 << "\"!\n\tTry again." << endl;

															exit(0);
														}
			} else if (ext1 == "-h" || ext1 == "--help") {

				cout << endl << "\n\tHelp entered!";

				exit(0);
			}
		}
	//================================================================================================//


	labelStartOver: 
		cout << endl << "\n\tDo you want to select a country with pre-configured settings? ";
	cout << "(Default is yes [y].)" << endl;
	cout << "\tPress 'y' if yes or 'n' if no: ";
	/* Str (1) */	getline(cin, whatif);
	
	if (whatif.length() == 0)
		whatif = "y";

	if (whatif == "n") {

		whatif = "y";	/* Failsafe statement.														 *
						 */

		retManConfig = manConfig();

		/* Err (1) */	if (retManConfig == false || retManConfig == true)
			/* Jump (1) */	goto labelExit1;
	}
	else if (whatif == "y") {
		//============================================================================================//
		/**------------------------------------------------------------------------------------------**
		 ** The switch statement below checks the return integer by country() function				 **
		 ** and redirects to the requested country's source file to handle the pre-configured		 **
		 ** process of evaluation.																	 **
		 **/

		labelCountry:
			countryCode = country();

		switch (countryCode) {
			case 1: {
				cout << endl << "\n\tAssinged country: India," << endl;
				cout << "\tCountry Code = 1" << endl;

				/* Err (2) */	if (india() == false)
					/* Jump (3) */	goto labelExit0;
				break;
			}
			case 2: {
				cout << endl << "\n\tAssigned country: Brazil" << endl;
				cout << "\tCountry Code = 2" << endl;

				/* Err (3) */	if (brazil() == false)
					/* Jump (4) */	goto labelExit0;
				break;
			}
			case 3: {
				cout << endl << "\n\tAssigned country: United States" << endl;
				cout << "\tCountry Code = 3" << endl;

				/* Err (4) */	if (us() == false)
					/* Jump (5) */	goto labelExit0;
				break;
			}
			case 4: {
				cout << endl << "\n\tAssigned country: China" << endl;
				cout << "\tCountry Code = 4" << endl;

				/* Err (5) */	if (china() == false)
					/* Jump (6) */	goto labelExit0;
				break;
			}
			default: {

				cout << endl << "\n\tCountry couldn't be evaluated!" << endl;

				countrySelect();
				/* Jump (7) */	goto labelCountry;
			}
		//================================================================================================//
		}
	} else {

		cout << endl << "\n\tWrong input!";
		/* Jump (8) */	goto labelStartOver;
	}

	//====================================================================================================//
	/**--------------------------------------------------------------------------------------------------**
	 ** I call the below if-else as 'exit-check'														 **
	 ** of which the core functionality is to ask whether to exit										 **
	 ** or repeat the process.																			 **
	 **/
	labelExit0:
		cin.ignore();	/* To ignore the previous 'enter' input											 *
						 * in order to prevent detection by below if-else.								 *
						 */

	labelExit1:
		cout << endl << "\n\tDo you want to repeat the process again? (Default is no [n].)" << endl;
	cout << "\tPress 'y' if yes or 'n' if no: ";
	/* Str (2) */	getline(cin, whatif);

	if (whatif.length() == 0 || whatif == "n") {

		cout << endl << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
		cout << endl << endl << endl;

		return 0;
	}
	else if (whatif == "y")
		/* Jump (9) */	goto labelStartOver;
	else {
		cout << endl << "\n\tWrong input!";
		/* Jump (10) */	goto labelExit1;
	}
	//=====================================================================================================//
}