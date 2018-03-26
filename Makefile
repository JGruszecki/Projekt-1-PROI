program: functions.o main.o	
	g++ functions.o main.o -o program

functions.o: functions.cpp matrix.h
	g++ -Wall functions.cpp -c -o functions.o

main.o: main.cpp matrix.h
	g++ -Wall main.cpp -c -o main.o

clean:
	rm -f program main.o functions.o

run:
	./program