#define TCLIENTE 5
#define TMASCOTA 11
#define TRAZA 6
#define INACTIVO 0
#define ACTIVO 1
#include<stdio.h>
#include<stdlib.h>
#include"Clientes-Mascotas.h"



int main()

{
    eCliente clientes[TCLIENTE];
    eMascota mascotas[TMASCOTA];
    eRaza razas[TRAZA];
    int opcion;
    int retorno;
    int id;
    char entrada[10];

    hardcodearClientes(clientes,TCLIENTE);
    hardcodearMascotas(mascotas,TMASCOTA);
    hardcodearRaza(razas,TRAZA);
   // initMascotas(mascotas,TMASCOTA);
   // initClientes(clientes,TCLIENTE);




    do
    {
            opcion=mostrarMenuABM();

            switch(opcion)
            {
                case 1:
                    system("cls");
                    mostrarClientes(clientes,TCLIENTE);
                break;
                case 2:
                    system("cls");
                    mostrarMascotas(mascotas,TMASCOTA,clientes,TCLIENTE,razas,TRAZA);
                break;
                case 3:
                    system("cls");
                    mostrarClientesConSusAnimales(clientes,TCLIENTE,mascotas,TMASCOTA,razas,TMASCOTA);
                break;
                case 4:
                    system("cls");
                    retorno=altaMascota(mascotas,TMASCOTA,clientes,TCLIENTE,razas,TRAZA);
                    if(retorno)
                    {
                        printf("Alta exitosa.\n\n");
                        system("pause");
                    }else
                    {
                        printf("Operacion cancelada, reeingrese.\n\n");
                        system("pause");
                    }
                break;
                case 5:
                    system("cls");
                    printf("Mascotas activos actualmente: \n\n");
                    mostrarMascotas(mascotas,TMASCOTA,clientes,TCLIENTE,razas,TRAZA);

                    printf("\n\nIngrese ID de la mascota a eliminar: ");
                    fflush(stdin);
                    gets(entrada);
                    id=validarIntEntreRangos(entrada,1,TMASCOTA);

                    retorno=bajaMascota(mascotas,TMASCOTA,id);
                    if(retorno)
                    {
                        printf("Eliminacion correcta.\n\n");
                        system("pause");
                    }else
                    {
                        printf("Operacion cancelada, reeingrese.\n\n");
                        system("pause");
                    }

                break;
                case 6:
                    system("cls");
                    printf("Mascotas activas actualmente: \n\n");
                    mostrarMascotas(mascotas,TMASCOTA,clientes,TCLIENTE,razas,TRAZA);

                    printf("\n\nIngrese ID de la mascota a modificar: ");
                    fflush(stdin);
                    gets(entrada);
                    id=validarIntEntreRangos(entrada,1,TMASCOTA);

                    retorno=modificarMascota(mascotas,TMASCOTA,id,razas,TRAZA);
                    if(retorno)
                    {
                        printf("Modificacion correcta.\n\n");
                        system("pause");
                    }else
                    {
                        printf("Operacion cancelada, reeingrese.\n\n");
                        system("pause");
                    }
                break;

                case 7:
                    system("cls");
                     retorno=altaCliente(clientes,TCLIENTE);
                    if(retorno)
                    {
                        printf("Alta exitosa.\n\n");
                        system("pause");
                    }else
                    {
                        printf("Operacion cancelada, reeingrese.\n\n");
                        system("pause");
                    }
                break;

                case 8:
                    system("cls");
                    printf("Clientes activos actualmente: \n\n");
                    mostrarClientes(clientes,TCLIENTE);

                    printf("\n\nIngrese ID de el cliente a eliminar (SE ELIMINARAN TAMBIEN SUS MASCOTAS): ");
                    fflush(stdin);
                    gets(entrada);
                    id=validarIntEntreRangos(entrada,1,TCLIENTE);
                    retorno=bajaClienteConSusMascotas(mascotas,TMASCOTA,clientes,TCLIENTE,id);
                    if(retorno)
                    {
                        printf("Baja exitosa.\n\n");
                        system("pause");
                    }else
                    {
                        printf("Operacion cancelada, reeingrese.\n\n");
                        system("pause");
                    }
                break;
                case 9:
                system("cls");
                mostrarMascotasPorTipo(mascotas,TMASCOTA,clientes,TCLIENTE,razas,TRAZA);
                break;
                case 10:
                system("cls");
                printf("Clientes activos actualmente: \n\n");
                mostrarClientes(clientes,TCLIENTE);

                printf("\n\nIngrese ID del cliente a modificar: ");
                fflush(stdin);
                gets(entrada);
                id=validarIntEntreRangos(entrada,1,TCLIENTE);

                retorno=modificarCliente(clientes,TCLIENTE,id);
                if(retorno)
                {
                    printf("Modificacion correcta.\n\n");
                    system("pause");
                }else
                {
                    printf("Operacion cancelada, reeingrese.\n\n");
                    system("pause");
                }
                break;

                case 11:
                system("cls");
                listarClientesConMasUnaMascota(mascotas,TMASCOTA,clientes,TCLIENTE);
                break;
                case 12:
                system("cls");
                listarMascotasMas3Anios(mascotas,TMASCOTA,clientes,TCLIENTE,razas,TRAZA);
                break;
                case 13:
                system("cls");
                mostrarMascotasPorTipoElegido(mascotas,TMASCOTA,razas,TRAZA);
                break;
                case 14:
                system("cls");
                ordenarClientesPorCantMascotas(mascotas,TMASCOTA,clientes,TCLIENTE);
                break;
                case 15:
                system("cls");
                ordenarClientesPorCantMascotasYnombre(mascotas,TMASCOTA,clientes,TCLIENTE);
                break;
                case 16:
                system("cls");
                promedioEdadMascotas(mascotas,TMASCOTA);
                break;
                case 17:
                system("cls");
                promedioEdadMascotaPorTipo(mascotas,TMASCOTA);
                break;
                case 18:
                system("cls");
                promedioEntreClientesMujeresHombres(clientes,TCLIENTE);
                break;
                case 19:
                    system("cls");
                    printf("Gracias por haber usado esta aplicacion. ");
                break;

            }

    }while(opcion!=19);



    return 0;
}
