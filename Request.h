#ifndef REQUEST_H 
#define REQUEST_H

#include <string>

using namespace std;

/**
 * \class
 * Generates random IP addresses, both in and out, and random times for each request to be processed.
 */
class Request{
	public:
		string ipIN; //!< Randomly generated IP address for intake
		string ipOUT; //!< Randomly generated IP address to be returned
		int time; //!< Time to complete request

		Request(int min, int max);

};


#endif