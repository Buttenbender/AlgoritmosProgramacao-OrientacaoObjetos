#include "Cd.h"

Cd::Cd(string n, double p, string c, int nf)
	: Produto(n, p, c), numFaixas(nf) { }

void Cd::exibir() const {
	cout << "CD - Nome: " << nome << ", Preço: " << preco << ", Faixas: " << numFaixas << ", Código: " << codigoBarras << endl;
}

void Cd::editar() {
	cout << "Novo nome: ";
	getline(cin, nome);
	cout << "Novo preço: ";
	cin >> preco;
	cin.ignore();
	cout << "Novo número de Faixas: ";
	cin >> numFaixas;
	cin.ignore();
}