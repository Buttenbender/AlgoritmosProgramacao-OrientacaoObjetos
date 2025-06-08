#include "Funcionario.h"

Funcionario::Funcionario(string n, float s, string d)
    : nome(n), salario(s), dataAdmissao(d) {}

string Funcionario::getNome() {
    return nome;
}

void Funcionario::setNome(string n) {
    nome = n;
}

float Funcionario::getSalario() {
    return salario;
}

void Funcionario::setSalario(float s) {
    salario = s;
}

string Funcionario::getDataAdmissao() {
    return dataAdmissao;
}

void Funcionario::setDataAdmissao(string d) {
    dataAdmissao = d;
}

bool Funcionario::operator==(const Funcionario& outro) const {
    return nome == outro.nome &&
           salario == outro.salario &&
           dataAdmissao == outro.dataAdmissao;
}

void Funcionario::exibirDados() {
    cout << "--- Dados de Funcionario ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Salário: " << salario << endl;
    cout << "Data de Admissão: " << dataAdmissao << endl;
}
