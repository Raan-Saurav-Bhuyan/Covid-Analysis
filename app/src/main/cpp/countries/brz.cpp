#include <iostream>
#include "country.h"			/* It is included in order to make the functions in this			 *
								 * source file available to other sources files using the			 *
								 * same header file.												 *
								 */

using namespace std;

bool brazil(void) {
	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 **                                Variable Declaration Section								     **
	 **/
			 //TODO: remove comment from "LSSD covid;"
			 /*LSSD covid;*/	/* Variable of type class 'LSSD'.									 *
								 * Class definition available in the source file 'covid.h'.          *
								 */

			int dayLimit;		/* Variable to hold the input to limit								 *
								 * the day of the prediction table.									 *
								 */

			int m, k;			/* Variable to hold the input of m and k.							 *
								 * Definitions of m and k are given below.							 *
								 */

			float alpha;		/* Variable to hold the input for the acceleration parameter.		 *
								 * Definition available on the README.md file.						 *
								 */

			float dK, dA, dr;	/* Variable to hold the input for the parameter increment vector.	 *
								 * Definition available on the README.md file.						 *
								 */
	//================================================================================================//

	cout << endl << "\n\t\t\t  INPUT SCREEN | BRAZIL";
	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** The absolute or relative path to the file can be manually entered							 **
	 ** which is holding the data in a Comma Seperated Values (.csv) file.							 **
	 ** Please put the file inside the '/app/build/exe/main/debug/data/' folder						 **
	 **/

	 //TODO: remove comment from covid.readinputfile()
	 //covid.readinputfile /* Enter file inside braces (): */(/data/India/<file name>);
	 //================================================================================================//

	 //================================================================================================//
	 /**----------------------------------------------------------------------------------------------**
	  ** Manually choose the limit of daily prediction:												  **
	  ** N.B. Prediction might not be sufficient to expect the peak or inflection point.			  **
	  **/

	cout << endl << "\n\tInsert the limit of the days of prediction table" << endl;
	cout << "\t(Remember that a limit exceeding 60 days is almost meaningless): ";
	/* Input (8) */	cin >> dayLimit;

	//TODO: remove comment from covid.EndTime
	//covid.EndTime = dayLimit;
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

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
		cout << endl << "\n\tInsert the final data count to take into account:" << endl;
	cout << "\t(Remember always, k = 2*m): ";
	/* Input (2) */	cin >> k;

	if (k < 2 * m) {
		cout << endl << "\n\tYou have entered an invalid value!";
		/* Jump (1) */	goto labelKM;
	}
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Pre-configuring the acceleration parameter alpha:											 **
	 ** N.B. This should always be < 1.																 **
	 **/

	cout << endl << "\n\t|\\\tDefault Acceleration Parameter\t\t/|" << endl;
	/* Const (1) */	alpha = 0.5;

	if (alpha >= 1) {
		return false;
	}
	else {
		cout << endl << "\n\t\tAlpha = " << alpha;
	}
	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Pre-configuring the parameter increment vectors												 **
	 ** dK, dA, and dr should always be << 1														 **
	 **/

	cout << endl << "\n\t|\\\tDefault Paramter Increment Vectors\t/|" << endl;

	/* Const (2) */	dK = 1e-9;
	if (dK >= 1e-3) {
		return false;
	}
	else {
		cout << endl << "\n\t\tdK = " << dK;
	}
	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

	/* Const (3) */	dA = 1e-8;
	if (dA >= 1e-3) {
		return false;
	}
	else {
		cout << endl << "\n\t\tdA = " << dA;
	}
	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

	/* Const (4) */	dr = 1e-7;
	if (dr >= 1e-3) {
		return false;
	}
	else {
		cout << endl << "\n\t\tdr = " << dr;
	}
	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	return true;
}