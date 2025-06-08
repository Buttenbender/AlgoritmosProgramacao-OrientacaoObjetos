#include "Funcionario.h"
#include "Departamento.h"
#include "Empresa.h"

int main() {
    Funcionario f1("João", 1900, "14/04/2025");
    Funcionario f2("Alexia", 1900, "12/04/2025");
    Funcionario f3("Ricardo", 2000, "19/06/2025");
    
    Departamento d1("Vendas");
    d1.adicionarFuncionario(&f1);
    d1.adicionarFuncionario(&f2);
    
    Departamento d2("TI");
    d2.adicionarFuncionario(&f3);
    
    Empresa e1("Unisinos", 32669058000119);
    e1.adicionarDepartamento(&d1);
    e1.adicionarDepartamento(&d2);
    e1.exibirDados();
    
    d1.darAumento();
    d1.exibirDados();
    
    d2.exibirDados();
    
    d1.transferirFuncionario(d2, &f1);
    d2.exibirDados();
    
    d1.exibirDados();
    
}
