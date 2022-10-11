#include<iostream>
#include<queue>
#include<cstdlib>

using namespace std;

int maxServerTime = 50;

class Webserver{
	
};

class LoadBalancer{
	void process(){
		
	}
};

struct Request{
	string ipIN;
	string ipOUT;
	int time;

	Request(){

		for(int i = 0; i < 4; i++){
			ipIN += to_string(rand() % 256);
			if(i != 3){
				ipIN += "."
			}
		}

		for(int i = 0; i < 4; i++){
			ipOUT += to_string(rand() % 256);
			if(i != 3){
				ipOUT += "."
			}
		}

		time = (rand() % 50) + 1
	}
};


int main(int argc, char** argv){
	if(argc != 3){
		cout << "Incorrect Number of Arguments" << endl;
		return -1;
	}

	int servers = argv[1];
	int time = argv[2];

	queue<Request> requestqueue;

	for(int i = 0; i < servers*2; i++){
		requestqueue.push(new Request());
	}



}