#pragma once
#include <iostream>
#include <string>
using namespace std;

class Funcionario {
    private:
        string nome;
        float salario;
        string dataAdmissao;
    public:
        Funcionario(string n, float s, string d);
        
        string getNome();
        void setNome(string n);
        
        float getSalario();
        void setSalario(float s);
        
        string getDataAdmissao();
        void setDataAdmissao(string d);
        
        bool operator==(const Funcionario& outro) const;
        
        void exibirDados();
};