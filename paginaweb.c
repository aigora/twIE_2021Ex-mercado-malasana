#include<stdio.h>
#include<stdlib.h>

void menu_inicio();
int main()
{
    FILE *pInfo, *pDireccion_Hora, *pCharcuteria, *pFruteria, *pPanaderia, *pPescaderia;
    char *DyH;
    long int SizeFicheroDyH;
    int i;

    //Creo un fichero con la direccion y horario del mercado
    pDireccion_Hora=fopen("Direccion y horarios", "r");
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
        printf("%s\n", DyH);
        free(DyH);
        return 0;
    }

    menu_inicio();

    return 0;
}
void menu_inicio()
{
    printf("                   MERCADO  MALASANA                    \n\n\n");
    printf("||Tiendas(T)||\t ||Acerca del mercado(A)||\t ||Direccion y horarios(D)||\t\n\n");
    char opcion;
    scanf("%c", &opcion);
}
