#include <iostream>
#include "covid.h"      /* Header is included to make the 'covid' class and other functions		 *
						 * accessible for the function calls.									 *
						 */

using namespace std;

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** calculating the s2(Eq. 8) for the modeland data.                                             **
 **/
float LSSD::VarNcases() {

    float temp = 0;

    float N;

    for (int i = 0; i < DATA.size(); i++) {

        N = FF.Ncases(i, Kg, Ag, rg);

        temp += (DATA[i] - N) * (DATA[i] - N);
    }

    return temp / DATA.size();
}
//================================================================================================//

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** Derivative of s2 with respect to K, (Eq. 10).                                                **
 **/
float LSSD::dRdK() {

    float temp = 0;

    float N, dN;

    for (int i = 0; i < DATA.size(); i++) {

        N = FF.Ncases(i, Kg, Ag, rg);

        dN = FF.dNdK(i, Kg, Ag, rg);

        temp += (DATA[i] - N) * dN;
    }

    return -2. * temp / DATA.size();
}
//================================================================================================//

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** Derivative of s2 with respect to A, (Eq. 10).                                                **
 **/
float LSSD::dRdA() {

    float temp = 0;

    float N, dN;

    for (int i = 0; i < DATA.size(); i++) {

        N = FF.Ncases(i, Kg, Ag, rg);

        dN = FF.dNdA(i, Kg, Ag, rg);

        temp += (DATA[i] - N) * dN;
    }

    return -2. * temp / DATA.size();
}
//================================================================================================//

//================================================================================================//
/**----------------------------------------------------------------------------------------------**
 ** Derivative of s2 with respect to r, (Eq. 10).                                                **
 **/
float LSSD::dRdr() {

    float temp = 0;

    float N, dN;

    for (int i = 0; i < DATA.size(); i++) {

        N = FF.Ncases(i, Kg, Ag, rg);

        dN = FF.dNdr(i, Kg, Ag, rg);

        temp += (DATA[i] - N) * dN;
    }

    return -2. * temp / DATA.size();
}
//================================================================================================//