output: LoadBalancer.o Request.o Webserver.o
	g++ LoadBalancer.o Request.o Webserver.o -o a.out

LoadBalancer.o: LoadBalancer.cpp
	g++ -c LoadBalancer.cpp 

Request.o: Request.cpp
	g++ -c Request.cpp 

Webserver.o: Webserver.cpp
	g++ -c Webserver.cpp 

clean:
	rm *.o a.out