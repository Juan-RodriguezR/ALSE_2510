/**
 * Project Untitled
 */

#include "Pentagono.h"
#include <math.h>

/**
 * Pentagono implementation
 */

/**
 * @param l
 */
Pentagono::Pentagono(double l)
{
    _lado = l;
}

Pentagono::Pentagono()
{
}

float Pentagono::area()
{
    return (5. * _lado * _lado) / (4. * tan(M_PI / 5.));
}
float Pentagono::perimetro()
{
    return 5. * _lado;
    //** */
}
