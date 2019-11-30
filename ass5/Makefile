CXX=clang++

Q1.o: Q1.cpp Q1.hpp
	$(CXX) -c Q1.cpp

Q1: Q1.o
	$(CXX) -o Q1 Q1.o

Q2.o: Q2.cpp Q2.hpp
	$(CXX) -c Q2.cpp

Q2: Q2.o
	$(CXX) -o Q2 Q2.o

date.o: date.cpp date.hpp
	$(CXX) -c date.cpp

testdate.o: testdate.cpp
	$(CXX) -c testdate.cpp

testdate: testdate.o date.o
	$(CXX) -o testdate testdate.o date.o

employee.o: employee.cpp employee.hpp
	$(CXX) -c employee.cpp

testemployee.o: testemployee.cpp
	$(CXX) -c testemployee.cpp

testemployee: testemployee.o employee.o date.o
	$(CXX) -o testemployee testemployee.o employee.o date.o

all: Q1 Q2 testemployee testdate

clean:
	rm -f Q1 Q2 testemployee testdate *.o