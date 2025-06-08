#pragma once
#include <string>
#include <iostream>
using namespace std;

class Produto {
protected:
	string nome;
	double preco;
	string codigoBarras;
public:
	Produto(string n, double p, string c);
	virtual ~Produto();

	string getCodigoBarras() const;
	bool igual(Produto* outro) const;

	virtual void exibir() const = 0;
	virtual void editar() = 0;
};