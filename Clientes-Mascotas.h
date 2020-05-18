#include"Clientes.h"
#include"Mascotas.h"
#include"Validaciones.h"

typedef struct
{
    int idCliente;
    int cantidadMascotas;
    char nombre[10];

}eClienteMascota;





/** \brief Muestra listado de mascotas con sus respectivos dueños.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void mostrarMascotas(eMascota[] ,int,eCliente[],int,eRaza[],int);



/** \brief Muestra listado de clientes con sus respectivos animales.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void mostrarClientesConSusAnimales(eCliente[],int,eMascota[],int,eRaza listadoRazas[] ,int sizeRaza);



/** \brief Muestra listado de mascotas por tipo.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void mostrarMascotasPorTipo(eMascota[],int,eCliente[],int,eRaza[],int);





/** \brief Alta de mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
int altaMascota(eMascota[] ,int,eCliente[],int,eRaza[],int);




/** \brief Carga campos respectivos a una mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
int cargarCamposMascota(eMascota[] ,int,eCliente[] ,int,eRaza[],int);



/** \brief Baja de un cliente con sus respectivas mascotas.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \param int ID UNICO de el cliente a dar de baja
 * \return void
 *
 */
int bajaClienteConSusMascotas(eMascota[],int,eCliente[],int,int);



/** \brief Muestra listado de clientes con mas de una mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void listarClientesConMasUnaMascota(eMascota[],int,eCliente[],int);




/** \brief Muestra listado de clientes con mascotas de mas de 3 años.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void listarMascotasMas3Anios(eMascota[],int,eCliente[],int,eRaza[],int);




/** \brief Ordena y lista clientes por cantidad de mascotas a cargo.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void ordenarClientesPorCantMascotas(eMascota[],int,eCliente[],int);




/** \brief Ordena y lista clientes por cantidad de mascotas y nombre.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void ordenarClientesPorCantMascotasYnombre(eMascota[],int,eCliente[],int);
