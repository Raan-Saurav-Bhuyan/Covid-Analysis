#include <iostream>
#include "covid.h"      /* Header is included to make the 'covid' class and other functions		 *
						 * accessible for the function calls.									 *
						 */

using namespace std;

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** Function to find the initial parameter before optimization.                                  **
 ** The initial guess is (Kg, Ag,, rg) using mg and kg externally given.                         **
 **/
bool LSSD::FindInitialGuess(int mx, int kx) {

    bool retval;

    mg = (float)mx;

    kg = (float)kx;

    C1 = DATA[kg - 2 * mg];

    C2 = DATA[kg - mg];

    C3 = DATA[kg];

    cout << endl << "\n\tAn initial guess for the Logistic model was found..." << endl;

    /* Initial guess                                                                             *
     */

    Kg = FF.K(C1, C2, C3);

    Ag = FF.A(mg, kg, C1, C2, C3);

    rg = FF.r(mg, C1, C2, C3);

    /* Checks if Kg is larger than the last data entered.                                        *
     */

    if ((Ag < 0) || (Kg < DATA[DATA.size() - 1])) {

        cout << endl << "\n\tIt wasnt possible to find a solution..." << endl;

        retval = false;
    }
    else {
        cout << endl << "\n\tK(0)=" << Kg << endl;
        cout << endl << "\n\tA(0)=" << Ag << endl;
        cout << endl << "\n\tr(0)=" << rg << endl;

        /* Find the time of maximum daily cases                                                  *
         */

        tp = log(Ag) / rg;

        Cp = Kg / 2;

        cout << endl << "\n\tEstimated time constant::" << 1 / rg << " days" << endl;
        cout << endl << "\n\tEstimated time of maximum::" << tp << " days after the initial day" << endl;
        cout << endl << "\n\tEstimated maximum cases at end time::" << Kg << endl;
        retval = true;
    }
    return retval;
}
//================================================================================================//