
#ifndef _PENTAGONO_H
#define _PENTAGONO_H

#include "Geometrica.h"

	class Pentagono : public Geometrica
{
public:
	/**
	 * @param l
	 * @param x
	 * @param y
	 */
	Pentagono(double l);
	float area();
	float perimetro();

	void setLado(float l) { _lado = l; }
	float getLado() { return _lado; }

private:
	float _lado;

	Pentagono();
};

#endif //_PENTAGONO_H
