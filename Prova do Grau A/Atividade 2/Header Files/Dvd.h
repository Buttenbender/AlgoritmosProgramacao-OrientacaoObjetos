#pragma once
#include "Produto.h"

class Dvd : public Produto {
	double duracao;
public:
	Dvd(string n, double p, string c, double d);

	void exibir() const override;
	void editar() override;
};
