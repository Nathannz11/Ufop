//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007
#include <assert.h>

#include "./unit_system.hpp"
#include "./unit_model.hpp"
#include "./unit_flow.hpp"
#include "./unit_tests.hpp"

#define DEBUGING
#ifdef DEBUGING
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;
#endif

int main(){

    cout << "\nTestes unitarios da Classe System\n"<< endl;
    run_unit_tests_system();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    cout << "\nTestes unitarios da Classe Flow\n" << endl;
    run_unit_tests_flow();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    cout << "\nTestes unitarios da Classe Model\n"<< endl;
    run_unit_tests_model();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    cout << "\nTestes unitarios de Funcoes Globais\n"<< endl;
    run_unit_tests_globals();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    return 0;
}