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

    cout << endl << "\n\tAn initial guess for the Logistic model was found." << endl;

    /* Initial guess.                                                                            *
     */

    Kg = FF.K(C1, C2, C3);

    Ag = FF.A(mg, kg, C1, C2, C3);

    rg = FF.r(mg, C1, C2, C3);

    /* Checks if Kg is larger than the last data entered.                                        *
     */

    if ((Ag < 0) || (Kg < DATA[DATA.size() - 1])) {

        cout << "\tHowever it wasn\'t possible to find a solution!" << endl;

        if (Ag < 0) {

            cout << endl << "\tAg = " << Ag << endl;

            cout << "\tREASON: It is found that Ag < 0." << endl;
        } else if (Kg < DATA[DATA.size() - 1]) {

            cout << endl << "\tKg = " << Kg << " | ";
            cout << "Last data entry = " << DATA[DATA.size() - 1] << endl;

            cout << "\tREASON: It is found that ";
            cout << "Kg < Last data entry." << endl;
            }

        cout << endl << "--------------------------------------------------------------------------";
        cout << "------";

        retval = false;
    } else {

        cout << endl << "\n\tK(0)= " << Kg;
        cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

        cout << endl << "\n\tA(0)= " << Ag;
        cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

        cout << endl << "\n\tr(0)= " << rg;
        cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

        /* Find the time of maximum daily cases                                                  *
         */

        tp = log(Ag) / rg;

        Cp = Kg / 2;

        cout << endl << "\n\tEstimated time constant:: " << 1 / rg << " days";
        cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

        cout << endl << "\n\tEstimated time of maximum daily cases:: " << tp << "days" << endl;
        cout << "\tafter the initial day.";
        cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

        cout << endl << "\n\tEstimated maximum cases at end time:: " << Kg;
        cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

        retval = true;
    }

    return retval;
}
//================================================================================================//