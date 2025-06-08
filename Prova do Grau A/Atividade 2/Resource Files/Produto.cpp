#include "Produto.h"

Produto::Produto(string n, double p, string c)
	: nome(n), preco(p), codigoBarras(c) { }

Produto::~Produto() {}

string Produto::getCodigoBarras() const {
	return codigoBarras;
}

bool Produto::igual(Produto* outro) const {
	return this->codigoBarras == outro->codigoBarras;
}