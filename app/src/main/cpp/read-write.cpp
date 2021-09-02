#include <iostream>
#include "covid.h"      /* Header is included to make the 'covid' class and other functions				 *
						 * accessible for the function calls.											 *
						 */

using namespace std;

//========================================================================================================//
/**------------------------------------------------------------------------------------------------------**
 ** This function reads input file filenamex                                                             **
 ** and save into DATA[] and dDATA[]                                                                     **
 **/

void LSSD::readinputfile(string filenamex) {
    //================================================================================================//
    /**----------------------------------------------------------------------------------------------**
     **                              Variable Declaration Section                                    **
     **/
        
        string line;                   /*                                                            *
                                        * Variable to catch individual lines on the                  *
                                        * Comma Separated Values (.csv) file,                        *
                                        * To evaluate in a 'while' loop.                             *
                                        */
        
        vector<string> lines;          /*                                                            *
                                        * Variable to hold the valid lines                           *
                                        * after the evaluation.                                      *
                                        */   
            
        int linecounter = 0;           /*                                                            *
                                        * To count the total number of lines to be read and written. *
                                        */
            
        string field;                  /*                                                            *
                                        * Variable to hold data in each of the lines.                *
                                        */
            
        ifstream myfile(filenamex);    /*                                                            *
                                        * To open the file and convert it to *char                   *
                                        */
    //================================================================================================//
        
    //================================================================================================//
    /**----------------------------------------------------------------------------------------------**
        ** Checks if there is any comment line, and skips it.                                        *
        ** After completion, valid lines are saved in lines.                                         *
        **/
    if (myfile.is_open()) {
        cout << endl << "->>>> Open input file::" << filenamex << endl;

        while (getline(myfile, line)) {
                
                if (line.substr(0, 1) != "#") {    /* Skip lines starting with '#' and               *
                                                    * Push back valid line in lines                  *
                                                    */
                    lines.push_back(line);
                }
        }
            
        /* After completion, the file should be closed as precaution to avoid                        *
            * overwriting it.                                                                        *
            */
            myfile.close();
    }
    //================================================================================================//

    for (int i = 0; i < lines.size(); i++) {
        field = lines[i].substr(lines[i].find(";") + 1, lines[i].length());
            
        DATA.push_back((float)stof(field));        /* Push back data to the 'DATA' vector            *
                                                    * from valid lines.                              *
                                                    */
    }
        
    dDATA.push_back(DATA[1] - DATA[0]);            /* Find the daily difference keeping              *
                                                    * the same size of the                           *
                                                    * original data, in a manner of                  *
                                                    * value 0 = value 1                              *
                                                    */
    for (int i = 1; i < lines.size(); i++) {
        dDATA.push_back(DATA[i] - DATA[i - 1]);
    }
}
//========================================================================================================//

//========================================================================================================//
/**------------------------------------------------------------------------------------------------------**
 ** writing model and input data (including daily change) for the data time span                         ** 
 **/

void LSSD::writeoutput(string filenamex) {
    ofstream myfile(filenamex);    //opens file
        
    cout << "Saving output::" << filenamex << endl;
    myfile << "day, Ncsimul, Ncases, dNcsimul, dNcases "<< endl;       /* There will be five columns    *
                                                                        * in the output file for        *
                                                                        * daily cases.                  *
                                                                        */
        
    for (int i = 0; i < DATA.size(); i++) {
            
           /* Inserts data into the file with name logistic_output_<country name>.csv.                  *
            */
        myfile << i+1 << "," << NcLog[i] << "," << DATA[i] << "," << dNcLog[i] << "," << dDATA[i] << endl;
    }
    myfile.close();    //closes file
}
//========================================================================================================//

//========================================================================================================//
/**------------------------------------------------------------------------------------------------------**
 ** writing model and input data (including daily change) up to EndTime                                  **
 **/

void LSSD::writeprediction(string filenamex) {
    ofstream myfile(filenamex); //opens file
        
    cout << "Saving prediction file::" << filenamex << endl;
    myfile << "day, Ncsimul, dNcsimul" << endl;        /* There will be three columns in the output     *
                                                        * file for daily predictions.                   *
                                                        */
        
    for (int i = 0; i < EndTime; i++) {
            
           /* Inserts data into the file with name lolgistic_pred_<country name>.csv                    *
            */
        myfile << i+1 << "," << NcLog[i] << "," << dNcLog[i] << endl;
    }
    myfile.close();    //closes file
}
//========================================================================================================//
