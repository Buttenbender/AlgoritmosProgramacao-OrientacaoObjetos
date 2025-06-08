#include "Dvd.h"

Dvd::Dvd(string n, double p, string c, double d)
	: Produto(n, p, c), duracao(d) { }

void Dvd::exibir() const {
	cout << "DVD - Nome: " << nome << ", Preço: " << preco << ", Duração: " << duracao << " min, Código: " << codigoBarras << endl;
}

void Dvd::editar() {
	cout << "Novo nome: ";
	getline(cin, nome);
	cout << "Novo preço: ";
	cin >> preco;
	cin.ignore();
	cout << "Nova duração: ";
	cin >> duracao;
	cin.ignore();
}