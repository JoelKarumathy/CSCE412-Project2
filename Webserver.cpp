#include<iostream>
#include <string>
#include "Webserver.h"
#include "Request.h"

using namespace std;

Webserver::Webserver(){
	startUp = true;
}

void Webserver::assignRequest(int curr_time, Request* req, int webserver_num){
	start_time = curr_time;
	request = req;
	cout << "At time " + to_string(curr_time) + " assigned request " + request->ipIN + " of processing time " + to_string(request->time) + " to Web Server " + to_string(webserver_num) << endl;
}

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



