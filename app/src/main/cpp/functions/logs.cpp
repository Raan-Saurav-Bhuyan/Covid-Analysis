#include <iostream>
#include "covid.h"      /* Header is included to make the 'covid' class and other functions		 *
						 * accessible for the function calls.									 *
						 */

using namespace std;

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** NcLog vector contains the Logistic model (vector of EndTime-1 elements)						 **
 **/
void LSSD::Logistic() {

	for (int i = 0; i <= EndTime; i++)
		NcLog.push_back(FF.Ncases(i, Kg, Ag, rg));
}
//================================================================================================//

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** dNcLog vector contains the derivative of the												 **
 ** Logistic model (vector of EndTime-1 elements)												 **
 **/

void LSSD::dLogistic() {

	for (int i = 1; i <= EndTime; i++)
		dNcLog.push_back(FF.dNcases(i, Kg, Ag, rg));
}
//================================================================================================//