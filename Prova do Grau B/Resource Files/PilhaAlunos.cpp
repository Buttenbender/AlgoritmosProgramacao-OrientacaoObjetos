#include "PilhaAlunos.h"

PilhaAlunos::NodeAluno::NodeAluno(const Aluno& a)
	: aluno(a), proximo(nullptr) { }

PilhaAlunos::PilhaAlunos()
	: topo(nullptr), contador(0) { }

PilhaAlunos::~PilhaAlunos() {
	while (!empty()) {
		pop();
	}
}

void PilhaAlunos::push(const Aluno& a) {
	NodeAluno* novo = new NodeAluno(a);
	novo->proximo = topo;
	topo = novo;
	contador++;
}

void PilhaAlunos::pop() {
	if (empty()) {
		cout << "Pilha Vazia!" << endl;
		return;
	}
	NodeAluno* temp = topo;
	topo = topo->proximo;
	delete temp;
	contador--;
}

Aluno* PilhaAlunos::top() {
	if (empty()) {
		cout << "Pilha Vazia!" << endl;
		return nullptr;
	}
	return &topo->aluno;
}

bool PilhaAlunos::empty() const {
	return (topo == nullptr);
}

int PilhaAlunos::size() const {
	return contador;
}

Aluno* PilhaAlunos::buscarPorNumero(int numero) {
	NodeAluno* atual = topo;
	while (atual) {
		if (atual->aluno.numero == numero) {
			return &atual->aluno;
		}
		atual = atual->proximo;
	}
	return nullptr;
}

void PilhaAlunos::listarSemNotas(Fila<Nota>& filaNotas) {
	NodeAluno* atual = topo;
	while (atual) {
		int num = atual->aluno.numero;
		bool temNota = false;

		int tam = filaNotas.size();
		Fila<Nota> filaTemp;

		for (int i = 0; i < tam; i++) {
			Nota n = filaNotas.dequeue();
			if (n.numeroAluno == num) {
				temNota = true;
			}
			filaTemp.enqueue(n);
		}

		while (!filaTemp.empty()) {
			filaNotas.enqueue(filaTemp.dequeue());
		}

		if (!temNota) {
			cout << atual->aluno.numero << " - " << atual->aluno.nome << endl;
		}

		atual = atual->proximo;
	}
}

bool PilhaAlunos::alunoTemNotas(int numero, Fila<Nota>& filaNotas) {
	int tam = filaNotas.size();
	Fila<Nota> temp;
	bool achou = false;

	for (int i = 0; i < tam; i++) {
		Nota n = filaNotas.dequeue();
		if (n.numeroAluno == numero) {
			achou = true;
		}
		temp.enqueue(n);
	}

	while (!temp.empty()) {
		filaNotas.enqueue(temp.dequeue());
	}

	return achou;
}

void PilhaAlunos::imprimirTodos() {
	NodeAluno* atual = topo;
	while (atual) {
		cout << atual->aluno.numero << " - " << atual->aluno.nome << endl;
		atual = atual->proximo;
	}
}

bool PilhaAlunos::removerAlunoPorNumero(int numero, Fila<Nota>& filaNotas) {
	if (empty()) {
		return false;
	}

	if (alunoTemNotas(numero, filaNotas)) {
		return false;
	}

	NodeAluno* atual = topo;
	NodeAluno* anterior = nullptr;

	while (atual) {
		if (atual->aluno.numero == numero) {
			if (anterior == nullptr) {
				topo = atual->proximo;
			}
			else {
				anterior->proximo = atual->proximo;
			}
			delete atual;
			contador--;
			return true;
		}
		anterior = atual;
		atual = atual->proximo;
	}

	return false;
}