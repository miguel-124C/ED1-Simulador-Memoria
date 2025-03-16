#ifndef CMEMORIA_H
#define CMEMORIA_H

#include "HMemoria.h"

class CMemoria : public HMemoria {
public:
    CMemoria();
    int NewEspacio(AnsiString cadena) override;
    void DeleteEspacio(int dir) override;
    void PonerDato(int dir, AnsiString cadena_id, AnsiString valor) override;
    NodoM ObtieneDato(int dir, AnsiString cadena_id) override;
    int EspacioDisponible() override;
    int EspacioOcupado() override;
    bool DirLibre(int dir) override;
};

#endif

