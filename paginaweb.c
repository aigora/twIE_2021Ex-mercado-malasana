#include<stdio.h>
#include<stdlib.h>

void menu_inicio(void);
void tiendas(void);
int main()
{
    FILE *pInformacion, *pDireccion_Hora, *pCharcuteria, *pFruteria, *pPanaderia, *pPescaderia;
    char *DireccionyHorarios, *Informacion, *Charcuteriadial;
    long int SizeFicheroDireccionyHorarios, SizeFicheroInformacion, SizeFicherocharcuterialdial;
    int i;
    char letratiendas_Acerca_Dir, letrainicio;

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
        SizeFicheroDireccionyHorarios=ftell(pDireccion_Hora);
        fseek(pDireccion_Hora, 0, SEEK_SET);
        DireccionyHorarios=malloc(SizeFicheroDireccionyHorarios);
        if(DireccionyHorarios==NULL)
        {
            printf("Error: memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pDireccion_Hora, "%c", &DireccionyHorarios[i])!=EOF)
            i++;
        fclose(pDireccion_Hora);
    }

    //Fichero de informacion acerca del mercado

    pInformacion=fopen("Informacion.txt", "r");
    if(pInformacion==NULL)
    {
        printf("Error al abrir fichero\n");
        return -1;
    }
    else
    {
        fseek(pInformacion, 0, SEEK_END);
        SizeFicheroInformacion=ftell(pInformacion);
        fseek(pInformacion, 0, SEEK_SET);
        Informacion=malloc(SizeFicheroInformacion);
        if(Informacion==NULL)
        {
            printf("Error: memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pInformacion, "%c", &Informacion[i])!=EOF)
            i++;
        fclose(pInformacion);
    }

    //Fichero Charcuteria Dial

    pCharcuteria=fopen("charcuteriadial.txt", "r");
    if(pCharcuteria==NULL)
    {
        printf("Error al abrir fichero\n");
        exit(-1);
    }
    else
    {
        fseek(pCharcuteria, 0, SEEK_END);
        SizeFicherocharcuterialdial=ftell(pCharcuteria);
        fseek(pCharcuteria, 0, SEEK_SET);
        Charcuteriadial=malloc(SizeFicherocharcuterialdial);
        i=0;
        while(fscanf(pCharcuteria, "%c", &Charcuteriadial[i])!=EOF)
            i++;
        fclose(pCharcuteria);
    }

    //Pantalla inicial

    menu_inicio();
    scanf("%c", &letratiendas_Acerca_Dir); //introducimos la letra correspondiente segun la opcion que queramos
    switch(letratiendas_Acerca_Dir)
    {
    case 't':
    case 'T':
        tiendas();
        break;
    case 'a':
    case 'A':
        printf("%s\t", Informacion);
        break;
    case 'd':
    case 'D':
        printf("%s\t", DireccionyHorarios);
        do
        {
            scanf("%c", &letrainicio);
        }
        while(letrainicio!='i'||letrainicio!='I');
        menu_inicio();
        break;

    }
    return 0;
}
void menu_inicio(void)
{
    printf("                         MERCADO  MALASANA                    \n\n\n");
    printf("||Tiendas(T)||\t ||Acerca del mercado(A)||\t ||Direccion y horarios(D)||\t\n\n");
}
void tiendas(void)
{
    printf("||Charcuteria(C)||\t ||Fruteria(F)||\t ||Panaderia(B)||\t ||Pescaderia(P)||\t");
}

