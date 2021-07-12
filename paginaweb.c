#include<stdio.h>
#include<stdlib.h>

void menu_inicio(void);
void tiendas(void);
void charcuterias(void);
void fruterias(void);
void pescaderias(void);
int main()
{
    FILE *pInformacion, *pDireccion_Hora, *pCharcuteriaDial, *pCharcuteriaExtremena, *pFruteriaManolo, *FruteriaAlberto;
    FILE *pPanaderia, *pPescaderiaJoaquin, *pPescaderiaCarlos;
    char *DireccionyHorarios, *Informacion, *Charcuteriadial, *Charcuteriaextrem;
    long int SizeFicheroDireccionyHorarios, SizeFicheroInformacion, SizeFicherocharcuterialdial, SizeFicherocharcuteriaextrem;
    int i;
    char letramenuinicio, letra_a_inicio, letratiendas, letracharcuterias;

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

    pCharcuteriaDial=fopen("charcuteriadial.txt", "r");
    if(pCharcuteriaDial==NULL)
    {
        printf("Error al abrir fichero\n");
        exit(-1);
    }
    else
    {
        fseek(pCharcuteriaDial, 0, SEEK_END);
        SizeFicherocharcuterialdial=ftell(pCharcuteriaDial);
        fseek(pCharcuteriaDial, 0, SEEK_SET);
        Charcuteriadial=malloc(SizeFicherocharcuterialdial);
        if(Charcuteriadial==NULL)
        {
            printf("Error:memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pCharcuteriaDial, "%c", &Charcuteriadial[i])!=EOF)
            i++;
        fclose(pCharcuteriaDial);
    }
    //Fichero Charcuteria Extremena

    pCharcuteriaExtremena=fopen("charcuteriaextremena.txt", "r");
    if(pCharcuteriaExtremena==NULL)
    {
        printf("Error al abrir fichero\n");
        exit(-1);
    }
    else
    {
        fseek(pCharcuteriaExtremena, 0, SEEK_END);
        SizeFicherocharcuteriaextrem=ftell(pCharcuteriaExtremena);
        fseek(pCharcuteriaExtremena, 0, SEEK_SET);
        Charcuteriaextrem=malloc(SizeFicherocharcuteriaextrem);
        if(Charcuteriaextrem==NULL)
        {
            printf("Error:memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pCharcuteriaExtremena, "%c", &Charcuteriaextrem[i])!=EOF)
            i++;
        fclose(pCharcuteriaExtremena);
    }

    //Pantalla inicial

    menu_inicio();
    scanf("%c", &letramenuinicio); //introducimos la letra correspondiente segun la opcion que queramos
    switch(letramenuinicio)
    {
    case 't':
    case 'T':
        tiendas();
        fflush(stdin);
        scanf("%c", &letratiendas);
        switch(letratiendas)
        {
        case 'c':
        case 'C':
            charcuterias();
            break;
        case 'f':
        case 'F':
            fruterias();
            break;
        case 'p':
        case 'P':
            pescaderias();
            break;
        case 'b':
        case 'B':
            printf("Panaderia\n");
            break;

        }
        break;
    case 'a':
    case 'A':
        printf("%s\t", Informacion);
        break;
    case 'd':
    case 'D':
        printf("%s\n", DireccionyHorarios);
        fflush(stdin);
        do
        {
            scanf("%c", &letra_a_inicio);
        }
        while(letra_a_inicio!='i'||letra_a_inicio!='I');
        menu_inicio();
        break;

    }
    return 0;
}
void menu_inicio(void)
{
    printf("\n\n                               ~~MERCADO  MALASANA~~\n\n\n");
    printf("        -----------  \t       ---------------------  \t   -----------------------\n");
    printf("       ||Tiendas(T)||\t     ||Acerca del mercado(A)||\t ||Direccion y horarios(D)||\n");
    printf("        -----------  \t       ---------------------  \t   -----------------------\n\n");
}
void tiendas(void)
{
    printf("         ||Charcuteria(C)||\t ||Fruteria(F)||\t ||Panaderia(B)||\t ||Pescaderia(P)||\n");
}
void charcuterias(void)
{
    printf("          ||Charcuteria Dial(D)||      ||Charcuteria Extremena(E)||\n");
}
void fruterias(void)
{
    printf("          ||Fruteria Alberto(A)||      ||Fruteria Manolo(M)||\n");
}
void pescaderias(void)
{
    printf("          ||Pescaderia Joaquin(J)||    ||Pescaderia Carlos(C)||\n");
}

