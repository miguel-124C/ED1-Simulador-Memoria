#ifndef HMEMORIA_H
#define HMEMORIA_H

#include <vcl.h>

struct NodoM {
    int dir;
    AnsiString dato;
    AnsiString id;
    int link;
};

class HMemoria {
private:
	static const int MAX = 20;
    static const int NULO = -1;

	int libre;
public:
    // Propiedades
	NodoM MEM[MAX];

	// Getters y setters
	int getLibre() const { return libre; }
	void setLibre(int value) { libre = value; }

	int Max() const { return MAX; }
    int Nulo() const { return NULO; }


	// Métodos
    virtual int NewEspacio(AnsiString cadena) = 0;
    virtual void DeleteEspacio(int dir) = 0;
    virtual void PonerDato(int dir, AnsiString cadena_id, AnsiString valor) = 0;
    virtual NodoM ObtieneDato(int dir, AnsiString cadena_id) = 0;
    virtual int EspacioDisponible() = 0;
    virtual int EspacioOcupado() = 0;
	virtual bool DirLibre(int dir) = 0;

	// "nombre,correo,contra" => 3 ids
	int NumeroIds( AnsiString cadena ){
		int cantidad = 1;
		for (int i = 1; i <= cadena.Length(); i++) {
			char c = cadena[i];
			if( c == ',' ){
                cantidad++;
			}
		}

		return cantidad;
	}

	// "nombre,correo,contra", 1 => "nombre"
    // "nombre,correo,contra", 2 => "correo"
	AnsiString ObtenerId( AnsiString cadena, int index ){
		AnsiString id = "";
		short cantidadComas = 0;
		for (int i = 1; i <= cadena.Length(); i++) {
			if( cadena[i] == ',' ){
				cantidadComas++;
			}

			if( index - 1 == cantidadComas && cadena[i] != ',' ){
				id += cadena[i];
			}
		}

        return id;
	}

    virtual ~HMemoria() {}  // Destructor virtual
};

#endif

