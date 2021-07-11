#include<stdio.h>
#include<stdlib.h>

void menu_inicio(void);
void tiendas(void);
int main()
{
    FILE *pInfo, *pDireccion_Hora, *pCharcuteria, *pFruteria, *pPanaderia, *pPescaderia;
    char *DyH, *Info;
    long int SizeFicheroDyH, SizeFicheroInfo;
    int i;

    //Fichero con la direccion y horario del mercado

    pDireccion_Hora=fopen("Direccion_y_horarios.txt", "r");
    if(pDireccion_Hora==NULL)
    {
        printf("Error al abrir fichero\n");
        return -1;
    }
    else
    {
        fseek(pDireccion_Hora, 0, SEEK_END);
        SizeFicheroDyH=ftell(pDireccion_Hora);
        fseek(pDireccion_Hora, 0, SEEK_SET);
        DyH=malloc(SizeFicheroDyH);
        if(DyH==NULL)
        {
            printf("Error: memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pDireccion_Hora, "%c", &DyH[i])!=EOF)
            i++;
        fclose(pDireccion_Hora);
    }
    //Fichero de informacion del mercado

    pInfo=fopen("Informacion.txt", "r");
    if(pInfo==NULL)
    {
        printf("Error al abrir fichero\n");
        return -1;
    }
    else
    {
        fseek(pInfo, 0, SEEK_END);
        SizeFicheroInfo=ftell(pInfo);
        fseek(pInfo, 0, SEEK_SET);
        Info=malloc(SizeFicheroDyH);
        if(Info==NULL)
        {
            printf("Error: memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pInfo, "%c", &Info[i])!=EOF)
            i++;
        fclose(pInfo);
    }
    return 0;
}
void menu_inicio(void)
{
    printf("                   MERCADO  MALASANA                    \n\n\n");
    printf("||Tiendas(T)||\t ||Acerca del mercado(A)||\t ||Direccion y horarios(D)||\t\n\n");
}
void tiendas(void)
{
    printf("||Charcuteria(C)||\t ||Fruteria(F)||\t ||Panaderia(B)||\t ||Pescaderia(P)||\t");
}

