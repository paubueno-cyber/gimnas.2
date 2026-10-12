#include<iostream>
#include<string.h>
using namespace std;

class Tarifa
{
private:
	double preuMensual;
	string nomTarifa;

public:
	Tarifa(double preu= 2.5, string nom= "i5"): preuMensual(preu), nomTarifa(nom){}

	double getPreuMensual()
	{
		return preuMensual;
	}

	string getNomtarifa()
	{
		return nomTarifa;
	}
};


class Soci
{
private:
	string nomSoci;
	int idSoci;
	Tarifa tarifa;

public:
	Soci(string nom, int id, Tarifa t) : nomSoci(nom), idSoci(id), tarifa(t){}

	virtual double calcularQuota()
	{
		return tarifa.getPreuMensual();
	}

	void mostrarDades()
	{
		cout << "Nom: " << nomSoci << endl;
		cout << "ID: " << idSoci << endl;
		cout << "Tarifa: " << tarifa.getNomtarifa() << endl;
		cout << "Quota: " << calcularQuota() << " euros" << endl;
	}
};

class SociVIP : public Soci
{
private:
	double descompteEntrenador;

public:
	SociVIP(string nom, int id, Tarifa t, double d)
		: Soci(nom, id, t), descompteEntrenador(d) {
	}

	double calcularQuota() override
	{
		double quota = Soci::calcularQuota();

		return quota - (quota * descompteEntrenador / 100);
	}
};


int main()
{
	Tarifa tarifa1(50, "Mensual");

	Soci soci1("Marc", 1, tarifa1);
	SociVIP soci2("Anna", 2, tarifa1, 20);

	cout << "SOCI NORMAL" << endl;
	soci1.mostrarDades();

	cout << endl;

	cout << "SOCI VIP" << endl;
	soci2.mostrarDades();

	return 0;
}