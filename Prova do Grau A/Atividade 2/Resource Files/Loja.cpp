#include "Loja.h"

Loja::Loja(string n)
	: nome(n) { }

Loja::~Loja() {
	for (Produto* p : estoque) {
		delete p;
	}
	estoque.clear();
}

void Loja::listarProdutos() const {
	cout << "\nEstoque da Loja " << nome << ":\n";
	if (estoque.empty()) {
		cout << "Estoque vazio!\n";
	}
	else {
		for (Produto* p : estoque) {
			p->exibir();
		}
	}
}

int Loja::buscarProduto(const string& codigo) const {
	for (size_t i = 0; i < estoque.size(); i++) {
		if (estoque[i]->getCodigoBarras() == codigo) {
			return i;
		}
	}
	return -1;
}

void Loja::inserirProduto(Produto* p) {
	if (buscarProduto(p->getCodigoBarras()) == -1) {
		estoque.push_back(p);
		cout << "Produto adicionado com sucesso!\n";
	}
	else {
		cout << "Código de barras duplicado. Produto não adicionado!\n";
		delete p;
	}
}

void Loja::removerProduto(const string& codigo) {
	int pos = buscarProduto(codigo);
	if (pos != -1) {
		delete estoque[pos];
		estoque.erase(estoque.begin() + pos);
		cout << "Produto removido com sucesso!\n";
	}
	else {
		cout << "Produto não encontrado!\n";
	}
}

void Loja::editarProduto(const string& codigo) {
	int pos = buscarProduto(codigo);
	if (pos != -1) {
		estoque[pos]->editar();
	}
	else {
		cout << "Produto não encontrado!\n";
	}
}