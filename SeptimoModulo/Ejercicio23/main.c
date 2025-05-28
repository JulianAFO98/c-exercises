/*
Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:
a) retornar la cantidad de nodos que posee.
b) hallar el porcentaje de claves pares
c)  retornar su grado
d) hallar la cantidad de nodos de grado impar que hay en niveles impares.
e)  verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
a la cantidad de hijos. (función int y función void)
f)  obtener el promedio de las claves del nivel K (dato)

*/
/*
void clavesIgualHijos(arbol a, pos p, int *cumple)
{
  pos c, t;
  int cont = 0;
  if (!nulo(p))
  {
    c = hijoMasIzq(p, a);
    while (!nulo(c))
    {
      cont++;
      t = hijoMasIzq(c, a);
      if (!nulo(t))
        clavesIgualHijos(a, c, cumple);
      c = hermanoDer(c, a);
    }
    (*cumple) = (*cumple) && cont == info(p);
  }
}*/

int clavesIgualHijos(arbol a, pos p)
{
  pos c, t;
  int verifica = 1;
  int cont = 0;
  if (!nulo(p))
  {
    c = hijoMasIzq(p, a);
    while (!nulo(c) && verifica)
    {
      cont++;
      t = hijoMasIzq(c, a);
      if (!nulo(t))
        verifica = verifica && clavesIgualHijos(a, c);
      c = hermanoDer(c, a);
    }
    return verifica && cont == info(p);
  }
  return 0;
}


int cantNodos(arbol a, pos p)
{
  pos c;
  int cont = 0;
  if (!nulo(p))
  {
    c = hijoMazIzq(p, a);
    while (!nulo(c))
    {
      cont += cantNodos(a, c);
      c = hermanoDer(c, a);
    }
    return 1 + cont;
  }
  return 0;
}

void porcentajeClavesPares(arbol a, pos p, int *cantNodosPares, int *totalNodos)
{
  pos c;
  if (!nulo(p))
  {
    c = hijoMasIzq(p, a);
    while (!nulo(c))
    {
      porcentajeClavesPares(a, c, cantNodosPares, totalNodos);
      c = hermanoDer(c, a);
    }
    (*totalNodos) += 1;
    if (info(p, a) % 2 == 0)
      (*cantNodosPares)++;
  }
}

int obtenerGradoArbol(arbol a, pos p)
{
  pos c;
  int contGrado = 0, aux = 0, max = 0;
  if (!nulo(p))
  {
    c = hijoMasIzq(p, a);
    while (!nulo(c))
    {
      aux = obtenerGradoArbol(a, c);
      max = (aux > max) ? aux : max;
      contGrado++;
      c = hermanoDer(c, a);
    }
    return contGrado > max ? contGrado : max;
  }
  return 0;
}

int hallarGradoImparEnNivelImpar(arbol a, pos p, int nivel)
{
  pos c;
  int cantNodos = 0, aux = 0;
  if (!nulo(p))
  {
    c = hijoMasIzq(p, a);
    while (!nulo(c))
    {
      aux = aux + hallarGradoImparEnNivelImpar(a, c, nivel + 1);
      cantNodos++;
      c = hermanoDer(c, a);
    }
    return aux + (nivel % 2 == 1 && cantNodos % 2 == 1);
  }
  return 0;
}

void promedioNivelK(arbol a, pos p, int nivelAct, int k, int *suma, int *n)
{
  pos c;
  if (!nulo(p))
  {
    c = hijoMasIzq(p, a);
    while (!nulo(c))
    {
      promedioNivelK(a, c, nivelAct + 1, k, suma, n);
      c = hermanoDer(c, a);
    }
    if (nivelAct == k)
    {
      (*n)++;
      (*suma) += info(p);
    }
  }
}