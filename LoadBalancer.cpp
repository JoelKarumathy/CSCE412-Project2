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
*/

#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include <ctime>

#include "Request.h"
#include "Webserver.h"

using namespace std;



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

	//int startingQueueSize = servers*2;
	int startingQueueSize = 500;

	for(int i = 0; i < startingQueueSize; i++){
		requestqueue.push(new Request());
	}

	int iteration = 0;

	cout << "Starting with queue size " + to_string(requestqueue.size())  << endl;

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
			requestqueue.push(new Request());
			timeToNextRequest = rand() % 5 + 1;
		}

		iteration++;
	}

	cout << "Finished at time " + to_string(iteration) + " with queue size " + to_string(requestqueue.size())  << endl;

}


