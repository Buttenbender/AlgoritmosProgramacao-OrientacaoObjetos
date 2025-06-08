#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Departamento.h"
using namespace std;

class Empresa {
    private:
        string nome;
        long long cnpj;
        vector<Departamento*> departamentos; // não tinha usado ponteiro
    public:
        Empresa(string n, long long c);
        
        string getNome();
        void setNome(string n);
        
        long long getCnpj();
        void setCnpj(long long c);
        
        void adicionarDepartamento(Departamento* departamento); // aqui eu também não tinha usado ponteiro
        void exibirDepartamentos();
        
        void exibirDados();
};