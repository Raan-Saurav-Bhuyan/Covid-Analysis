#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace cppMain {

	class testWhatif {

	public:

		static string pass;

		static void pass_WhatifAtBegin(string value) {

			if (value.length() == 0)	/* Default input test
										 * of the first occurence
										 * of 'whatif'.
										 */
				value = "y";

			pass = value;
		}

		static string ret_Value() {

			return pass;
		}

		int pass_WhatifAtLast(string value) {

			if (value.length() == 0 || value == "n")	/* Default input test
														 * of the last occurence
														 * of 'whatif'.
														 */
				return 1;
		}

	private:
		;
	};
}

namespace cppManual {

	class testcountryName {

	public:

		static int test_Country(string name) {

			if (name.length() == 0)
				return 0;
		}

		static string check_CountryName(string countryName) {

			string duplicate = countryName;		/* Local variable to temporarily hold the				 *
												 * string input of countryName.							 *
												 */

			//============================================================================================//
			/**
			 ** transform() function defined under the 'algorithm.h' header file						 *
			 ** is used to change the 'duplicate' string into uppercase.								 *
			 **/

			transform(duplicate.begin(), duplicate.end(), duplicate.begin(), ::toupper);

			return duplicate;
			//===========================================================================================//
		}

	private:
		;
	};
}