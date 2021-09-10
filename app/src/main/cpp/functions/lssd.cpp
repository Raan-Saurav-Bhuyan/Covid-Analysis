#include <iostream>
#include "covid.h"      /* Header is included to make the 'covid' class and other functions		 *
						 * accessible for the function calls.									 *
						 */

using namespace std;

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** minimize the residue s2 and find a better estimate for K, A and r                            **
 ** using the Steepest Descent method.                                                           **
 ** The iteration parameters are given externaly by alphax, dKx, dAx and drx.                    **
 **/
void LSSD::steepestDescent(float alphax, float dKx, float dAx, float drx) {
    float R0, R;

    float dK, dA, dr, alpha;

    int iter = 0;

    alpha = alphax;         /* acceleration parameter                                            *
                             */
    dK = dKx;

    dA = dAx;

    dr = drx;

    R0 = VarNcases();       /* Find the initial dispersion.                                      *
                             */

    cout << endl << "\n\t";

    for (int j = 0; j < max_iter; j++) {

        /* calculating the gradients                                                             *
         */

        Kg -= dRdK() * dK * alpha;

        Ag -= dRdA() * dA * alpha;

        rg -= dRdr() * dr * alpha;

        R = VarNcases();

        
        /* if the actual dispersion is smaller than the previous,                                *
         * then update previous value.                                                           *
         */
        if (R < R0) {

            R0 = R;

            cout << "\r" << "Iteration " << j << " | K= " << Kg << " | A= " << Ag;
            cout << " | r= " << rg << " | Residue= " << R;

            iter = j;
        }
        else
            break;
    }

    cout << endl << "-------------------------------------------------------------------------";
    cout << "-------";

    cout << endl << "\n\t\t\tConverged values" << endl;
    cout << "\t\t================================" << endl;

    cout << endl << "\n\tK(" << iter << ")= " << Kg;

    cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

    cout << endl << "\n\tA(" << iter << ")= " << Ag;

    cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

    cout << endl << "\n\tr(" << iter << ")= " << rg;

    cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

    tp = log(Ag) / rg;

    Cp = Kg / 2;

    cout << endl << "\n\tTime constant:: " << 1 / rg << " days.";

    cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

    cout << endl << "\n\tExpected final time of maximum daily cases:: " << endl;
    cout << "\t" << tp << " days after the initial day.";

    cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

    cout << endl << "\n\tExpected final maximum number of cases:: " << Kg;

    cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
}