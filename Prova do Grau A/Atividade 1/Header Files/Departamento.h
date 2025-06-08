#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Funcionario.h"
using namespace std;

class Departamento {
    private:
        string nome;
        vector<Funcionario*> funcionarios;
    public:
        Departamento(string n);
        
        string getNome();
        void setNome(string n);
        
        void adicionarFuncionario(Funcionario* funcionario);
        void excluirFuncionario(Funcionario* funcionario);
        void exibirFuncionarios();
        void transferirFuncionario(Departamento& destino, Funcionario* funcionario);
        
        void exibirDados();
        void darAumento();
};
