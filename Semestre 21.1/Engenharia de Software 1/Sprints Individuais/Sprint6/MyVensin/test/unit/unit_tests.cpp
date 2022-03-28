//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007

#include <assert.h>
#include "unit_tests.hpp"
#include "../../src/include/systemImpl.hpp"
#include <cassert>

void unit_test_global_sumOperator(){
    SystemHandle* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 1 - System class sum global operator" << endl;
    assert((20.0 + (*sys)) == 30);

    cout <<  "OK!" <<  endl;
}

void unit_test_global_minusOperator(){
    SystemHandle* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 2 - System class subtraction global operator" << endl;
    assert((20.0 - (*sys)) == 10);

    cout <<  "OK!" <<  endl;
}

void unit_test_global_timesOperator(){
    SystemHandle* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 3 - System class multiplication global operator" << endl;
    assert((20.0 * (*sys)) == 200);

    cout <<  "OK!" <<  endl;
}

void unit_test_global_divisionOperator(){
    SystemHandle* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 4 - System class division global operator" << endl;
    assert((20.0 / (*sys)) == 2);

    cout <<  "OK!" <<  endl;
}

void run_unit_tests_globals(){
    unit_test_global_sumOperator();
    unit_test_global_minusOperator();
    unit_test_global_timesOperator();
    unit_test_global_divisionOperator();
}