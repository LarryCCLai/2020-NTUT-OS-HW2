IF NOT EXIST bin mkdir bin 
cd bin
g++ -std=c++11 -c ../Forloop.cpp 
g++ -std=c++11 -c ../Matrix.cpp 
g++ -std=c++11 -c ../Matrix.h -o ./Matrix.gch
g++ -std=c++11 -c ../multithreading.cpp 
g++ -std=c++11 -c ../main.cpp 
g++ -o ../run.exe main.o Matrix.o multithreading.o Forloop.o