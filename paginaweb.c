#include<stdio.h>
#include<stdlib.h>

void menu_inicio(void);
void tiendas(void);
void charcuterias(void);
void fruterias(void);
void pescaderias(void);

int main()
{
    FILE *pInformacion, *pDireccion_Hora, *pCharcuteriaDial, *pCharcuteriaExtremena, *pFruteriaManolo, *pFruteriaAlberto;
    FILE *pPescaderiaJoaquin, *pPescaderiaCarlos;
    char *DireccionyHorarios, *Informacion, *Charcuteriadial, *Charcuteriaextrem, *Fruteriamanolo, *Fruteriaalberto;
    char *Pescaderiajoaquin, *Pescaderiacarlos;
    long int SizeFicheroDireccionyHorarios, SizeFicheroInformacion, SizeFicherocharcuterialdial, SizeFicherocharcuteriaextrem;
    long int SizeFicheroFruteriaManolo, SizeFicheroFruteriaAlberto, SizeFicheroPescaderiaJoaquin, SizeFicheroPescaderiaCarlos;
    int i;
    int teclamenuinicio, teclatiendas, teclacharcuterias, teclafruterias, teclapescaderias;
    char tecla_a_inicio;

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

    //Fichero Fruteria Alberto

    pFruteriaAlberto=fopen("fruteriaalberto.txt", "r");
    if(pFruteriaAlberto==NULL)
    {
        printf("Error al abrir fichero\n");
        exit(-1);
    }
    else
    {
        fseek(pFruteriaAlberto, 0, SEEK_END);
        SizeFicheroFruteriaAlberto=ftell(pFruteriaAlberto);
        fseek(pFruteriaAlberto, 0, SEEK_SET);
        Fruteriaalberto=malloc(SizeFicheroFruteriaAlberto);
        if(Fruteriaalberto==NULL)
        {
            printf("Error:memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pFruteriaAlberto, "%c", &Fruteriaalberto[i])!=EOF)
            i++;
        fclose(pFruteriaAlberto);
    }

    //Fichero Fruteria Manolo

    pFruteriaManolo=fopen("fruteriamanolo.txt", "r");
    if(pFruteriaManolo==NULL)
    {
        printf("Error al abrir fichero\n");
        exit(-1);
    }
    else
    {
        fseek(pFruteriaManolo, 0, SEEK_END);
        SizeFicheroFruteriaManolo=ftell(pFruteriaManolo);
        fseek(pFruteriaManolo, 0, SEEK_SET);
        Fruteriamanolo=malloc(SizeFicheroFruteriaManolo);
        if(Fruteriamanolo==NULL)
        {
            printf("Error:memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pFruteriaManolo, "%c", &Fruteriamanolo[i])!=EOF)
            i++;
        fclose(pFruteriaManolo);
    }

    //Fichero Pescaderia Joaquin

    pPescaderiaJoaquin=fopen("pescaderiajoaquin.txt", "r");
    if(pPescaderiaJoaquin==NULL)
    {
        printf("Error al abrir fichero\n");
        exit(-1);
    }
    else
    {
        fseek(pPescaderiaJoaquin, 0, SEEK_END);
        SizeFicheroPescaderiaJoaquin=ftell(pPescaderiaJoaquin);
        fseek(pPescaderiaJoaquin, 0, SEEK_SET);
        Pescaderiajoaquin=malloc(SizeFicheroPescaderiaJoaquin);
        if(Pescaderiajoaquin==NULL)
        {
            printf("Error:memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pPescaderiaJoaquin, "%c", &Pescaderiajoaquin[i])!=EOF)
            i++;
        fclose(pPescaderiaJoaquin);
    }

    //Fichero Pescaderia Carlos

    pPescaderiaCarlos=fopen("pescaderiacarlos.txt", "r");
    if(pPescaderiaCarlos==NULL)
    {
        printf("Error al abrir fichero\n");
        exit(-1);
    }
    else
    {
        fseek(pPescaderiaCarlos, 0, SEEK_END);
        SizeFicheroPescaderiaCarlos=ftell(pPescaderiaCarlos);
        fseek(pPescaderiaCarlos, 0, SEEK_SET);
        Pescaderiacarlos=malloc(SizeFicheroPescaderiaCarlos);
        if(Pescaderiacarlos==NULL)
        {
            printf("Error:memoria insuficiente\n");
            exit(-1);
        }
        i=0;
        while(fscanf(pPescaderiaCarlos, "%c", &Pescaderiacarlos[i])!=EOF)
            i++;
        fclose(pPescaderiaCarlos);
    }


    //Pantalla inicial

    menu_inicio();
    scanf("%i", &teclamenuinicio); //introducimos la letra correspondiente segun la opcion que queramos
    switch(teclamenuinicio)
    {
    case 1:
        tiendas();
        fflush(stdin);
        scanf("%i", &teclatiendas);
        switch(teclatiendas)
        {
        case 1:
            charcuterias();
            fflush(stdin);
            scanf("%i", &teclacharcuterias);
            if(teclacharcuterias==1)
            {
                printf("%s\n", Charcuteriadial);
            }
            else if(teclacharcuterias==2)
            {
                printf("%s\n", Charcuteriaextrem);
            }
            break;
        case 2:
            fruterias();
            fflush(stdin);
            scanf("%i", &teclafruterias);
            if(teclafruterias==1)
            {
                printf("%s\n", Fruteriaalberto);
            }
            else if(teclafruterias==2)
            {
                printf("%s\n", Fruteriamanolo);
            }
            break;
        case 3:
            pescaderias();
            fflush(stdin);
            scanf("%i", &teclapescaderias);
            if(teclapescaderias==1)
            {
                printf("%s\n", Pescaderiajoaquin);
            }
            else if(teclapescaderias==2)
            {
                printf("%s\n", Pescaderiacarlos);
            }
            break;
        }
        break;
    case 2:
        printf("%s\n\n", Informacion);
        break;
    case 3:
        printf("%s\n\n", DireccionyHorarios);
        fflush(stdin);
        do
        {
            scanf("%c", &tecla_a_inicio);
        }
        while(tecla_a_inicio!='i'||tecla_a_inicio!='I');
        menu_inicio();
        break;

    }
    return 0;
}
void menu_inicio(void)
{
    printf("\n\n                               ~~MERCADO  MALASANA~~\n\n\n");
    printf("        -----------  \t       ---------------------  \t   -----------------------\n");
    printf("       ||Tiendas(1)||\t     ||Acerca del mercado(2)||\t ||Direccion y horarios(3)||\n");
    printf("        -----------  \t       ---------------------  \t   -----------------------\n\n");
}
void tiendas(void)
{
    printf("         ||Charcuteria(1)||\t ||Fruteria(2)||\t ||Pescaderia(3)||\n\n");
}
void charcuterias(void)
{
    printf("                  ||Charcuteria Dial(1)||      ||Charcuteria Extremena(2)||\n\n");
}
void fruterias(void)
{
    printf("                  ||Fruteria Alberto(1)||      ||Fruteria Manolo(2)||\n");
}
void pescaderias(void)
{
    printf("                  ||Pescaderia Joaquin(1)||    ||Pescaderia Carlos(2)||\n");
}

