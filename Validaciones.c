#include"Validaciones.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int mostrarMenuABM(void)
{
    char entrada[10];
    int opcion;

        system("cls");
        printf("1.MOSTRAR CLIENTES.\n");
        printf("2.MOSTRAR MASCOTAS.\n");
        printf("3.MOSTRAR CLIENTES CON SUS MASCOTAS.\n");
        printf("4.ALTA MASCOTA. \n");
        printf("5.BAJA DE MASCOTA. \n");
        printf("6.MODIFICAR MASCOTA. \n");
        printf("7.ALTA DE DUENIO. \n");
        printf("8.BAJA DE DUENIO. \n");
        printf("9.MASCOTAS ORDENADAS POR TIPO. \n");
        printf("10.MODIFICAR DUENIO. \n");
        printf("11.LISTAR CLIENTES CON MAS DE UNA MASCOTA. \n");
        printf("12.LISTAR MASCOTAS CON MAS DE 3 ANIOS DE EDAD.\n");
        printf("13.LISTAR MASCOTAS SEGUN ELECCION. \n");
        printf("14.MOSTRAR DUENIOS SEGUN CANTIDAD DE MASCOTAS. \n");
        printf("15.MOSTRAR DUENIOS SEGUN CANTIDAD DE MASCOTAS Y ORDEN ALFABETICO. \n");
        printf("16.PROMEDIO DE EDAD ENTRE MASCOTAS. \n");
        printf("17.PROMEDIO DE EDAD ENTRE MASCOTAS SEGUN TIPO. \n");
        printf("18.PROMEDIO ENTRE VARONES Y MUJERES. \n");
        printf("19.SALIR. \n");



        printf("Ingrese opcion: ");
        fflush(stdin);
        gets(entrada);
        opcion=getInt(entrada);


        return opcion;



}
int validarCadena(char cadenaValidar[])
{
    int retorno=0;
    int lenght;
    int i;
    int contadorEspacios=0;

    lenght=strlen(cadenaValidar);

    for(i=0;i<lenght;i++)
    {
        if(cadenaValidar[i]==' ')
        {
            contadorEspacios++;
        }

        if( (cadenaValidar[i]>='a' && cadenaValidar[i]<='z') || (cadenaValidar[i]>='A' && cadenaValidar[i]<='Z') || (contadorEspacios==1 && i>0))
        {
             retorno=1;
        }
        else
        {
            retorno=0;
            break;
        }

    }


    return retorno;


}

float getFloat(char numeroValidar[] )
{

   float operandoValidado;

    while(validarFloat(numeroValidar)==1)
    {
        system("cls");
        printf("Numero no valido!!, Ingrese otro numero: ");
        fflush(stdin);
        gets(numeroValidar);
        validarFloat(numeroValidar);

    }


    operandoValidado=atof(numeroValidar);

    return operandoValidado;

}
int validarFloat(char numeroValidar[] )
{

     int i;
     int lenght;
     int contadorPuntos=0;
     lenght=strlen(numeroValidar);


     if(numeroValidar[0]=='\0')
        return 1;


     for (i=0;i<lenght;i++)
    {


              if(isdigit(numeroValidar[i])==0 || isspace(numeroValidar[i]!=0)) //SI ES 0 ES UN DIGITO INVALIDO (NO ES NUMERO)
            {

              if(numeroValidar[i]!='-' && numeroValidar[i]!='.')
              {
                  return 1;
              }


               if(numeroValidar[i]=='.')
               {
                    if(i==0)
                    {
                        return 1;
                    }

               }
               else
               {
                   contadorPuntos++;
               }


               if(contadorPuntos>1)
               {
                   return 1;
               }


            }


    }
    return 0;

}

int getInt(char* entero)
{
    int retorno;
    int enteroValidado;

    retorno=validarEntero(entero);

    while(retorno)
    {
        //system("cls");
        printf("Numero invalido.\n");
        printf("Reeingrese el numero: ");
        gets(entero);
        retorno=validarEntero(entero);
    }

    enteroValidado=atoi(entero);

    return enteroValidado;

}

int validarEntero (char* numeroValidar)
{
    int i;
    int lenght;
    int retorno=0;

    lenght=strlen(numeroValidar);

    if (lenght==0)  //VACIO
    {
        retorno=1;
    }

    for(i=0;i<lenght;i++)
    {

        if(isdigit(numeroValidar[i])==0) //0 NO ES NUMERO. !=0 ES NUMERO
        {
            retorno=1;
            break;
        }
    }

    return retorno;

}
int validarIntEntreRangos(char entrada[] ,int rangoMinimo,int rangoMaximo)
{
    int numeroValidar;

    numeroValidar=getInt(entrada);

    while(numeroValidar<rangoMinimo || numeroValidar>rangoMaximo)
    {
      //  system("cls");
        printf("Numero invalido, reeingrese un numero valido: \n");
     //   printf("1.Confirma.\n");
     //   printf("2.Cancela.\n\n");
        printf("Ingrese opcion:");
        gets(entrada);
        numeroValidar=getInt(entrada);

    }

    return numeroValidar;

}

char getChar(char letraValidar)
{

    while(validarChar(letraValidar)==1)
    {
        printf("Letra invalida, ingrese otra letra: ");
        fflush(stdin);
        scanf("%c",&letraValidar);
        validarChar(letraValidar);

    }


    return letraValidar;
}
int validarChar(char letraValidar)
{
    int retorno=0;

    if( (letraValidar>='a' && letraValidar<='z') || (letraValidar>='A' && letraValidar<='Z') )
        retorno=0;
    else
        retorno=1;

    return retorno;

}
void formatearNombres (char* nombre)
{
    int i;

    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);

    for(i=0;i<strlen(nombre);i++)
    {
        if(isspace(nombre[i]))
            nombre[i+1]=toupper(nombre[i+1]);
    }


}
int validarTipoMascota(char* entrada)
{

    if(strcmp(entrada,"Gato")==0 || strcmp(entrada,"Perro")==0|| strcmp(entrada,"Raro")==0)
    {
        return 1;
    }

    return 0;
}

int validarTelefono(char* nroTelefono)
{
    int lenght;
    int retorno=0;
    int i;

    lenght=strlen(nroTelefono);

    if(lenght==0)
    {
        retorno=1;
    }

    for(i=0;i<lenght;i++)
    {
        if(isdigit(nroTelefono[i])==0 || lenght>9) //0 NO ES NUMERO. !=0 ES NUMERO
        {
            if(nroTelefono[i]!='-' || i!=4)
            {
                retorno=1;
                break;
            }
        }
    }

    return retorno;

}

int validarSexoClientes(char sexoCliente)
{
    int retorno=0;

    if(sexoCliente=='M' || sexoCliente=='F'|| sexoCliente=='f' || sexoCliente=='M')
    {
        retorno=1;
    }

    return retorno;

}



int validarSexoMascota(char sexoMascota)
{

    int retorno=0;

    if(sexoMascota=='H' || sexoMascota=='M'|| sexoMascota=='h' || sexoMascota=='m')
    {
        retorno=1;
    }

    return retorno;
}
