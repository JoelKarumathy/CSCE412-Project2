#include<cstdlib>
#include <string>
#include "Request.h"

using namespace std;


/*!
 * \brief Populates instance variables with Random In IP Address, Random Out IP Address, and Random Time to Complete Request.
*/
Request::Request(){
	for(int i = 0; i < 4; i++){
		ipIN += to_string(rand() % 256);
		if(i != 3){
			ipIN += ".";
		}
	}

	for(int i = 0; i < 4; i++){
		ipOUT += to_string(rand() % 256);
		if(i != 3){
			ipOUT += ".";
		}
	}

	time = (rand() % 499) + 2;
}


