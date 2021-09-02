#include <iostream>
#include "country.h"			/* It is included in order to make the functions in this			 *
								 * source file available to other sources files using the			 *
								 * same header file.												 *
								 */

#include <string>

using namespace std;

//====================================================================================================//
/**
 ** country() function is used to determine which pre-configured country to							 **
 ** evaluate and returns it's country code to the main() function									 **
 ** which later will start the related function for the required country.							 **
 **/
int country(void) {
	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 **                                Variable Declaration Section								     **
	 **/

			string cName;		/* String to hold the country name									 *
								 * for later evaluation and											 *
								 * input and output files detection and validation.					 *
								 */
			int cCode;			/* Variable to hold the country code								 *
								 * Only inside this function (local scope).							 *
								 */
	//================================================================================================//

	cout << endl << "\n\tInsert the name of the country for evaluation" << endl;
	cout << "\t(Remember to enter the full name without spaces.): ";
	getline(cin, cName);	//Optimized: Replaced 'std::cin' with 'std::getline()' to include spaces.

	if (cName == "India")
		/* Var (1) */	cCode = 1;
	else if (cName == "Brazil")
			/* Var (2) */	cCode = 2;
		else if (cName == "US" || cName == "United States")
				/* Var (3) */	cCode = 3;
			else if (cName == "China")
					/* Var (4) */	cCode = 4;
				else
					return 0;		/* Should work similar to exit(0)								 *
									 * except for it doesn't require an extra header.				 *
									 */

	return cCode;
}
//====================================================================================================//

void countrySelect(void) {

	cout << endl << "--------------------------------------------------------------------------------";
	cout << endl << "\n\tAvailable countries are:" << endl;
	cout << "\t\t1. India," << endl;
	cout << "\t\t2. Brazil," << endl;
	cout << "\t\t3. US, and" << endl;
	cout << "\t\t4. China" << endl;
	cout << endl << "--------------------------------------------------------------------------------";
}