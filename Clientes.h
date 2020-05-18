typedef struct
{
    char nombre [20];
    char apellido [20];
    char localidad [20];
    char telefono[10];
    int edad;
    char sexo;
    int id;
    int estado;

}eCliente;

/** \brief
 *
 * \param eCliente[]
 * \param int
 * \return void
 *
 */
void hardcodearClientes(eCliente[],int);



/** \brief Inicializa array de clientes para posterior carga.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return void
 *
 */
void initClientes(eCliente[],int);


/** \brief Muestra clientes activos con sus respectivos datos.
 *
 * \param Array de clientes.
 * \param Tamaño del array.
 * \return
 *
 */

void mostrarClientes(eCliente[],int);




/** \brief Alta de cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int 1 alta correcta, 0 alta cancelada.
 *
 */
int altaCliente(eCliente[],int);



/** \brief Busca posicion libre en array de clientes para su posterior carga.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int Posicion libre, -1 no hay espacio.
 *
 */
int buscarLibreArrayCliente(eCliente[],int);





/** \brief Carga campos correspondiente a al alta de un cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int 1 carga correcta,0 carga cancelada.
 *
 */
int cargarCamposCliente(eCliente[],int);




/** \brief Modificar datos de un cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño de array.
 * \param int ID unico del cliente a modificar.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int modificarCliente(eCliente[],int,int);




/** \brief Muestra menu para elegir que campos quiere modificar del cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño de array.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int menuModificacionesCliente(eCliente[],int);


void promedioEntreClientesMujeresHombres(eCliente[],int);
