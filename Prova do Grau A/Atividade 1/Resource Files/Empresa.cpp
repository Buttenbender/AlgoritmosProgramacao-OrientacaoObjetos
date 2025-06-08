#include "Empresa.h"

Empresa::Empresa(string n, long long c)
    : nome(n), cnpj(c) {}

string Empresa::getNome() {
    return nome;
}

void Empresa::setNome(string n) {
    nome = n;
}

long long Empresa::getCnpj() {
    return cnpj;
}

void Empresa::setCnpj(long long c) {
    cnpj = c;
}

void Empresa::adicionarDepartamento(Departamento* departamento) {
    departamentos.push_back(departamento);
}

void Empresa::exibirDepartamentos() {
    cout << "--- Departamentos ---" << endl;
    for (auto& departamento : departamentos) {
        cout << "- " << departamento->getNome() << endl;
    }
    cout << endl;
}

void Empresa::exibirDados() {
    cout << "--- Dados da Empresa ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "CNPJ: " << cnpj << endl;
    exibirDepartamentos();
}
