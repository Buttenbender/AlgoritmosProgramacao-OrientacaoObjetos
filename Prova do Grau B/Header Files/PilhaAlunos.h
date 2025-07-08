#pragma once
#include <iostream>
#include <string>
#include "Fila.h"
using namespace std;

struct Aluno {
	int numero;
	string nome;
};

struct Nota {
	int numeroAluno;
	float valor;
};

class PilhaAlunos {
private:
	struct NodeAluno {
		Aluno aluno;
		NodeAluno* proximo;
		NodeAluno(const Aluno& a);
	};

	NodeAluno* topo;
	int contador;
public:
	PilhaAlunos();
	~PilhaAlunos();

	void push(const Aluno& a);
	void pop();
	Aluno* top();
	bool empty() const;
	int size() const;
	
	Aluno* buscarPorNumero(int numero);
	void listarSemNotas(Fila<Nota>& filaNotas);
	bool alunoTemNotas(int numero, Fila<Nota>& filaNotas);
	void imprimirTodos();
	bool removerAlunoPorNumero(int numero, Fila<Nota>& filaNotas);
};
