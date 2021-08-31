#include <iostream>
#include "country.h"				/* Included to provide access to below functions:				 *
									 * 1. int country(),											 *
									 * 2. void countrySelect(void)									 *
									 */

#include <algorithm>				/* Included to provide access to transform() function.			 *
									 */

#include <string>					/* Included to provide access to below functions:				 *
									 * 1. getline(),												 *
									 * 2. ignore()													 *
									 */

using namespace std;

bool manConfig() {
	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 **                                Variable Declaration Section								     **
	 **/

			//TODO: remove comment from "LSSD covid;"
			 /*LSSD covid;*/	 /* Variable of type class 'LSSD'.									  *
								  * Class definition available in the source file 'covid.h'.          *
								  */

			string iName;		/* A string to hold the pathname to the								 *
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

	if (countryName.length() == 0) {
		cout << endl << "\n\tYou have not entered the country name!" << endl;
		/* Jump (1) */	goto labelCountryName;
	}

	{

		string duplicate = countryName;		/* Local variable to temporarily hold the				 *
											 * string input of countryName.							 *
											 */
		//============================================================================================//
		/**
		 ** transform() function defined under the 'algorithm.h' header file						 *
		 ** is used to change the 'duplicate' string into uppercase.								 *
		 **/
		transform(duplicate.begin(), duplicate.end(), duplicate.begin(), ::toupper);

		cout << endl << "\n\t\t\tINPUT SCREEN | " << duplicate;
		cout << endl << "---------------------------------------------------------------------";
		cout << "-----------";
		//============================================================================================//
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

	cout << endl << "\n\tInsert the relative path to the Comma Separated Values (*.csv) file" << endl;
	cout << "\t(The pathname should be '/data/<country_name>/<country_name>_data.csv') ";
	cout << "without spaces: ";
	/* Input (7) */	cin >> iName;

	//TODO: remove comment from covid.readinputfile()
	//covid.readinputfile /* Enter file inside braces (): */(iName);
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choose the limit of daily prediction:												 **
	 ** N.B. Prediction might not be sufficient to expect the peak or inflection point.				 **
	 **/

	cout << endl << "\n\tInsert the limit of the days of prediction table" << endl;
	cout << "\t(Remember that a limit exceeding 60 days is almost meaningless): ";
	/* Input (8) */	cin >> dayLimit;

	//TODO: remove comment from covid.EndTime
	//covid.EndTime = 60;
	//================================================================================================//
	cout << endl << "--------------------------------------------------------------------------------";

	return true;
}