#include <cassert>
using namespace std;

//For testing purposes.
#include "../../main/test-headers/test-main.h"
using namespace cppMain;

/* Other source files test function definitions.
 */

void manual();

/* Main source file test body.
 */

void main() {

	testWhatif maintest;

	string whatif;
	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//
	/**_____________________________________________________________________________**
	 ** To test the default input of the first occurence of
	 ** the variable 'whatif'.
	 **/

	testWhatif::pass_WhatifAtBegin(whatif);

	cout << "------------------------------------------------" << endl;
	cout << endl << "Whatif test >> Source: main.cpp" << endl;

	cout << endl << "\nCondition (1): Expected value of whatif: y" << endl;
	cout << "Returned value of whatif: " << testWhatif::ret_Value() << endl;

	assert(testWhatif::ret_Value().compare("y") == 0);
	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//

	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//
	/**_____________________________________________________________________________**
	 ** To test the default input of the last occurence of
	 ** the variable 'whatif'.
	 **/

	cout << endl << "\nCondition (2): Expected value to return : 1" << endl;
	cout << "Actual Value returned: " << maintest.pass_WhatifAtLast(whatif) << endl;

	assert(maintest.pass_WhatifAtLast(whatif) == 1);

	cout << "------------------------------------------------" << endl;
	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//

	manual();	//manual.cpp
}