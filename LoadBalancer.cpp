/*!
 * \author Joel Karumathy
 *
 * \date October 11, 2022
 *
 * \mainpage CSCE 412 Project 2
 * \section Introduction
 * In this project, we model a simulation of a large company load balancing web requests using a load balancer.
 * \section run_section Running The Program
 * To compile this program run `make` in the project root directory.
 * To run the compiled code run `./a.out {Number of Servers} {Number of Clock Cycles}`.
 * \section code_structure Code Structure
 * The Request class generates random IP addresses, both in and out, and random times for each request to be processed.
 * The Webserver class takes requests from the Load Balancer(main function) and processes the requests.
 * The main function located in LoadBalancer.cpp keeps a queue of request objects, keeps track of clock cycles, and assigns requests to a Webserver. 
*/

#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include <ctime>

#include "Request.h"
#include "Webserver.h"

using namespace std;


/*!
 * \brief Main Function which acts as load balancer by assigning requests to web servers
 * \param argc Number of arguments passed to program
 * \param argv List of arguments passed to program
 * \details The main function first obtains the number of web servers and total time iterations through command line input. 
 * Next, the function initializes the inputted number of web servers and fills a queue with a defined number of requests.
 * The function then iterates through a while loop in which each iteration represents a single tick. The while loop will last as long as specified by the user input.
 * In each iteration, each web server will be checked. If the server is free, it will be assigned a request. 
 * If all web servers are free and the queue of requests is empty before the while loop iterations are completed, the program will exit.
*/
int main(int argc, char** argv){
	srand(time(NULL));

	if(argc != 3){
		cout << "Incorrect Number of Arguments" << endl;
		return -1;
	}

	int servers = atoi(argv[1]);
	int time = atoi(argv[2]);

	vector<Webserver*> webservers;

	for(int i = 0; i < servers; i++){ 
		webservers.push_back(new Webserver());
	}

	queue<Request*> requestqueue;

	int startingQueueSize = 500;
	int min_time_request = 2;
	int max_time_request = 500;

	for(int i = 0; i < startingQueueSize; i++){
		requestqueue.push(new Request(min_time_request, max_time_request));
	}

	int iteration = 0;

	cout << "Starting with queue size " + to_string(requestqueue.size())  << endl;
	cout << "Range for task times: " << min_time_request << "-" << max_time_request << endl;

	int timeToNextRequest = rand() % 5 + 1;

	while(iteration < time){
		bool allWebserversFree = true;
		for(int i = 0; i < webservers.size(); i++){
			if(webservers[i]->free(iteration)){
				if(requestqueue.empty()){
					continue;
				}
				webservers[i]->assignRequest(iteration, requestqueue.front(), i+1);
				requestqueue.pop();
			}else{
				allWebserversFree = false;
			}

		}
		
		

		if(requestqueue.empty() && allWebserversFree){
			cout << "Finished at time " + to_string(iteration) + " wite queue size 0" << endl;
			for(int i = 0; i < servers; i++){ 
				delete webservers[i];
			} 
			return 0;
		}

		if(--timeToNextRequest == 0){
			requestqueue.push(new Request(min_time_request, max_time_request));
			timeToNextRequest = rand() % 5 + 1;
		}

		iteration++;
	}

	cout << "Finished at time " + to_string(iteration) + " with queue size " + to_string(requestqueue.size())  << endl;

}


