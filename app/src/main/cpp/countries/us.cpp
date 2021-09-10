#include <iostream>
#include "country.h"			/* It is included in order to make the functions in this			 *
								 * source file available to other sources files using the			 *
								 * same header file.												 *
								 */

#include "covid.h"				/* Header is included to make the 'covid' class and other			 *
								 * functions accessible for the function calls.						 *
								 */

using namespace std;

bool us(void) {
	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 **                                Variable Declaration Section								     **
	 **/

			LSSD covid;			/* Variable of type class 'LSSD'.									 *
								 * Class definition available in the source file 'covid.h'.          *
								 */

			int dayLimit;		/* Variable to hold the input to limit								 *
								 * the day of the prediction table.									 *
								 */

			int m, k;			/* Variable to hold the input of m and k.							 *
								 * Definitions of m and k are given below.							 *
								 */

			float alpha;		/* Variable to hold the input for the acceleration parameter.		 *
								 * Definition available on the README.md file.						 *
								 */

			float dK, dA, dr;	/* Variable to hold the input for the parameter increment vector.	 *
								 * Definition available on the README.md file.						 *
								 */

			int month;			/* Variable to hold the number of month to analyse data.			 *
								 */

			string mName, fName;/* String to attach the abbriviation of the name					 *
								 * of the month and input file.										 *
								 */
	//================================================================================================//

	cout << endl << "\n\t\t\tINPUT SCREEN | UNITED STATES";
	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** The absolute or relative path to the file can be manually entered							 **
	 ** which is holding the data in a Comma Seperated Values (.csv) file.							 **
	 ** Please put the file inside the '/data/US/' folder.											 **
	 **/

	labelMonth:
		cout << endl << "\n\tWhich month's data to be analysed?" << endl;
	cout << "\tPlease insert the month's number: ";
	cin >> month;

	if (month == 1)
		mName = "Jan";
		else if (month == 2)
			mName = "Feb";
			else if (month == 3)
				mName = "Mar";
				else if (month == 4)
					mName = "Apr";
					else if (month == 5)
						mName = "May";
						else if (month == 6)
							mName = "June";
							else if (month == 7)
								mName = "July";
								else if (month == 8)
									mName = "Aug";
									else if (month == 9)
										mName = "Sept";
										else if (month == 10)
											mName = "Oct";
											else if (month == 11)
												mName = "Nov";
												else if (month == 12)
													mName = "Dec";
													else {
														cout << endl << "\n\tInvalid month number!";
														goto labelMonth;
													}

	cout << endl << "\n\tSelected month is " << mName << "." << endl;

	fName = "data/US/US_data(" + mName + ").csv";

	if (covid.readinputfile(fName) == false)
		return false;
	else {

		cout << endl << "-------------------------------------------------------------------------";
		cout << "-------";
	}
	//================================================================================================//

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choose the limit of daily prediction:												 **
	 ** N.B. Prediction might not be sufficient to expect the peak or inflection point.				 **
	 **/

	cout << endl << "\n\tInsert the limit of the days of prediction table" << endl;
	cout << "\t(Remember that a limit exceeding 60 days is almost meaningless): ";
	/* Input (8) */	cin >> dayLimit;

	covid.EndTime = dayLimit;
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choosing the value of m (initial data count to find initial guess):				 **
	 **/

	cout << endl << "\n\tInsert the initial data count to take into account: ";
	/* Input (1) */	cin >> m;
	//================================================================================================//

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Manually choosing the value of k (final data count to find initial guess):					 **
	 ** N.B. This should be > 2*m.																	 **
	 **/

	labelKM:
		cout << endl << "\n\tInsert the final data count to take into account:" << endl;
	cout << "\t(Remember always, k = 2*m): ";
	/* Input (2) */	cin >> k;

	if (k < 2 * m) {

		cout << endl << "\n\tYou have entered an invalid value!";
		/* Jump (1) */	goto labelKM;
	}
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Pre-configuring the acceleration parameter alpha:											 **
	 ** N.B. This should always be < 1.																 **
	 **/

	cout << endl << "\n\t|\\\tDefault Acceleration Parameter\t\t/|" << endl;

	/* Const (1) */	alpha = 0.5;
	if (alpha >= 1) {

		cout << endl << "\n\talpha should not be > 1!";

		return false;
	} else
		cout << endl << "\n\t\tAlpha = " << alpha;

	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Pre-configuring the parameter increment vectors.											 **
	 ** dK and dA < 1; and dr should always be << 1.												 **
	 **/

	cout << endl << "\n\t|\\\tDefault Paramter Increment Vectors\t/|" << endl;

	/* Const (2) */	dK = 0.1;
	if (dK >= 1) {

		cout << endl << "\n\tdK should not be >= 1!";

		return false;
	} else
		cout << endl << "\n\t\tdK = " << dK;

	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

	/* Const (3) */	dA = 0.001;
	if (dA >= 1) {

		cout << endl << "\n\tdA should not be >= 1!";

		return false;
	} else
		cout << endl << "\n\t\tdA = " << dA;

	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

	/* Const (4) */	dr = 1e-7;
	if (dr >= 1e-3) {

		cout << endl << "\n\tdr should not be >= 1e-3!";

		return false;
	} else
		cout << endl << "\n\t\tdr = " << dr;

	cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	//================================================================================================//

	cout << endl << "--------------------------------------------------------------------------------";

	//================================================================================================//
	/**----------------------------------------------------------------------------------------------**
	 ** Function FindInitialGuess from class type 'covid':											 **
	 ** It takes m and k as input parameters.														 **
	 ** Function definition is on the source file 'guess.cpp'.										 **
	 **/

	if (covid.FindInitialGuess(m, k)) {
		//============================================================================================//
		/**------------------------------------------------------------------------------------------**
		 ** Function calls made:																	 **
		 ** 1. Logistic()																			 **
		 ** 2. dLogistic()																			 **
		 ** 3. VarNcases()																			 **
		 ** 4. steepestdescent()																	 **
		 ** 5. writeoutput()																		 **
		 ** 6. writeprediction()																	 **
		 **/

		 /*														 									 *
		  * Calculate the forecast for the total number of cases 									 *
		  * and daily variation.								 									 *
		  */

		/* fn (1) */    covid.Logistic();
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/* fn (2) */    covid.dLogistic();
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/* Var (1) */   covid.varN = covid.VarNcases();
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/* Out (1) */   cout << endl << "\n\tEstimated VAR:: " << covid.varN;

		cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		cout << endl << "-------------------------------------------------------------------------";
		cout << "-------";

		/* Out (2) */   cout << endl << "\n\tEstimated dispersion s(0):: " << sqrt(covid.varN);

		cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		cout << endl << "-------------------------------------------------------------------------";
		cout << "-------";
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		covid.steepestDescent(alpha, dK, dA, dr);	//Minimize s2
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/*																							 *
		 * Calculate new forecast for the optimized solution, total number of cases and				 *
		 * daily variation																			 *
		 */

		/* fn (1) */    covid.Logistic();
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/* fn (2) */    covid.dLogistic();
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/* Var (1) */   covid.varN = covid.VarNcases();
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/* Out (1) */   cout << endl << "\n\tFinal VAR:: " << covid.varN;

		cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		cout << endl << "-------------------------------------------------------------------------";
		cout << "-------";

		/* Out (2) */   cout << endl << "\n\tFinal dispersion:: " << sqrt(covid.varN);

		cout << endl << "\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		cout << endl << "-------------------------------------------------------------------------";
		cout << "-------";
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

		/*																							 *
		 * Filenames for the output.																 *
		 */

		string postfix1 = "result/US/logistic_output_US(" + mName + ").txt";
		string csvSave1 = "excel/US/logistic_output_US(" + mName + ").csv";

		cout << endl << "\n\t\"*.txt\" formatted output file is saved as: " << endl;
		cout << "\t\"" << postfix1 << "\"" << endl;
		/* File (1) */  covid.writeOutput(postfix1);		//*.txt

		cout << endl << "\t\"*.csv\" formatted ouput file is saved as: " << endl;
		cout << "\t\"" << csvSave1 << "\"";
		/* File (2) */	covid.writeOutCsv(csvSave1);		//*.csv

		/*																							 *
		 * Filenames for the prediction.															 *
		 */

		string postfix2 = "result/US/logistic_pred_US(" + mName + ").txt";
		string csvSave2 = "excel/US/logistic_pred_US(" + mName + ").csv";

		cout << endl << "\n\t\"*.txt\" formatted prediction file is saved as: " << endl;
		cout << "\t\"" << postfix2 << "\"" << endl;
		/* File (3) */  covid.writePrediction(postfix2);	//*.txt

		cout << endl << "\t\"*.csv\" formatted prediction file is saved as: " << endl;
		cout << "\t\"" << csvSave2 << "\"";
		/* File (4) */	covid.writePredCsv(csvSave2);		//*.csv

		cout << endl << "-------------------------------------------------------------------------";
		cout << "-------";

		cout << endl << "\n\tOpening the folder to *.csv files ... ...";
		system("explorer excel\\US\\");		//Opens the folder
		//============================================================================================//
	}
	//================================================================================================//

	return true;
}