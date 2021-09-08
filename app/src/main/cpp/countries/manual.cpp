#include <iostream>
#include <algorithm>				/* Included to provide access to transform() function.			 *
									 */

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

/*\^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\*/
//For testing purposes.

#include "../test-headers/test-main.h"
/*\^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\*/

using namespace std;

bool manConfig(void) {
	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 **                                Variable Declaration Section								     **
	 **/

			 LSSD covid;		/* Variable of type class 'LSSD'.									 *
								 * Class definition available in the source file 'covid.h'.          *
								 */

			string pName;		/* A string to hold the pathname to the								 *
								 * Comma Separated Values (.csv) file.								 *
								 */

			int dayLimit = 0;	/* Variable to hold the input to limit								 *
								 * the day of the prediction table.									 *
								 */

			string countryName;	/* This string variable will hold the name of the country			 *
								 * while manually configuring the data prediction.					 *
								 */

			int m = 0, k = 0;	/* Variable to hold the input of m and k.							 *
								 * Definitions of m and k are given below.							 *
								 */

			float alpha;		/* Variable to hold the input for the acceleration parameter.		 *
								 * Definition available on the README.md file.						 *
								 */

			float dK, dA, dr;	/* Variable to hold the input for the parameter increment vector.	 *
								 * Definition available on the README.md file.						 *
								 */
	//================================================================================================//

	labelCountryName:
		cout << endl << "\n\tEnter the country name: ";
	/* Str (1) */	getline(cin, countryName);

	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
	/* Testing whatif default value:-------------------------------------------------------------------
	 * Using class 'testcountryName'; method: test_Country(string).------------------------------------
	 */

	if (cppManual::testcountryName::test_Country(countryName) == 0) {

		cout << endl << "\n\tYou have not entered the country name!" << endl;

		/* Jump (1) */	goto labelCountryName;
	}
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

	{
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
		/* Testing whatif default value:--------------------------------------------------------------
		 * Using class 'testcountryName'; method: check_CountryName(string).--------------------------
		 */

		string duplicate = cppManual::testcountryName::check_CountryName(countryName);
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

		cout << endl << "\n\t\t\tINPUT SCREEN | " << duplicate;
		cout << endl << "---------------------------------------------------------------------";
		cout << "-----------";
	}

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choosing the value of m (initial data count to find initial guess):				 **
	 **/

	cout << endl << "\n\tInsert the initial data count to take into account: ";
	/* Input (1) */	cin >> m;
	//================================================================================================//

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choosing the value of k (final data count to find initial guess):					 **
	 ** N.B. This should be > 2*m.																	 **
	 **/

	labelKM:
		cout << endl << "\n\tInsert the final data count to take into account: " << endl;
	cout << "\t(Remember always, k = 2*m): ";
	/* Input (2) */	cin >> k;

	if (k < 2 * m) {
		cout << endl << "\n\tYou have entered an invalid value!";
		/* Jump (2) */	goto labelKM;
	}
	//================================================================================================//

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choosing the acceleration parameter alpha:											 **
	 ** N.B. This should always be < 1.																 **
	 **/

	labelAlpha:
		cout << endl << "\n\tInsert the value of acceleration parameter alpha" << endl;
	cout << "\t(Remember always, alpha < 1): ";
	/* Input (3) */	 cin >> alpha;

	/* Check (1) */	if (alpha >= 1) {
		cout << endl << "\n\tYou have entered an invalid value!";
		/* Jump (3) */	goto labelAlpha;
	}
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choosing the parameter increment vector											 **
	 ** dK, dA, and dr should always be << 1														 **
	 **/

	cout << endl << "\n\tInsert values for parameter increment vectors" << endl;
	cout << "\t(Remember always, dK, dA and dr << 1)" << endl;

	labeldK:
		cout << endl << "\n\tInsert the value of parameter increment vector dK: ";
	/* Input (4) */	 cin >> dK;

	/* check (2) */	if (dK >= 1e-3) {
		cout << endl << "\n\tYou have entered an invalid value!";
		/* Jump (4) */	goto labeldK;
	}

	labeldA:
		cout << endl << "\n\tInsert the value of parameter increment vector dA: ";
	/* Input (5) */	 cin >> dA;

	/* Check (3) */	if (dA >= 1e-3) {
		cout << endl << "\n\tYou have entered an invalid value!";
		/* Jump (5) */	goto labeldA;
	}

	labeldr:
		cout << endl << "\n\tInsert the value of parameter increment vector dr: ";
	/* Input (6) */	 cin >> dr;

	/* Check (4) */	if (dr >= 1e-3) {
		cout << endl << "\n\tYou have entered an invalid value!";
		/* Jump (6) */	goto labeldr;
	}
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** The absolute or relative path to the file can be manually entered							 **
	 ** which is holding the data in a Comma Seperated Values (.csv) file.							 **
	 ** Please put the file inside the '/app/build/exe/main/debug/data/' folder						 **
	 **/

	cin.ignore();		/* To ignore the previous 'enter' input										 *
						 * in order to prevent detection by below if-else.							 *
						 */

	/* The below for-loop replaces any spaces in the country name with an underscore.				 *
	 */

	for (int i = 0; i < countryName.length(); i++) {
		if (countryName[i] == ' ')
			countryName[i] = '_';
	}

	string prefix = "/data/" + countryName + "/";
	labelRename:
		cout << endl << "\n\tInsert the name of the Comma Separated Values (*.csv) file:" << endl;
	cout << "\t(The path to the file should be '/data/<country_name>/'): ";
	/* Str (2) */	getline(cin, pName);

	/* The below for-loop checks if there's any space in the filename.								 *
	 * If yes, then it will ask to rename the file without keeping spaces.							 *
	 */

	for (int i = 0; i < pName.length(); i++) {
		if (pName[i] == ' ') {
			cout << endl << "\n\tCannot open filename with spaces!" << endl;
			cout << "\tRename the filename without any spaces.";
			goto labelRename;
		}
	}

	pName = prefix + pName;
	cout << endl << "\n\tThe selected file is: " << pName << endl;
	cout << endl << "--------------------------------------------------------------------------------";

	//TODO: remove comment from covid.readinputfile
	//covid.readinputfile /* Enter file inside braces (): */ (pName);
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choose the limit of daily prediction:												 **
	 ** N.B. Prediction might not be sufficient to expect the peak or inflection point.				 **
	 **/

	cout << endl << "\n\tInsert the limit of the days of prediction table" << endl;
	cout << "\t(Remember that a limit exceeding 60 days is almost meaningless): ";
	/* Input (7) */	cin >> dayLimit;

	covid.EndTime = dayLimit;
	//================================================================================================//
	cout << endl << "--------------------------------------------------------------------------------";

	return true;
}