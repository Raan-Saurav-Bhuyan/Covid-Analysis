#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<time.h>
#include<vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include<math.h>
#include<complex>
#include <valarray>

#define _USE_MATH_DEFINES

using namespace std;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
/**++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++**
 **										    ||		CREDIT		||												 **
 **										Estimating the COVID-19 evolution										 **
 **                             using the Logistic Model, A Xavier Jr, March 2020								 **
 **										 Brazilian Space Agency, Brazil											 **
 **/

const int max_iter = 100000;	/* maximum number of iterations													 *
								 */
class tools {
	private:
		;
	public:
		/* Src (/functions/equations.cpp) */

			float Ncases(int jx, float Kx, float Ax, float rx);

			float dNcases(int jx, float Kx, float Ax, float rx);
		
			float K(float C1, float C2, float C3);

			float A(float m, float jx, float C1, float C2, float C3);

			float r(float m, float C1, float C2, float C3);

			float dNdK(int tx, float Kx, float Ax, float rx);

			float dNdA(int tx, float Kx, float Ax, float rx);

			float dNdr(int tx, float Kx, float Ax, float rx);
};
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
/**++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++**
 ** Class Least Squares Steepest Descent (LSSD)																	 *
 **/
class LSSD{
	private:
		;
	public:

		//int and float variables
		int EndTime;

		float C1, C2, C3, Kg, Ag, rg, kg, mg;	/* C1, C2 and C3 are the three numbers M(k-2m), M(k-m) and		 *
												 * M(k) for calculating the input guess of the Logistic model.	 *
												 */

		float tp, Cp;							/* tp - time of maximum number of daily cases (Eq. 6),			 *
												 * Cp - number of cases at tp, equal to K/2.					 *
												 */
		float varN;

		//vector variables
		vector<float> DATA, dDATA;				/* DATA contains the series of input data.						 *
												 * dDATA' containing the daily number of cases.					 *
												 */

		
		vector<float> NcLog, dNcLog;			/* NcLog, dNcLog - contain the forecast of the model			 *
												 * for the total and the daily number of cases.					 *
												 */
  
		//tools variable
		tools FF;

		/* Src (/functions/s-two.cpp) */

			float VarNcases();

			float dRdK();

			float dRdA();

			float dRdr();

		/* Src (/functions/logs.cpp) */

			void Logistic();				/* Logistic() updates NcLog with the model forecast.				 *
											 */

			void dLogistic();				/* dLogistic() updates dNcLog with the model forecast.				 *
											 */

		/* Src (/functions/guess.cpp)*/

			bool FindInitialGuess(int m, int k);

		/* Src (/functions/lssd.cpp) */

			void steepestDescent(float alpha, float dKx, float dAx, float drx);
  
		/* Src (read-write.cpp) */

			bool readinputfile(string filenamex);

			void writeOutput(string filenamex);

			void writeOutCsv(string filenamex);

			void writePrediction(string filenamex);

			void writePredCsv(string filenamex);
};
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
