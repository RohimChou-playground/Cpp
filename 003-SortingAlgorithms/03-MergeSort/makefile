output: main.o
	g++ main.o -o main.exe 

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o main.exe

# delete products, using in windows
cleanw:
	del *.o main.exe