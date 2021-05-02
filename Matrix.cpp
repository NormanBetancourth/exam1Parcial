#include "Matrix.h"
const int F = 10, C = 6;

Matrix::Matrix(){

    asiento = new Asiento **[F];
	for (int i = 0; i < F; i++) {
        asiento[i] = new Asiento * [C];
	}
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
            asiento[i][j] = new Asiento();
		}
	}
	inicializarEstado();
	inicializarIdentificacion();
}
string Matrix::tostring(){
	stringstream s;
	s<<"Asientos\t\n";
	for (int f = 0; f < F; f++) {
		for (int c = 0; c < C; c++) {
			s <<'['<< asiento[f][c]->toString()<<']';
		}
        s << '\n';
        s << "-----------------------------------------------------------------------------------------------------------------\n";
	}
	return s.str();
}
void Matrix::inicializarIdentificacion() {
	
	int n = 0;
	for (int f = 0; f < F; f++) {
		for (int c = 0; c < C; c++) {
		    n++;
			asiento[f][c]->setId(n);
		}
		
	}
	
}
void Matrix::inicializarEstado() {
	for (int f = 0; f < F; f++) {
		for (int c = 0; c < C; c++) {
			asiento[f][c]->setEstado("Disponible");
		}
	}
}
Asiento* Matrix::gethabitacion(int i, int j)
{
	return asiento[i][j];
}


Matrix::~Matrix() {

	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			delete[] asiento[i][j];

		}
	}

	delete[] asiento;
}

void Matrix::setId(const string &id) {
    Matrix::id = id;
}

const string &Matrix::getId() const {
    return id;
}
