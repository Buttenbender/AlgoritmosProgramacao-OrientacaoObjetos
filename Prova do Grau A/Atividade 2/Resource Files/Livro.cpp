#include "Livro.h"

Livro::Livro(string n, double p, string c, string a)
	: Produto(n, p, c), autor(a) { }

void Livro::exibir() const {
	cout << "Livro - Nome: " << nome << ", Preço: " << preco << ", Autor: " << autor << ", Código: " << codigoBarras << endl;
}

void Livro::editar() {
	cout << "Novo nome: ";
	getline(cin, nome);
	cout << "Novo preço: ";
	cin >> preco;
	cin.ignore();
	cout << "Novo autor: ";
	getline(cin, autor);
}