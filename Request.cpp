#include<cstdlib>
#include <string>
#include "Request.h"

using namespace std;


/*!
 * \brief Populates instance variables with Random In IP Address, Random Out IP Address, and Random Time to Complete Request.
 * \param min Minimum time of random generated request
 * \param max Maximum time of random generated request
*/
Request::Request(int min, int max){
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

	time = rand()%(max-min + 1) + min;
}


