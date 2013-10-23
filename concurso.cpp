// Concurso de Waragon
// Algoritmo por: Licenciado Alvaro Gonzalez
// alvaro.gonzalez.ferrer@gmail.com
// (011) - 15 54738580 (14 a 18 hs, preferible comunicarse por email)
// Licencia MIT

// compilado con gcc versión 4.7.2 (Ubuntu/Linaro 4.7.2-2ubuntu1)
// comando recomendado: g++ concurso.cpp -o concurso -Wall

// pseudocodigo:
// un pastel es rico si en alguna fila o columna tiene todos los ingredientes iguales (puede incluir una masita esa fila o columna, y cuenta como igual)
//
// otra manera:
// para cada fila, verificar los ingredientes: si son todos iguales o hay una masita junto a ingredientes iguales, es rico
// para cada columna, verificar los ingredientes: si son todos iguales o hay una masita junto a ingredientes iguales, es rico


#include <iostream>

#define W_P  3
#define H_P  3

// ingredientes
#define MASITA 0
#define DULCE 1
#define FRUTA 2
#define CONFITE 3


// es rico el pastel?
// este es el algoritmo que define la receta, si el pastel aprueba este test, esta riquisimo
bool es_rico(char pastel[][H_P])
{
    // hay alguna fila entera del mismo ingrediente, o con una masita metida entre 2 iguales?
    int c=0;
    for (int y=0; y<H_P; y++)
    {
        c=1; // el primer ingrediente OK
        for (int x=1; x<W_P; x ++)
        {
            if (pastel[x][y] == pastel[0][y] || pastel[x][y] == MASITA)        
                c++;
            
            if (c>=W_P)
                return true; // pastel rico!
        }
    }
    // hay alguna columna entera del mismo ingrediente, o con una masita metida entre 2 iguales?
    for (int x=0; x<W_P; x ++)
    {
        c=1; // el primer ingrediente OK
        for (int y=1; y<H_P; y ++)
        {
            if (pastel[x][y] == pastel[x][0] || pastel[x][y] == MASITA)        
                c++;
            
            if (c>=H_P)
                return true; // pastel rico!
        }
    }

return false; // el pastel no es rico :(
}

int main()
{
    // pastel de prueba, este pastel es rico
    char pastel_rico[W_P][H_P] =
                            {{DULCE,FRUTA,MASITA},
                            {DULCE,CONFITE,FRUTA},
                            {DULCE,FRUTA,CONFITE}};
    // este pastel es feo
    char pastel_feo[W_P][H_P] =
                            {{DULCE,CONFITE,DULCE},
                            {FRUTA,DULCE,FRUTA},
                            {CONFITE,FRUTA,CONFITE}};
    // y este tiene masita
    char pastel_comodin[W_P][H_P] =
                            {{FRUTA,DULCE,DULCE},
                            {FRUTA,CONFITE,MASITA},
                            {CONFITE,FRUTA,DULCE}};

    //testear
    std::cout << es_rico(pastel_rico) << std::endl;

    std::cout << es_rico(pastel_feo) << std::endl;

    std::cout << es_rico(pastel_comodin) << std::endl;

    return true;
}
