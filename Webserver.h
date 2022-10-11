#ifndef WEBSERVER_H 
#define WEBSERVER_H

#include "Request.h"

class Webserver{
	private:
		int start_time;
		Request* request;
		bool startUp;

	public:
		Webserver();
		void assignRequest(int curr_time, Request* req, int webserver_num);
		bool free(int curr_time);

};

#endif