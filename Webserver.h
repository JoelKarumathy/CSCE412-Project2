#ifndef WEBSERVER_H 
#define WEBSERVER_H

#include "Request.h"

class Webserver{
	public:
		int start_time; //!< Time in which Webserver object has started fulfilling a Request object
		Request* request; //!< Pointer to current Request object that is being fulfilled by server
		bool startUp; //!< Flag that indicates first use of Webserver

	
		Webserver();
		void assignRequest(int curr_time, Request* req, int webserver_num);
		bool free(int curr_time);

};

#endif