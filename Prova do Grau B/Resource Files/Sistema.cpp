#include "Sistema.h"

void Sistema::iniciarPrograma() {
	PilhaAlunos pilha;
	Fila<Nota> filaNotas;
	int proximoNumero = 1;
	int opc;
	do {
		cout << "===== MENU =====" << endl;
		cout << "1) Cadastrar Aluno" << endl;
		cout << "2) Cadastrar Nota" << endl;
		cout << "3) Calcular Média" << endl;
		cout << "4) Listar Nomes dos Alunos sem Nota" << endl;
		cout << "5) Excluir Aluno" << endl;
		cout << "6) Excluir Nota" << endl;
		cout << "7) Sair" << endl;
		cout << "Escolha sua Opção: ";
		cin >> opc;

		switch (opc) {
		case 1: {
			cin.ignore();
			string nome;
			cout << "Nome do Aluno: ";
			getline(cin, nome);
			Aluno a = { proximoNumero++, nome };
			pilha.push(a);
			cout << "Aluno Cadastrado como número " << proximoNumero - 1 << "!" << endl;
			break;
		}
		case 2: {
			int num;
			float nota;
			cout << "Número do Aluno: ";
			cin >> num;
			cout << "Nota: ";
			cin >> nota;

			if (pilha.buscarPorNumero(num)) {
				filaNotas.enqueue({ num, nota });
				cout << "Nota cadastrada!" << endl;
			}
			else {
				cout << "Aluno não cadastrado!" << endl;
			}
			break;
		}
		case 3: {
			int num;
			cout << "Número do Aluno: ";
			cin >> num;
			Aluno* aluno = pilha.buscarPorNumero(num);

			if (!aluno) {
				cout << "Aluno não cadastrado!" << endl;
				break;
			}

			float soma = 0;
			int qtd = 0;
			int tam = filaNotas.size();
			Fila<Nota> temp;

			for (int i = 0; i < tam; i++) {
				Nota n = filaNotas.dequeue();
				if (n.numeroAluno == num) {
					soma += n.valor;
					qtd++;
				}
				temp.enqueue(n);
			}

			while (!temp.empty()) {
				filaNotas.enqueue(temp.dequeue());
			}

			if (qtd == 0) {
				cout << "Aluno sem notas!" << endl;
			}
			else {
				cout << "Nome: " << aluno->nome << " | Média do Aluno = " << (soma / qtd) << endl;
			}
			break;
		}
		case 4:
			cout << "Alunos sem Notas:" << endl;
			pilha.listarSemNotas(filaNotas);
			break;
		case 5: {
			int num;
			cout << "Número do Aluno a Excluir: ";
			cin >> num;

			if (!pilha.buscarPorNumero(num)) {
				cout << "Aluno não encontrado!" << endl;
			}
			else if (pilha.removerAlunoPorNumero(num, filaNotas)) {
				cout << "Aluno Excluído!" << endl;
			}
			else {
				cout << "Este aluno possúi notas, logo não pode ser excluido!" << endl;
			}
			break;
		}
		case 6: {
			if (filaNotas.empty()) {
				cout << "Fila Vazia!" << endl;
				break;
			}

			int num;
			cout << "Número do Aluno cuja nota será excluida: ";
			cin >> num;

			bool excluida = false;
			int tam = filaNotas.size();
			Fila<Nota> temp;

			for (int i = 0; i < tam; i++) {
				Nota n = filaNotas.dequeue();
				if (!excluida && n.numeroAluno == num) {
					excluida = true;
					continue;
				}
				temp.enqueue(n);
			}

			while (!temp.empty()) {
				filaNotas.enqueue(temp.dequeue());
			}

			if (excluida) {
				cout << "Nota Excluida!" << endl;
			}
			else {
				cout << "Nota não encontrada para esse aluno!" << endl;
			}
			break;
		}
		case 7:
			cout << "Saindo do Programa..." << endl;
			break;
		default:
			cout << "Opção Inválida!" << endl;
			break;
		}

	} while (opc != 7);
}