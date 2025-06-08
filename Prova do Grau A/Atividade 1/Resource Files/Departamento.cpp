#include "Departamento.h"

Departamento::Departamento(string n)
    : nome(n) {}

string Departamento::getNome() {
    return nome;
}

void Departamento::setNome(string n) {
    nome = n;
}

void Departamento::adicionarFuncionario(Funcionario* funcionario) {
    funcionarios.push_back(funcionario);
}

void Departamento::excluirFuncionario(Funcionario* funcionario) {
    for (auto f = funcionarios.begin(); f != funcionarios.end(); f++) {
        if (*f == funcionario) {
            funcionarios.erase(f);
            break;
        }
    }
}

void Departamento::exibirFuncionarios() {
    cout << "--- Funcionários ---" << endl;
    for (auto& funcionario : funcionarios) {
        cout << "- " << funcionario->getNome() << ", Salário: R$" << funcionario->getSalario() << ", Data de Admissão: " <<
        funcionario->getDataAdmissao() << endl;
    }
    cout << endl;
}

// era: void Departamento::transferirFuncionario(Departamento& destino, Funcionario funcionario);
void Departamento::transferirFuncionario(Departamento& destino, Funcionario* funcionario) {
    excluirFuncionario(funcionario);
    destino.adicionarFuncionario(funcionario);
}

void Departamento::exibirDados() {
    cout << "--- Dados do Departamento ---" << endl;
    cout << "Nome: " << nome << endl;
    exibirFuncionarios();
}

void Departamento::darAumento() {
    for (auto& funcionario : funcionarios) {
        funcionario->setSalario(funcionario->getSalario() * 1.10);
    }
}