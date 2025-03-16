#include "CMemoria.h"

// Constructor
CMemoria::CMemoria() {
	for( int i = 0; i < Max(); i++ ) {
        MEM[i].dir 	= i;
		MEM[i].link = i +1;
	}

	MEM[Max() - 1].link = Nulo();
    setLibre(0);
}

int CMemoria::NewEspacio(AnsiString cadena) {
	int cantidadIds = NumeroIds( cadena );
	int DIR = getLibre();
	int D 	= getLibre();
	for( int i = 1; i <= cantidadIds - 1; i++ ) {
		MEM[D].id = ObtenerId(cadena, i);
		D = MEM[D].link;
	}
	setLibre(MEM[D].link);
	MEM[D].link = -1;
	MEM[D].id = ObtenerId(cadena, cantidadIds);

    return DIR;
}

void CMemoria::DeleteEspacio(int dir) {
    int x = dir;
	while( MEM[x].link != -1 ) {
		x = MEM[x].link;
	}

	MEM[x].link = getLibre();
    setLibre( dir );
}

void CMemoria::PonerDato(int dir, AnsiString cadena_id, AnsiString valor) {
	int z = dir;
	bool idEncontrado = false;
	while( z != -1 ){
		if( MEM[z].id == cadena_id ){
			MEM[z].dato = valor;
			ShowMessage("Dato guardado en memoria: " + cadena_id);
            idEncontrado = true;
		}
		z = MEM[z].link;
	}

    if( !idEncontrado ) ShowMessage("No se pudo añadir el dato, ya que no existe un espacio en memoria llamado " + cadena_id);
}

NodoM CMemoria::ObtieneDato(int dir, AnsiString cadena_id) {
    NodoM dato;
	int z = dir;
	while( z != -1 ){
		if( MEM[z].id == cadena_id ){
			dato = MEM[z];
		}
		z = MEM[z].link;
	}

    return dato;
}

int CMemoria::EspacioDisponible() {
	int x = getLibre();
	int c = 0;

	while( x != -1 ){
		c++;
		x = MEM[x].link;
	}

	return c;
}

int CMemoria::EspacioOcupado() {
	return Max() - EspacioDisponible();
}

bool CMemoria::DirLibre(int dir) {
	int x = getLibre();
	int c = false;

	while( x != -1 && !c ){
		if( dir == x ){
			c = true;
            break;
		}
		x = MEM[x].link;
	}

	return c;
}