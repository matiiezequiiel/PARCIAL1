#include"Clientes-Mascotas.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void mostrarClientesConSusAnimales(eCliente listaClientes[],int sizeClientes,eMascota listadoMascotas[],int sizeMascotas,eRaza listadoRazas[] ,int sizeRaza)
{
    int i;
    int j;
    int k;
    int contMascotas;

    for(i=0;i<sizeClientes;i++)
    {
        contMascotas=0;
        if(listaClientes[i].estado==1)
        {
            printf("\n\nCliente: %s %s",listaClientes[i].nombre,listaClientes[i].apellido);
            printf("\nMascotas a cargo del cliente:");
            printf("\nNOMBRE          TIPO    RAZA            EDAD    PESO    SEXO");
            contMascotas=0;
        }
        else
        {
            continue;
        }


        for(j=0;j<sizeMascotas;j++)
        {

            if(listaClientes[i].id==listadoMascotas[j].idDelDuenio && listadoMascotas[j].estado==1 )
            {
                printf("\n%s    \t",listadoMascotas[j].nombre);
                printf("%s\t",listadoMascotas[j].tipo);
                for(k=0;k<sizeRaza;k++)
                {
                    if(listadoMascotas[j].idRaza==listadoRazas[k].idRaza)
                    {
                         printf("%s   \t",listadoRazas[k].nombreRaza);
                         break;
                    }
                }

                printf("%d\t",listadoMascotas[j].edad);
                printf("%.2f\t",listadoMascotas[j].peso);
                printf("%c\t",listadoMascotas[j].sexo);
                contMascotas++;
            }

        }

        if(contMascotas==0)
        {
            printf("\nNO TIENE MASCOTAS.\n\n");
        }
    }
    printf("\n\n");
    system("pause");

}


void mostrarMascotas(eMascota listadoMascotas[] ,int sizeMascotas,eCliente listadoClientes[],int sizeClientes,eRaza listadoRazas[] ,int sizeRaza)
{
    int i;
    int j;
    int k;
    int contMascotas=0;

    printf("\nID      NOMBRE          TIPO            RAZA           EDAD     PESO           SEXO    NOMBRE DEL DUENIO");

    for(i=0;i<sizeMascotas;i++)
    {

            if(listadoMascotas[i].estado==1)

            {
                printf("\n%d\t",listadoMascotas[i].idMascota);
                printf("%s    \t",listadoMascotas[i].nombre);
                printf("%s     \t",listadoMascotas[i].tipo);

                for(k=0;k<sizeRaza;k++)
                {
                    if(listadoMascotas[i].idRaza==listadoRazas[k].idRaza)
                    {
                         printf("%s   \t",listadoRazas[k].nombreRaza);
                    }
                }

                printf("%d\t",listadoMascotas[i].edad);
                printf("%.2f     \t",listadoMascotas[i].peso);
                printf("%c\t",listadoMascotas[i].sexo);
                contMascotas++;

                for(j=0;j<sizeClientes;j++)
                {
                    if(listadoMascotas[i].idDelDuenio== listadoClientes[j].id )
                    {
                        printf("%s\n",listadoClientes[j].nombre);
                        break;
                    }
                }
            }



    }

    if(contMascotas==0)
    {
        printf("\n\nNO HAY MASCOTAS CARGADAS.\n\n");
        system("pause");
    }

    system("pause");
}

int altaMascota(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[] , int sizeCliente,eRaza listadoRazas[],int sizeRazas)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreArrayMascota(listadoMascotas,sizeMascotas);

    system("cls");

    if(posicionLibre!=-1)

    {
        confirmacion=cargarCamposMascota(listadoMascotas,posicionLibre,listadoClientes,sizeCliente,listadoRazas,sizeRazas);


        if (confirmacion==1)
        {
            listadoMascotas[posicionLibre].estado=1;
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

int cargarCamposMascota(eMascota listadoMascotas[],int posicionLibre,eCliente listadoClientes[] , int sizeCliente,eRaza listadoRazas[],int sizeRazas)
{
    char entrada[10];
    char sexo;
    char opcion[5];
    int confirmacion;


        printf("Ingrese nombre de la mascota: ");
        fflush(stdin);
        gets(listadoMascotas[posicionLibre].nombre);
        formatearNombres(listadoMascotas[posicionLibre].nombre);
        while(validarCadena(listadoMascotas[posicionLibre].nombre)==0)
        {
            system("cls");
            printf("Nombre invalido, reeingrese nombre: ");
            gets(listadoMascotas[posicionLibre].nombre);
            formatearNombres(listadoMascotas[posicionLibre].nombre);
            validarCadena(listadoMascotas[posicionLibre].nombre);

        }
        printf("\nIngrese tipo de la mascota (Gato/Perro/Raro) :");
        fflush(stdin);
        gets(listadoMascotas[posicionLibre].tipo);
        formatearNombres(listadoMascotas[posicionLibre].tipo);

        while(validarCadena(listadoMascotas[posicionLibre].tipo)==0 || validarTipoMascota(listadoMascotas[posicionLibre].tipo)==0)
        {
            system("cls");
            printf("Tipo invalido, reeingrese el tipo (Gato/Perro/Raro): ");
            gets(listadoMascotas[posicionLibre].tipo);
            formatearNombres(listadoMascotas[posicionLibre].tipo);
            validarCadena(listadoMascotas[posicionLibre].tipo);
            validarTipoMascota(listadoMascotas[posicionLibre].tipo);
        }

        printf("Listado de razas disponibles: ");
        mostrarRaza(listadoRazas,sizeRazas);

        printf("\nIngrese  id raza de la mascota: ");
        fflush(stdin);
        gets(entrada);
        listadoMascotas[posicionLibre].idRaza=getInt(entrada);


        printf("\nIngrese edad de la mascota: ");
        fflush(stdin);
        gets(entrada);
        listadoMascotas[posicionLibre].edad=getInt(entrada);

        printf("\nIngrese peso de la mascota: ");
        fflush(stdin);
        gets(entrada);
        listadoMascotas[posicionLibre].peso=getFloat(entrada);

        printf("\nIngrese sexo de la mascota H/M: ");
        fflush(stdin);
        scanf("%c",&sexo);
        listadoMascotas[posicionLibre].sexo=getChar(sexo);

         while(validarSexoMascota(listadoMascotas[posicionLibre].sexo)==0)
        {
            printf("\n\nSexo invalido, ingrese H/M :");
            fflush(stdin);
            scanf("%c",&sexo);
            listadoMascotas[posicionLibre].sexo=getChar(sexo);
            validarSexoClientes(listadoMascotas[posicionLibre].sexo);
        }


        listadoMascotas[posicionLibre].sexo=toupper(listadoMascotas[posicionLibre].sexo);
        mostrarClientes(listadoClientes,sizeCliente);


        printf("\nIngrese ID del dueño de la mascota : ");
        fflush(stdin);
        gets(entrada);
        listadoMascotas[posicionLibre].idDelDuenio=getInt(entrada);

        system("cls");

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(opcion);

        confirmacion=validarIntEntreRangos(opcion,1,2);

        return confirmacion;

}

int bajaClienteConSusMascotas(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[] , int sizeCliente,int idEliminar)
{
    int i;
    char entrada[10];
    int confirmacion;
    int retorno=0;

    for(i=0;i<sizeCliente;i++)
    {
        if(listadoClientes[i].id == idEliminar && listadoClientes[i].estado==1)
        {
            printf("CLIENTE ENCONTRADO.\n\n");
            printf("Ingrese 1 para confirmar la eliminacion del cliente y sus mascotas.\n");
            printf("Ingrese 2 para salir.\n\n");
            printf("Opcion elegida: ");

            gets(entrada);

            confirmacion=validarIntEntreRangos(entrada,1,2);

            if (confirmacion==1)
            {
                listadoClientes[i].estado=0;
                for(i=0;i<sizeMascotas;i++)
                {
                    if(listadoMascotas[i].idDelDuenio==idEliminar && listadoMascotas[i].estado==1)
                    {
                        listadoMascotas[i].estado=0;
                    }
                }
                retorno=1;
            }
            else
            {
                retorno=0;
            }
            break;
        }
    }


    return retorno;
}

void mostrarMascotasPorTipo(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes,eRaza listadoRazas[] ,int sizeRaza)
{
    int i;
    int j;
    eMascota auxMascota;

    for(i=0;i<sizeMascotas-1;i++)
    {
        for(j=i+1;j<sizeMascotas;j++)
        {

            if(strcmp(listadoMascotas[i].tipo,listadoMascotas[j].tipo)>0)
            {
                auxMascota  =  listadoMascotas[i];
                listadoMascotas[i] = listadoMascotas[j];
                listadoMascotas[j] = auxMascota;
            }

        }

    }
    mostrarMascotas(listadoMascotas,sizeMascotas,listadoClientes,sizeClientes,listadoRazas,sizeRaza);

}


void listarClientesConMasUnaMascota(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes)
{
    int i;
    int j;
    int contMascotas;

     printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   CANT MASCOTAS \n");

    for(i=0;i<sizeClientes;i++)
    {
        contMascotas=0;
        for(j=0;j<sizeMascotas;j++)
        {
            if(listadoClientes[i].id == listadoMascotas[j].idDelDuenio && listadoClientes[i].estado==1 && listadoMascotas[j].estado==1)
            {
               contMascotas++;
            }
        }
        if(contMascotas>1)
        {
            printf("%d\t",listadoClientes[i].id);
            printf("%s   \t",listadoClientes[i].nombre);
            printf("%s   \t",listadoClientes[i].apellido);
            printf("%s   \t",listadoClientes[i].localidad);
            printf("%s\t",listadoClientes[i].telefono);
            printf("%d\t",listadoClientes[i].edad);
            printf("%c\t",listadoClientes[i].sexo);
            printf("%d\t\n",contMascotas);
        }
    }
    system("pause");
}

void listarMascotasMas3Anios(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes, eRaza listadoRazas[] ,int sizeRaza)
{
    int contMascotas=0;
    int i;
    int j;
    int k;

    printf("\nID    NOMBRE            TIPO    RAZA            EDAD    PESO    SEXO  NOMBRE DEL DUENIO");

    for(i=0;i<sizeMascotas;i++)
    {

            if(listadoMascotas[i].estado==1 && listadoMascotas[i].edad>3)

            {
                contMascotas++;
                printf("\n%d     ",listadoMascotas[i].idMascota);
                printf("%s       \t",listadoMascotas[i].nombre);
                printf("%s\t",listadoMascotas[i].tipo);
                for(k=0;k<sizeRaza;k++)
                {
                    if(listadoMascotas[i].idRaza==listadoRazas[k].idRaza)
                    {
                         printf("%s   \t",listadoRazas[k].nombreRaza);
                    }
                }
                printf("%d\t",listadoMascotas[i].edad);
                printf("%.2f\t",listadoMascotas[i].peso);
                printf("%c\t",listadoMascotas[i].sexo);


                for(j=0;j<sizeClientes;j++)
                {
                    if(listadoMascotas[i].idDelDuenio == listadoClientes[j].id )
                    {
                        printf("%s\n",listadoClientes[j].nombre);
                        break;
                    }
                }
            }
    }
    if(contMascotas==0)
    {
        printf("No hay mascotas con mas de 3 anios.");
    }
    system("pause");
}

void ordenarClientesPorCantMascotas(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes)
{
    eClienteMascota aux[sizeClientes];
    eClienteMascota auxBurbujeo;
    int i;
    int j;
    int contMascotas;
    int contClientes=0;

    for(i=0;i<sizeClientes;i++)
    {
        contMascotas=0;
        if(listadoClientes[i].estado!=1)
        {
            continue;
        }
        for(j=0;j<sizeMascotas;j++)
        {
            if(listadoClientes[i].id == listadoMascotas[j].idDelDuenio && listadoMascotas[j].estado==1)
            {
               contMascotas++;
            }
        }
        aux[contClientes].idCliente=listadoClientes[i].id;
        aux[contClientes].cantidadMascotas=contMascotas;
        contClientes++;

    }


     printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   CANT MASCOTAS \n");
     for(i=0;i<contClientes-1;i++)
    {
        for(j=i+1;j<contClientes;j++)
        {

            if(aux[i].cantidadMascotas < aux[j].cantidadMascotas )
            {
                auxBurbujeo  =  aux[i];
                aux[i] = aux[j];
                aux[j] = auxBurbujeo;
            }
        }
    }


    for(i=0;i<contClientes;i++)
    {
        for(j=0;j<sizeClientes;j++)
        {


            if(aux[i].idCliente==listadoClientes[j].id )
            {
                printf("%d\t",listadoClientes[j].id);
                printf("%s   \t",listadoClientes[j].nombre);
                printf("%s   \t",listadoClientes[j].apellido);
                printf("%s   \t",listadoClientes[j].localidad);
                printf("%s\t",listadoClientes[j].telefono);
                printf("%d\t",listadoClientes[j].edad);
                printf("%c\t",listadoClientes[j].sexo);
                printf("%d\t\n",aux[i].cantidadMascotas);

            }
        }
    }
    system("pause");
}

void ordenarClientesPorCantMascotasYnombre(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes)
{
    eClienteMascota aux[sizeClientes];
    eClienteMascota auxBurbujeo;
    int i;
    int j;
    int contMascotas;
    int contClientes=0;

    for(i=0;i<sizeClientes;i++)
    {
        contMascotas=0;
        if(listadoClientes[i].estado!=1)
        {
            continue;
        }
        for(j=0;j<sizeMascotas;j++)
        {
            if(listadoClientes[i].id == listadoMascotas[j].idDelDuenio && listadoMascotas[j].estado==1)
            {
               contMascotas++;
            }
        }
        aux[contClientes].idCliente=listadoClientes[i].id;
        aux[contClientes].cantidadMascotas=contMascotas;
        strcpy(aux[contClientes].nombre,listadoClientes[i].nombre);
        contClientes++;

    }

     for(i=0;i<contClientes-1;i++)
    {
        for(j=i+1;j<contClientes;j++)
        {


            if(aux[i].cantidadMascotas < aux[j].cantidadMascotas)
            {

                     auxBurbujeo  =  aux[i];
                     aux[i] = aux[j];
                     aux[j] = auxBurbujeo;

            }
            else
             {
                  if(aux[i].cantidadMascotas == aux[j].cantidadMascotas)
                  {
                      if(strcmp(aux[i].nombre,aux[j].nombre)>0)
                     {
                         auxBurbujeo  =  aux[i];
                         aux[i] = aux[j];
                         aux[j] = auxBurbujeo;
                     }
                  }

             }
        }

    }


    printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   CANT MASCOTAS \n");

    for(i=0;i<contClientes;i++)
    {

        for(j=0;j<sizeClientes;j++)
        {

            if(aux[i].idCliente==listadoClientes[j].id)
            {

                printf("%d\t",listadoClientes[j].id);
                printf("%s   \t",listadoClientes[j].nombre);
                printf("%s   \t",listadoClientes[j].apellido);
                printf("%s   \t",listadoClientes[j].localidad);
                printf("%s\t",listadoClientes[j].telefono);
                printf("%d\t",listadoClientes[j].edad);
                printf("%c\t",listadoClientes[j].sexo);
                printf("%d\t\n",aux[i].cantidadMascotas);
                break;
            }
        }
    }
    system("pause");

}
