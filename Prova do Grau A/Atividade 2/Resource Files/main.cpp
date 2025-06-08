#include "Loja.h"
#include "Livro.h"
#include "Cd.h"
#include "Dvd.h"
#include <iostream>
using namespace std;

int main() {
	Loja loja("Minha Loja");
	int opcao;

	do {
		cout << "\nMenu:\n"
			<< "1 - Inserir Produto\n"
			<< "2 - Remover Produto\n"
			<< "3 - Editar Produto\n"
			<< "4 - Listar Produtos\n"
			<< "0 - Sair\n"
			<< "Opção: ";
		cin >> opcao;
		cin.ignore();

		if (opcao == 1) {
			int tipo;
			string nome, codigo, autor;
			double preco, duracao;
			int faixas;

			cout << "Tipo (1 - Livro, 2 - CD, 3 - DVD): ";
			cin >> tipo;
			cin.ignore();
			cout << "Nome: ";
			getline(cin, nome);
			cout << "Preço: ";
			cin >> preco;
			cin.ignore();
			cout << "Código de Barras: ";
			getline(cin, codigo);

			if (tipo == 1) {
				cout << "Autor: ";
				getline(cin, autor);
				loja.inserirProduto(new Livro(nome, preco, codigo, autor));
			}
			else if (tipo == 2) {
				cout << "Número de Faixas: ";
				cin >> faixas;
				cin.ignore();
				loja.inserirProduto(new Cd(nome, preco, codigo, faixas));
			}
			else if (tipo == 3) {
				cout << "Duração (em minutos): ";
				cin >> duracao;
				cin.ignore();
				loja.inserirProduto(new Dvd(nome, preco, codigo, duracao));
			}
			else {
				cout << "Tipo inválido!\n";
			}
		}
		else if (opcao == 2) {
			string codigo;
			cout << "Código de Barras do produto a remover: ";
			getline(cin, codigo);
			loja.removerProduto(codigo);
		}
		else if (opcao == 3) {
			string codigo;
			cout << "Código de Barras do produto a editar: ";
			getline(cin, codigo);
			loja.editarProduto(codigo);
		}
		else if (opcao == 4) {
			loja.listarProdutos();
		}
	} while (opcao != 0);

	cout << "Encerrando programa...\n";
	
	return 0;
}