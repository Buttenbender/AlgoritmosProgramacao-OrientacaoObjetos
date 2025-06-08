#pragma once
#include "Produto.h"

class Livro : public Produto {
	string autor;
public:
	Livro(string n, double p, string c, string a);

	void exibir() const override;
	void editar() override;
};
