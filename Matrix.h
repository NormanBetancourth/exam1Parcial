#include <time.h>
#include "Asiento.h"
class Matrix {
private:
	Asiento*** asiento;
	string id;
public:

    const string &getId() const;
    void setId(const string &id);
	Matrix();
	string tostring();
	~Matrix();
	void inicializarIdentificacion();
	void inicializarEstado();
	void reservarAsiento(int x);
	bool espacio(int cant);

	
	Asiento* gethabitacion(int,int);

	
	


};


