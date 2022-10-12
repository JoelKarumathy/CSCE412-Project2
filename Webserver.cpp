#include<iostream>
#include <string>
#include "Webserver.h"
#include "Request.h"

using namespace std;

/*!
 * \brief Constructs Webserver Object
 * \details Sets instance variable startUp to true
*/
Webserver::Webserver(){
	startUp = true;
}

/*!
 * \brief Assigns a Request Object to Webserver instance
 * \param curr_time Time iteration of loop in load balancer class
 * \param req Pointer to request that will be fulfilled by Webserver instance
 * \param webserver_num The id number of the current Webserver instance
 * \details Assigns curr_time and req to associated instance variables(start_time and request). Prints to stdout that request has been assigned.
*/
void Webserver::assignRequest(int curr_time, Request* req, int webserver_num){
	start_time = curr_time;
	request = req;
	cout << "At time " + to_string(curr_time) + " assigned request " + request->ipIN + " of processing time " + to_string(request->time) + " to Web Server " + to_string(webserver_num) << endl;
}

/*!
 * \brief Checks if Webserver instance is free to fulfill Request
 * \param curr_time Time iteration of loop in load balancer class
 * \details Checks if startUp is true, indicating that the Webserver is free. startUp is subsequently changed to false as Webserver has started processing requests.
 * Returns true if Webserver has finished fullfilling current request. Returns false if there is still time left to complete current request.
 * Function will print to stdout when Request has been fullfilled. 
*/
bool Webserver::free(int curr_time){
	if(startUp){
		startUp = false;
		return true;
	}
	else if(!request){
		return true;
	}
	else if(curr_time - start_time > request->time){
		delete request;
		request = nullptr;
		return true;
	}
	else if(curr_time - start_time == request->time){
		cout << "At time " + to_string(curr_time) + " processed request from " + request->ipIN + " to " + request->ipOUT << endl;
	}
	return false;
}



