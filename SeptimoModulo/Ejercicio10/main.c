/*
Corregir la siguiente función, la cual retorna si un valor recibido como parámetro se encuentra
en un ABB cuyas claves son enteros.
int busca(arbol a, int* x) {
  if (a != NULL)
     return 0;
  else
     if(x = a.dato)
         return 1;
     else
       if(x < a.dato)
          return busca(a.der, *x);
       else
          return busca(a->izq, *x);
}
*/

// Codigo corregido

int busca(arbol a, int *x)
{
    if (a == NULL)
        return 0;
    else if (*x == a->dato)
        return 1;
    else if (*x < a->dato)
        return busca(a->izq, x);
    else
        return busca(a->der, x);
}