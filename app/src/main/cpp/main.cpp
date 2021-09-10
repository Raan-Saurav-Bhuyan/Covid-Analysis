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

int main() {
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

			int retManConfig;	/* Variable to hold the return value from							 *
								 * the manConfig() function.										 *
								 */
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

		/* Err (1) */	if (retManConfig == 1)
			/* Jump (1) */	goto labelExit1;
							else if (retManConfig == 0)
				/* Jump (2) */	goto labelExit0;
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