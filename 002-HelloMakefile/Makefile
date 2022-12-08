# syntax
# [target]: [dependencies...]
# 	[action]
# must use tab to indent the [action]

output: main.o class1.o
	g++ main.o class1.o -o main.exe 

main.o: main.cpp
	g++ -c main.cpp

class1.o: class1.cpp class1.h
	g++ -c class1.cpp

clean:
	rm *.o main.exe

# delete products, using in windows
cleanw:
	del *.o main.exe