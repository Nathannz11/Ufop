api_lib = bin/model.o bin/system.o bin/flow.o

all: lib tests
lib: model.o system.o flow.o
tests: tests-functional

model.o:
	g++ -c src/model.cpp -o bin/model.o -Wall

system.o:
	g++ -c src/system.cpp -o bin/system.o -Wall

flow.o:
	g++ -c src/flow.cpp -o bin/flow.o -Wall

tests-functional:
	g++ test/functional/main.cpp test/functional/functional_tests.cpp $(api_lib) -o bin/functional_tests.out
	
clean:
	rm -f bin/*.o bin/*.out

run:
	./bin/functional_tests.out
