#include"Mascotas.h"
#include"Clientes.h"
#include"Validaciones.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void hardcodearRaza(eRaza listaRazas[],int sizeRaza)
{

    char nombre[6][20]= {"Siames","Persa","Ovejero","Labrador","Lagarto","Piton"};
    char pais[6][20]= {"Argentina","China","Alemania","Italia","Japon","Sudan"};
    int i;

    for(i=0;i<6;i++)
    {

        strcpy(listaRazas[i].nombreRaza,nombre[i]);
        strcpy(listaRazas[i].pais,pais[i]);
        listaRazas[i].idRaza=i+1;

    }

}

void mostrarRaza(eRaza listadoRazas[] , int sizeRazas)
{
    int i;

    printf("\n\nID      NOMBRE           PAIS");
    for(i=0;i<sizeRazas;i++)
    {
        printf("\n%d \t",listadoRazas[i].idRaza);
        printf("%s      \t",listadoRazas[i].nombreRaza);
        printf("%s\n",listadoRazas[i].pais);
    }
}


void hardcodearMascotas(eMascota listadoMascotas[],int sizeMascotas)
{
    char nombre[11][20]={"Reyna","Juana","Slack","Noah","Pedro","Raul","Berta","Hercules","Michi","Blanquito","Eduardo"}; //,"","","","","","","","",};
    char tipo [11][20]={"Gato","Gato","Perro","Perro","Gato","Perro","Raro","Perro","Gato","Gato","Perro"};
    int raza [11]={1,2,3,4,1,4,5,3,2,2,4};
    int edad[11]= {7,10,5,3,1,4,8,15,9,7,2};
    float peso[11]={20,10,15,8,7.5,6.9,2.6,4.6,12,13,6.6};
    char sexo[11]={'H','H','M','M','M','M','H','M','M','M','M'};
    int idDelDuenio[11]={3,3,1,1,1,5,5,2,4,4,4};
    int idMascota[11]={1,2,3,4,5,6,7,8,9,10,11};
    int estado[11]={1,1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0;i<sizeMascotas;i++)
    {
        strcpy(listadoMascotas[i].nombre,nombre[i]);
        strcpy(listadoMascotas[i].tipo,tipo[i]);
        listadoMascotas[i].idRaza=raza[i];
        listadoMascotas[i].edad=edad[i];
        listadoMascotas[i].peso=peso[i];
        listadoMascotas[i].sexo=sexo[i];
        listadoMascotas[i].idDelDuenio=idDelDuenio[i];
        listadoMascotas[i].idMascota=idMascota[i];
        listadoMascotas[i].estado=estado[i];


    }


}

void initMascotas(eMascota listadoMascotas[],int sizeMascotas)
{
    int i;

    for(i=0;i<sizeMascotas;i++)
    {
        listadoMascotas[i].estado=0;
        listadoMascotas[i].idMascota=i+1;

    }

}

int buscarLibreArrayMascota(eMascota listadoMascotas[],int sizeMascotas )
{
    int i;
    int lugarLibre=-1;

        for(i=0;i<sizeMascotas;i++)
        {
            if(listadoMascotas[i].estado==0)
            {
                lugarLibre=i;
                return lugarLibre;
            }
        }
        return lugarLibre;
}

int bajaMascota(eMascota listadoMascotas[],int sizeMascotas,int idEliminar)
{
    int i;
    char entrada[10];
    int confirmacion;
    int retorno=0;
    int contMascotas=0;

    for(i=0;i<sizeMascotas;i++)

    {
        if((listadoMascotas[i].idMascota==idEliminar) && (listadoMascotas[i].estado==1))
        {
                contMascotas++;
                printf("MASCOTA ENCONTRADA. \n");

                printf("Ingrese 1 para confirmar la eliminacion.\n");
                printf("Ingrese 2 para salir.\n\n");
                printf("Opcion elegida: ");

                gets(entrada);

                confirmacion=validarIntEntreRangos(entrada,1,2);

                if (confirmacion==1)
                {
                    listadoMascotas[i].estado=0;
                    return 1;
                }
                else
                {
                    return 0;
                }
                break;
        }

    }

    if(contMascotas==0)
    {
        printf("No se encontraron mascotas\n\n");

    }


    return retorno;

}

int modificarMascota(eMascota listadoMascotas[] , int sizeMascotas, int idModificar, eRaza listadoRazas[] ,int sizeRazas)
{

    int i;
    int retorno=0;
    int contMascotas=0;



    if(idModificar<0 || idModificar>sizeMascotas)
    {
        return 0;
    }

    for(i=0;i<sizeMascotas;i++)

    {
        if((listadoMascotas[i].idMascota==idModificar) && (listadoMascotas[i].estado==1))
        {
            printf("MASCOTA ENCONTRADA. \n");

            contMascotas++;
            retorno=menuModificaciones(listadoMascotas,i,listadoRazas,sizeRazas);

        }

    }

    if(contMascotas==0)
    {
        printf("No se encontraron mascotas\n\n");

    }

    return retorno;

}

int menuModificaciones(eMascota listadoMascotas[],int posicionModificar,eRaza listadoRazas[] ,int sizeRazas)
{
    char entrada[10];
    int opcion;
    int confirmacion;
    int nuevaEdad;
    int nuevaRaza;
    char auxModificacion[30];
    char auxSexo;
    float nuevoPeso;
    int nuevoDuenio;

        printf("\n\n1.Modificar nombre.");
        printf("\n2.Modificar tipo.");
        printf("\n3.Modificar raza.");
        printf("\n4.Modificar edad.");
        printf("\n5.Modificar peso.");
        printf("\n6.Modificar sexo.");
        printf("\n7.Modificar duenio.");

        printf("\n\nIngrese opcion: ");

        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,7);

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
                        strcpy(listadoMascotas[posicionModificar].nombre,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 2:
                    system("cls");
                    printf("Ingrese nuevo tipo (Perro/Gato/Raro): ");
                    fflush(stdin);
                    gets(auxModificacion);
                    formatearNombres(auxModificacion);
                    while (validarCadena(auxModificacion)==0 || validarTipoMascota(auxModificacion)==0)
                    {
                        system("cls");
                        printf("Tipo invalido, reeingrese tipo (Perro/Gato/Raro): ");
                        fflush(stdin);
                        gets(auxModificacion);
                        formatearNombres(auxModificacion);
                        validarCadena(auxModificacion);
                        validarTipoMascota(auxModificacion);
                    }

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        strcpy(listadoMascotas[posicionModificar].tipo,auxModificacion);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 3:
                    system("cls");
                    mostrarRaza(listadoRazas,sizeRazas);
                    printf("Ingrese id nueva raza: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    nuevaRaza=getInt(auxModificacion);

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {

                        listadoMascotas[posicionModificar].idRaza=nuevaRaza;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 4:
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
                        listadoMascotas[posicionModificar].edad=nuevaEdad;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;

                    case 5:

                    system("cls");
                    printf("Ingrese nuevo peso: ");
                    fflush(stdin);
                    gets(auxModificacion);
                    nuevoPeso=getFloat(auxModificacion);

                    printf("Ingrese 1 para confirmar.\n");
                    printf("Ingrese 2 para salir.\n\n");
                    printf("Opcion elegida: ");

                    gets(entrada);

                    confirmacion=validarIntEntreRangos(entrada,1,2);

                    if (confirmacion==1)
                    {
                        listadoMascotas[posicionModificar].peso=nuevoPeso;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }

                    break;
                    case 6:
                    system("cls");
                    printf("Ingrese nuevo sexo: ");
                    fflush(stdin);
                    scanf("%c",&auxSexo);

                    auxSexo=getChar(auxSexo);

                    while(validarSexoMascota(auxSexo)==0)
                    {
                        printf("\nSexo invalido, reeingrese sexo de mascota H/M: ");
                        fflush(stdin);
                        scanf("%c",&auxSexo);
                        auxSexo=getChar(auxSexo);
                        validarSexoMascota(auxSexo);
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
                        listadoMascotas[posicionModificar].sexo=auxSexo;
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

void mostrarMascotasPorTipoElegido(eMascota listadoMascotas[],int sizeMascotas,eRaza listadoRazas[] ,int sizeRazas)
{
    char entrada[10];
    int i;
    int j;


    printf("Ingrese tipo de mascota (Gato/Perro/Raro): ");
    gets(entrada);
    formatearNombres(entrada);

    while(validarCadena(entrada)==0)
    {
        printf("Tipo de mascota invalida, ingrese (Perro,Gato,Raro) : ");
        gets(entrada);
        formatearNombres(entrada);
        validarTipoMascota(entrada);
        validarCadena(entrada);

    }

    printf("\nID      NOMBRE                  TIPO     RAZA          EDAD     PESO  SEXO ");

    for(i=0;i<sizeMascotas;i++)
    {

        if(strcmp(entrada,listadoMascotas[i].tipo)==0 && listadoMascotas[i].estado==1)
        {

                printf("\n%d     \t",listadoMascotas[i].idMascota);
                printf("%s              \t",listadoMascotas[i].nombre);
                printf("%s\t",listadoMascotas[i].tipo);
                for(j=0;j<sizeRazas;j++)
                {
                    if(listadoMascotas[i].idRaza ==listadoRazas[j].idRaza)
                    {
                         printf("%s   \t",listadoRazas[j].nombreRaza);
                         break;
                    }
                }

                printf("%d\t",listadoMascotas[i].edad);
                printf("%.2f\t",listadoMascotas[i].peso);
                printf("%c\t",listadoMascotas[i].sexo);

        }


    }


    printf("\n\n");
    system("pause");
}

void promedioEdadMascotas(eMascota listadoMascotas[],int sizeMascotas)
{
    int i;
    int acumEdades=0;
    int contMascotas=0;
    float promedio;

    for(i=0;i<sizeMascotas;i++)
    {
        if(listadoMascotas[i].estado==1)
        {
            acumEdades=listadoMascotas[i].edad+acumEdades;
            contMascotas++;
        }
    }
    promedio=(float)acumEdades/contMascotas;

    printf("El promedio de edad entre las mascotas es: %2.f\n\n",promedio);
    system("pause");
}

void promedioEdadMascotaPorTipo(eMascota listadoMascotas[],int sizeMascotas)
{
    char entrada[10];
    int i;
    int acumEdades=0;
    int contMascotas=0;
    float promedio;


    printf("Ingrese el tipo de mascota por la cual desea saber el promedio de edad (Perro/Gato/Raro):");
    fflush(stdin);
    gets(entrada);
    formatearNombres(entrada);

    while(validarCadena(entrada)==0 || validarTipoMascota(entrada)==0)
    {
        system("cls");
        printf("Tipo invalido, reeingrese el tipo (Gato/Perro/Raro): ");
        gets(entrada);
        formatearNombres(entrada);
        validarCadena(entrada);
        validarTipoMascota(entrada);
    }


    for(i=0;i<sizeMascotas;i++)
    {
        if(strcmp(listadoMascotas[i].tipo,entrada)==0 && listadoMascotas[i].estado==1)
        {
            acumEdades=listadoMascotas[i].edad+acumEdades;
            contMascotas++;
        }
    }
    promedio=acumEdades/(float)contMascotas;

    printf("El promedio de edad entre las mascotas de tipo %s: %.2f\n\n",entrada,promedio);
    system("pause");
}
