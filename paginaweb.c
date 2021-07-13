#include<stdio.h>
#include<stdlib.h>
#define N 48


int menu_inicio(void);
int tiendas(void);
int charcuterias(void);
int fruterias(void);
int pescaderias(void);
int inicio_comprar_salir(void);
int registrarse_iniciarsesion(void);

typedef struct
{
    int numero;
    float precio, kilos;
}producto;

typedef struct
{
    char correo_electronico[50];
    char contrasena[50];
    char nombre[50];
    char primer_apellido[50];

}cuenta;


int main()
{
    FILE *pInformacion, *pDireccion_Hora, *pCharcuteriaDial, *pCharcuteriaExtremena, *pFruteriaManolo, *pFruteriaAlberto;
    FILE *pPescaderiaJoaquin, *pPescaderiaCarlos, *pClientesregistrados, *pTodoslosproductos;
    char *DireccionyHorarios, *Informacion, *Charcuteriadial, *Charcuteriaextrem, *Fruteriamanolo, *Fruteriaalberto;
    char *Pescaderiajoaquin, *Pescaderiacarlos;
    long int SizeFicheroDireccionyHorarios, SizeFicheroInformacion, SizeFicherocharcuterialdial, SizeFicherocharcuteriaextrem;
    long int SizeFicheroFruteriaManolo, SizeFicheroFruteriaAlberto, SizeFicheroPescaderiaJoaquin, SizeFicheroPescaderiaCarlos;
    producto lista_productos[N];
    int i;
    int teclamenuinicio, teclatiendas, teclacharcuterias, teclafruterias, teclapescaderias;
    int teclainicio_comprar_salir, teclaregistrarse_iniciarsesion;
    cuenta cliente[100]; //Vector de estructuras para almacenar a los clientes

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
    do
    {
        teclamenuinicio=menu_inicio();
        switch(teclamenuinicio) //switch para elegir entre tiendas, informacion y horarios.
        {
        case 1:
            teclatiendas=tiendas(); //Muestro las diferentes categorias de tiendas
            switch(teclatiendas)   //switch para elegir el tipo de tienda
            {
            case 1:
                teclacharcuterias=charcuterias();  //Mostramos las dos charcuterias
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
                teclafruterias= fruterias(); //Mostramos las dos fruterias
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
                teclapescaderias= pescaderias(); //Mostramos las dos pescaderias
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
            break;
        case 4:
            return 0;  //Salimos de la pagina
        }
        teclainicio_comprar_salir=inicio_comprar_salir();//Elige entre inicio, comprar o salir de la pagina
    }
    while(teclainicio_comprar_salir==1);


    if(teclainicio_comprar_salir==2)  //Ha seleccionado comprar, pero tendra que registrarse o iniciar sesion
    {
        teclaregistrarse_iniciarsesion=registrarse_iniciarsesion();
        if(teclaregistrarse_iniciarsesion==1) //Registrarse
        {
            printf("Nombre: ");
            scanf("%s", cliente[0].nombre);
            printf("Primer apellido: ");
            scanf("%s", cliente[0].primer_apellido);
            printf("Correo electronico: ");
            scanf("%s", cliente[0].correo_electronico);
            printf("Contrasena(sin espacios): ");
            scanf("%s", cliente[0].contrasena);
        }
        else if(teclaregistrarse_iniciarsesion==2)
        {
            printf("Correo electronico: ");
            scanf("%s", cliente[0].correo_electronico);
            printf("Contrasena(sin espacios): ");
            scanf("%s", cliente[0].contrasena);
        }

    }
    else if(teclainicio_comprar_salir==3)
        return 0;
}

int menu_inicio(void)
{
    int teclamenuinicio;
    printf("\n\n                               ~~MERCADO  MALASANA~~\n\n\n");
    printf("        -----------  \t       ---------------------  \t   -----------------------  \t   --------\n");
    printf("       ||Tiendas(1)||\t     ||Acerca del mercado(2)||\t ||Direccion y horarios(3)||\t ||Salir(4)||\n");
    printf("        -----------  \t       ---------------------  \t   -----------------------  \t   --------\n\n");
    do
    {
        fflush(stdin);
        printf("Seleccione una opcion: ");    //Introducimos el numero correspondiente segun la opcion que queramos
        scanf("%i", &teclamenuinicio);        //si no introducimos uno de los tres numeros se volvera a escanear hasta que se introduzca correctamente.
        printf("\n");
    }
    while(teclamenuinicio!=1&&teclamenuinicio!=2&&teclamenuinicio!=3&&teclamenuinicio!=4);
    return teclamenuinicio;
}

int tiendas(void)
{
    int teclatiendas;
    printf("         ||Charcuteria(1)||\t ||Fruteria(2)||\t ||Pescaderia(3)||\n\n");
    do
    {
        printf("Seleccione una opcion:");
        fflush(stdin);
        scanf("%i", &teclatiendas);  //Bucle do while por si nos equivocamos de tecla
        printf("\n");
    }
    while(teclatiendas!=1&&teclatiendas!=2&&teclatiendas!=3);
    return teclatiendas;
}

int charcuterias(void)
{
    int teclacharcuterias;
    printf("                  ||Charcuteria Dial(1)||      ||Charcuteria Extremena(2)||\n\n");
    do
    {
        printf("Seleccione una opcion:");
        fflush(stdin);
        scanf("%i", &teclacharcuterias);
        printf("\n");
    }
    while(teclacharcuterias!=1&&teclacharcuterias!=2);
    return teclacharcuterias;
}

int fruterias(void)
{
    int teclafruterias;
    printf("                  ||Fruteria Alberto(1)||      ||Fruteria Manolo(2)||\n");
    do
    {
        fflush(stdin);
        scanf("%i", &teclafruterias);
    }
    while(teclafruterias!=1&&teclafruterias!=2);
    return teclafruterias;
}

int pescaderias(void)
{
    int teclapescaderias;
    printf("                  ||Pescaderia Joaquin(1)||    ||Pescaderia Carlos(2)||\n");

    do
    {
        fflush(stdin);
        scanf("%i", &teclapescaderias);
    }
    while(teclapescaderias!=1&&teclapescaderias!=2);
    return teclapescaderias;
}

int inicio_comprar_salir(void)
{
    int teclainicio_comprar_salir;
    printf("                    ||Volver a inicio(1)||       ||Comprar(2)||     ||Salir(3)||\n");
    do
    {
        fflush(stdin);
        scanf("%i", &teclainicio_comprar_salir);
    }
    while(teclainicio_comprar_salir!=1&&teclainicio_comprar_salir!=2&&teclainicio_comprar_salir!=3);
    return teclainicio_comprar_salir;
}
int registrarse_iniciarsesion(void)
{
    int teclaregistrarse_iniciarsesion;
    printf("                        ||Registrarse(1)||        ||Iniciar session(2)||\n");
    do
    {
        fflush(stdin);
        scanf("%i", &teclaregistrarse_iniciarsesion);
    }
    while(teclaregistrarse_iniciarsesion!=1&&teclaregistrarse_iniciarsesion!=2);
    return teclaregistrarse_iniciarsesion;
}
