void sacaC(TCola *C, TElementoC *e)
{
    if ((*C).pri != -1)
    {
        *e = (*C).datos[(*C).pri];
        if ((*C).pri == (*C).ult)
            (*C).pri == (*C).ult == -1;
        else
        {
            (*C).pri += 1;
        }
    }
}