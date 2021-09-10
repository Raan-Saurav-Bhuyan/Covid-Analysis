#include <iostream>

using namespace std;

int country(void);				/* country() function is used to determine which pre-configured country to		 *
								 * evaluate and returns it's country code to the main() function				 *
								 * which later will start the related function for the required country.
								 */

void countrySelect(void);		/* Just a function to show available countries in case needed.					 *
								 */

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
/**++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++** 
 ** Below are some bolean functions to start the process of evaulation of covid									 **
 ** cases in the required country and returns whether the process												 **
 ** was successful or a failure.
 **/

int manConfig(void);
bool india(void);
bool brazil(void);
bool us(void);
bool china(void);
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//