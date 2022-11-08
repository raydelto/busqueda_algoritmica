
#include <iostream>

//O(N)
bool busquedaLineal(int* enteros, size_t cantidad, int numero)
{
    size_t vueltas = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        vueltas++;
        if (enteros[i] == numero)
        {
            std::cout << "Busqueda lineal tomó " << vueltas << " vueltas" << std::endl;
            return true;
        }
    }
    std::cout << "Busqueda lineal tomó " << vueltas << " vueltas" << std::endl;
    return false;
}
//O(Log(N))
bool busquedaBinaria(int* enteros, size_t cantidad, int numero)
{
    int puntoMedio;
    int izquierdo = 0;
    int derecho = cantidad - 1;
    size_t vueltas = 0;

    while (izquierdo <= derecho)
    {
        vueltas++;
        puntoMedio = (derecho + izquierdo) / 2;
        if (numero > enteros[puntoMedio])
        {
            izquierdo = puntoMedio + 1;
        }
        else if (numero < enteros[puntoMedio])
        {
            derecho = puntoMedio - 1;
        }
        else
        {
            std::cout << "Busqueda binaria tomó " << vueltas << " vueltas" << std::endl;
            return true;
        }
    }
    std::cout << "Busqueda binaria tomó " << vueltas << " vueltas" << std::endl;
    return false;
}


int main()
{
    int arreglo[] = {1,3,5,7,9,11,13,14,18,21,23,44,55,66,88,100};
    size_t tamano = sizeof(arreglo) / sizeof(int);
    int numero = 123;
    bool resultado = busquedaBinaria(arreglo, tamano, numero);
    if (resultado == true)
    {
        std::cout << "El número " << numero << " fue encontrado" << std::endl;
    }
    else
    {
        std::cout << "El número " << numero << " NO fue encontrado" << std::endl;
    }

    resultado = busquedaLineal(arreglo, tamano, numero);
    if (resultado == true)
    {
        std::cout << "El número " << numero << " fue encontrado" << std::endl;
    }
    else
    {
        std::cout << "El número " << numero << " NO fue encontrado" << std::endl;
    }

    
}