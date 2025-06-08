#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Produto.h"
using namespace std;

class Loja {
	string nome;
	vector<Produto*> estoque;
public:
	Loja(string n);
	~Loja();

	void listarProdutos() const;
	int buscarProduto(const string& codigo) const;
	void inserirProduto(Produto* p);
	void removerProduto(const string& codigo);
	void editarProduto(const string& codigo);
};
