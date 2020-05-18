#include"Clientes.h"
#include"Validaciones.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void hardcodearClientes(eCliente listaClientes[],int sizeClientes)
{

    char nombre[5][20]= {"Matias","Ariel","Claudia","Benjamin","Anastasia"};
    char apellido[5][20]= {"Aguirre","Campos","Barraza","Villegas","Anido"};
    char localidad [5][20]={"Lanus","Avellaneda","Gerli","Banfield","Temperley"};
    char telefono [5][10]= {"4267-1667","4267-1668","4267-1669","4267-1670","4267-1671"};
    int edad[5]= {20,25,30,35,40};
    char sexo [5]= {'M','M','F','M','F'};
    int id[5]={1,2,3,4,5};
    int estado[5]={1,1,1,1,1};
    int i;

    for(i=0;i<sizeClientes;i++)
    {

        strcpy(listaClientes[i].nombre,nombre[i]);
        strcpy(listaClientes[i].apellido,apellido[i]);
        strcpy(listaClientes[i].localidad,localidad[i]);
        strcpy(listaClientes[i].telefono,telefono[i]);
        listaClientes[i].edad=edad[i];
        listaClientes[i].sexo=sexo[i];
        listaClientes[i].id=id[i];
        listaClientes[i].estado=estado[i];
    }


}

void initClientes(eCliente listaClientes[],int sizeClientes)
{
     int i;

    for(i=0;i<sizeClientes;i++)
    {
        listaClientes[i].estado=0;
        listaClientes[i].id=i+1;

    }
}

void mostrarClientes(eCliente listaClientes[],int sizeClientes)
{
    int i;
    int contClientes=0;


    printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO \n");

    for(i=0;i<sizeClientes;i++)
    {

        if(listaClientes[i].estado==1)
        {
            printf("%d\t",listaClientes[i].id);
            printf("%s   \t",listaClientes[i].nombre);
            printf("%s   \t",listaClientes[i].apellido);
            printf("%s   \t",listaClientes[i].localidad);
            printf("%s\t",listaClientes[i].telefono);
            printf("%d\t",listaClientes[i].edad);
            printf("%c\t\n",listaClientes[i].sexo);
            contClientes++;


        }

    }
    if(contClientes==0)
    {
        printf("No hay clientes\n\n");
        system("pause");
    }
    system("pause");
}

int altaCliente(eCliente listaClientes[],int sizeClientes)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreArrayCliente(listaClientes,sizeClientes);

    system("cls");

    if(posicionLibre!=-1)

    {
        confirmacion=cargarCamposCliente(listaClientes,posicionLibre);


        if (confirmacion==1)
        {
            listaClientes[posicionLibre].estado=1;
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }



}

int buscarLibreArrayCliente(eCliente listaClientes[],int sizeClientes)
{
     int i;
     int lugarLibre=-1;

        for(i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].estado==0)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;

}
int cargarCamposCliente(eCliente listaClientes[],int posicionLibre)
{
        char entrada[10];
        char sexo;
        char opcion[5];
        int confirmacion;


        printf("Ingrese nombre de el cliente: ");
        fflush(stdin);
        gets(listaClientes[posicionLibre].nombre);
        formatearNombres(listaClientes[posicionLibre].nombre);
        while(validarCadena(listaClientes[posicionLibre].nombre)==0)
        {
            system("cls");
            printf("Nombre invalido, reeingrese nombre: ");
            gets(listaClientes[posicionLibre].nombre);
            formatearNombres(listaClientes[posicionLibre].nombre);
            validarCadena(listaClientes[posicionLibre].nombre);

        }
        printf("\nIngrese apellido del cliente :");
        fflush(stdin);
        gets(listaClientes[posicionLibre].apellido);
        formatearNombres(listaClientes[posicionLibre].apellido);

        while(validarCadena(listaClientes[posicionLibre].apellido)==0)
        {
            system("cls");
            printf("Apellido invalido, reeingrese el apellido: ");
            gets(listaClientes[posicionLibre].apellido);
            validarCadena(listaClientes[posicionLibre].apellido);
            validarTipoMascota(listaClientes[posicionLibre].apellido);
        }

        printf("\nIngrese localidad de residencia del cliente: ");
        fflush(stdin);
        gets(listaClientes[posicionLibre].localidad);
        formatearNombres(listaClientes[posicionLibre].localidad);
        while(validarCadena(listaClientes[posicionLibre].localidad)==0)
        {
            system("cls");
            printf("Localidad invalida, reeingrese la localidad: ");
            gets(listaClientes[posicionLibre].localidad);
            formatearNombres(listaClientes[posicionLibre].localidad);
            validarCadena(listaClientes[posicionLibre].localidad);

        }

        printf("\nIngrese telefono del cliente, el formato valido es XXXX-XXXX: ");
        fflush(stdin);
        gets(listaClientes[posicionLibre].telefono);

        while(validarTelefono(listaClientes[posicionLibre].telefono)==1)
        {
            system("cls");
            printf("Telefono invalido, el formato valido es XXXX-XXXX : ");
            gets(listaClientes[posicionLibre].telefono);
            validarTelefono(listaClientes[posicionLibre].telefono);

        }

        printf("\nIngrese edad de el cliente: ");
        fflush(stdin);
        gets(entrada);
        listaClientes[posicionLibre].edad=getInt(entrada);

        printf("\nIngrese sexo del cliente F/M: ");
        fflush(stdin);
        scanf("%c",&sexo);
        listaClientes[posicionLibre].sexo=getChar(sexo);

        while(validarSexoClientes(listaClientes[posicionLibre].sexo)==0)
        {
            printf("\n\nSexo invalido, ingrese F/M :");
            fflush(stdin);
            scanf("%c",&sexo);
            listaClientes[posicionLibre].sexo=getChar(sexo);
            validarSexoClientes(listaClientes[posicionLibre].sexo);
        }
        listaClientes[posicionLibre].sexo=toupper(listaClientes[posicionLibre].sexo);

        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        fflush(stdin);
        gets(opcion);

        confirmacion=validarIntEntreRangos(opcion,1,2);

        return confirmacion;


}

int modificarCliente(eCliente listaClientes[],int sizeClientes, int idModificar)
{
    int i;
    int retorno=0;
    int contMascotas=0;



    if(idModificar<0 || idModificar>sizeClientes)
    {
        return 0;
    }

    for(i=0;i<sizeClientes;i++)

    {
        if((listaClientes[i].id==idModificar) && (listaClientes[i].estado==1))
        {
            printf("CLIENTE ENCONTRADO. \n");

            contMascotas++;
            retorno=menuModificacionesCliente(listaClientes,i);

        }

    }

    if(contMascotas==0)
    {
        printf("No se encontraron mascotas\n\n");

    }

    return retorno;
}

int menuModificacionesCliente(eCliente listaClientes[],int posicionModificar)
{
    char entrada[10];
    int opcion;
    int confirmacion;
    int nuevaEdad;
    char auxModificacion[30];
    char auxSexo;


        printf("\n\n1.Modificar nombre.");
        printf("\n2.Modificar apellido.");
        printf("\n3.Modificar localidad.");
        printf("\n4.Modificar telefono.");
        printf("\n5.Modificar edad.");
        printf("\n6.Modificar sexo.");
        printf("\n\nIngrese opcion: ");

        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,6);

                switch(opcion)
                {
                    case 1:
                    system("cls");
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    while (validarCadena(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Nombre invalido, reeingrese nombre: ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarCadena(auxModificacion);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        formatearNombres(auxModificacion);
                        strcpy(listaClientes[posicionModificar].nombre,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 2:
                    system("cls");
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    while (validarCadena(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Apellido invalido, reeingrese apellido: ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarCadena(auxModificacion);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        formatearNombres(auxModificacion);
                        strcpy(listaClientes[posicionModificar].apellido,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 3:
                     system("cls");
                    printf("Ingrese nueva localidad: ");
                    fflush(stdin);
                    gets(auxModificacion);

                    while (validarCadena(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Localidad invalida, reeingrese localidad: ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarCadena(auxModificacion);
                    }


                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        formatearNombres(auxModificacion);
                        strcpy(listaClientes[posicionModificar].localidad,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 4:
                    system("cls");
                    printf("Ingrese nuevo telefono: ");
                    fflush(stdin);
                    gets(auxModificacion);

                    while(validarTelefono(auxModificacion)==1)
                    {
                        printf("\nTelefono invalido, reeingrese con el formato XXXX-XXXX : ");
                        fflush(stdin);
                        gets(auxModificacion);
                        validarTelefono(auxModificacion);
                    }
                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        strcpy(listaClientes[posicionModificar].telefono,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }

                    break;

                    case 5:
                    system("cls");
                    printf("Ingrese nueva edad: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    nuevaEdad=getInt(auxModificacion);

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        listaClientes[posicionModificar].edad=nuevaEdad;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;
                    case 6:
                    system("cls");
                    printf("Ingrese nuevo sexo (F/M): ");
                    fflush(stdin);
                    scanf("%c",&auxSexo);

                    auxSexo=getChar(auxSexo);

                    while(validarSexoClientes(auxSexo)==0)
                    {
                        printf("\nSexo invalido, reeingrese sexo F/M: ");
                        fflush(stdin);
                        scanf("%c",&auxSexo);
                        auxSexo=getChar(auxSexo);
                        validarSexoClientes(auxSexo);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    fflush(stdin);
                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        auxSexo=toupper(auxSexo);
                        listaClientes[posicionModificar].sexo=auxSexo;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    break;

                    default:
                    system("cls");
                    printf("Opcion invalida, vuelva a comenzar.\n\n");
                    system("pause");
                    return 0;
                    break;
                }
}


void promedioEntreClientesMujeresHombres(eCliente listaClientes[],int sizeClientes)
{
    int i;
    int contFemenino=0;
    int contClientes=0;
    float promedio;

    for(i=0;i<sizeClientes;i++)
    {
        if(listaClientes[i].estado==1)
        {
            contClientes++;
        }


        if(listaClientes[i].sexo== 'F' && listaClientes[i].estado==1)
        {
            contFemenino++;
        }

    }



    promedio=contFemenino*100/contClientes;

    printf("El %.2f de los clientes son mujeres.\n\n ",promedio);

    system("pause");



}
