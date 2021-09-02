#include <iostream>
#include "covid.h"      /* Header is included to make the 'covid' class and other functions		 *
						 * accessible for the function calls.									 *
						 */

using namespace std;

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** minimize the residue s2 and find a better estimate for K, A and r                            **
 ** using the Steepest Descent method.                                                           **
 ** The iteration parameters are given externaly by alphax, dKx, dAx and drx                     **
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
    for (int j = 0; j < max_iter; j++) {

        /* calculating the gradients                                                             *
         */

        Kg -= dRdK() * dK * alpha;

        Ag -= dRdA() * dA * alpha;

        rg -= dRdr() * dr * alpha;

        R = VarNcases();

        
        /* if the actual dispersion is smaller than the previous                                 *
         * update previous value                                                                 *
         */
        if (R < R0) {

            R0 = R;

            cout << "\r" << "iter " << j << " K=" << Kg << " A=" << Ag << " r=" << rg << " Residue= " << R;

            iter = j;
        }
        else
            break;
    }

    cout << endl << "Converged values" << endl;
    cout << "===========================" << endl;
    cout << endl << "K(" << iter << ")=" << Kg << endl;
    cout << endl << "A(" << iter << ")=" << Ag << endl;
    cout << endl << "r(" << iter << ")=" << rg << endl;

    tp = log(Ag) / rg;

    Cp = Kg / 2;

    cout << endl << "Time constant::" << 1 / rg << " days" << endl;
    cout << endl << "Final time of maximum daily cases::" << tp << " days after the initial day" << endl;
    cout << endl << "Final expected maximum number of cases::" << Kg << endl;
}