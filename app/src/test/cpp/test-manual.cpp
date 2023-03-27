#include <cassert>
using namespace std;

//For testing purposes.
#include "../../main/test-headers/test-main.h"
using namespace cppManual;

void manual() {
	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//
	/**_____________________________________________________________________________**
	 ** To test the response of the first occurence of the
	 ** variable 'countryName' in case of no input is received.
	 **/
	string countryName;

	cout << endl << "countryName test >> Source: /countries/manual.cpp" << endl;

	cout << endl << "\nCondition (1): Expected return value: 0" << endl;
	cout << "Actual value returned: " << testcountryName::test_Country(countryName) << endl;

	assert(testcountryName::test_Country(countryName) == 0);
	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//

	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//
	/**_____________________________________________________________________________**
	 ** To test the response of the variable 'countryName'
	 ** if the name has been capitalized or not.
	 **/
	countryName = "Britain";

	cout << endl << "\nCondition (2): Expected value of duplicate: 'BRITAIN'" << endl;
	cout << "Returned value of duplicate: " << testcountryName::check_CountryName(countryName) << endl;

	assert(testcountryName::check_CountryName(countryName).compare("BRITAIN") == 0);

	cout << "------------------------------------------------" << endl;
	//<><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><>//
}