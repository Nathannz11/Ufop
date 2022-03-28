//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007

#include "./unit_system.hpp"
#include "./unit_model.hpp"
#include "./unit_flow.hpp"
#include "./unit_tests.hpp"

int main(){

    cout << "\nTestes unitarios da Classe System\n"<< endl;
    run_unit_tests_system();
    cout << "\nTestes unitarios da Classe Flow\n" << endl;
    run_unit_tests_flow();
    cout << "\nTestes unitarios da Classe Model\n"<< endl;
    run_unit_tests_model();
    cout << "\nTestes unitarios de Funcoes Globais\n"<< endl;
    run_unit_tests_globals();

    return 0;
}