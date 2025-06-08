#pragma once
#include "Produto.h"

class Cd : public Produto {
	int numFaixas;
public:
	Cd(string n, double p, string c, int nf);

	void exibir() const override;
	void editar() override;
};
