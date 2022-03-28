all_unit: ./test/unit/main.cpp  unit_tests.dll unit_model.dll unit_flow.dll unit_system.dll modelImpl.dll flowImpl.dll systemImpl.dll 
	g++ ./test/unit/main.cpp -o ./bin/unit_tests  ./bin/unit_tests.dll ./bin/modelImpl.dll ./bin/flowImpl.dll ./bin/systemImpl.dll ./bin/unit_model.dll ./bin/unit_flow.dll ./bin/unit_system.dll

all_funcional: ./test/functional/main.cpp functional_tests.dll  modelImpl.dll flowImpl.dll systemImpl.dll 
	g++ ./test/functional/main.cpp -o ./bin/functional_tests ./bin/modelImpl.dll ./bin/flowImpl.dll ./bin/systemImpl.dll ./bin/functional_tests.dll

systemImpl.dll: ./src/systemImpl.cpp ./src/systemImpl.hpp 
	g++ -Wall -g -c ./src/systemImpl.cpp -o ./bin/systemImpl.dll

flowImpl.dll: ./src/flowImpl.cpp ./src/flowImpl.hpp 
	g++ -Wall -g -c ./src/flowImpl.cpp -o ./bin/flowImpl.dll

modelImpl.dll: ./src/modelImpl.cpp ./src/modelImpl.hpp 
	g++ -Wall -g -c ./src/modelImpl.cpp -o ./bin/modelImpl.dll

functional_tests.dll: ./test/functional/functional_tests.cpp ./test/functional/functional_tests.hpp 
	g++ -Wall -g -c ./test/functional/functional_tests.cpp -o ./bin/functional_tests.dll

unit_system.dll: ./test/unit/unit_system.cpp ./test/unit/unit_system.hpp  
	g++ -Wall -g -c ./test/unit/unit_system.cpp -o ./bin/unit_system.dll

unit_flow.dll: ./test/unit/unit_flow.cpp ./test/unit/unit_flow.hpp  
	g++ -Wall -g -c ./test/unit/unit_flow.cpp -o ./bin/unit_flow.dll

unit_model.dll: ./test/unit/unit_model.cpp ./test/unit/unit_model.hpp  unit_flow.dll 
	g++ -Wall -g -c ./test/unit/unit_model.cpp -o ./bin/unit_model.dll

unit_tests.dll: ./test/unit/unit_tests.cpp ./test/unit/unit_tests.hpp 
	g++ -Wall -g -c ./test/unit/unit_tests.cpp -o ./bin/unit_tests.dll

run_unit:
	./bin/unit_tests

run_funcional:
	./bin/functional_tests

clean:
	rm -f ./bin/*