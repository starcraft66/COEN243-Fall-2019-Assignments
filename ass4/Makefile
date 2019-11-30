CXX=clang++

edevice.o: edevice.cpp edevice.hpp
	$(CXX) -c edevice.cpp

testdevice.o: testdevice.cpp
	$(CXX) -c testdevice.cpp

testdevice: testdevice.o edevice.o
	$(CXX) -o testdevice testdevice.o edevice.o

house.o: house.cpp house.hpp
	$(CXX) -c house.cpp

testhouse.o: testhouse.cpp
	$(CXX) -c testhouse.cpp

testhouse: testhouse.o house.o
	$(CXX) -o testhouse testhouse.o house.o

employee.o: employee.cpp employee.hpp
	$(CXX) -c employee.cpp

testemployee.o: testemployee.cpp
	$(CXX) -c testemployee.cpp

testemployee: testemployee.o employee.o
	$(CXX) -o testemployee testemployee.o employee.o

department.o: department.cpp department.hpp
	$(CXX) -c department.cpp

testdepartment.o: testdepartment.cpp
	$(CXX) -c testdepartment.cpp

testdepartment: testdepartment.o department.o employee.o
	$(CXX) -o testdepartment testdepartment.o department.o employee.o

all: testdepartment testemployee testdevice testhouse

clean:
	rm -f testdevice testdepartment testemployee testhouse *.o