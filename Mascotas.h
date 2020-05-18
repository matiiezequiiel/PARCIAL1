typedef struct
{
    char nombre[20];
    char tipo[20];
    int idRaza;
    int edad;
    float peso;
    char sexo;
    int idMascota;
    int idDelDuenio;
    int estado;

}eMascota;

typedef struct
{
    char nombreRaza[20];
    char pais[20];
    char idRaza;
}eRaza;

void hardcodearMascotas(eMascota[] ,int);




/** \brief Busca posicion libre en array de clientes para su posterior carga.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int Posicion libre, -1 no hay espacio.
 *
 */
int buscarLibreArrayMascota(eMascota[] ,int);


/** \brief Baja logica de una mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño del array de mascotas.
 * \param int ID UNICO de la mascota a dar de baja.
 * \return int 1 baja correcta, 0 baja cancelada.
 *
 */
int bajaMascota(eMascota[] ,int,int);



/** \brief Modificar datos de una mascota.
 *
 * \param eCliente[] Array de mascotas.
 * \param int Tamaño de array.
 * \param int ID unico de la mascota a modificar.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int modificarMascota(eMascota[] ,int,int,eRaza[],int);




/** \brief Muestra menu para elegir que campos quiere modificar de la mascota.
 *
 * \param eCliente[] Array de mascotas.
 * \param int Tamaño de array.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int menuModificaciones(eMascota[] ,int,eRaza[],int);




/** \brief Inicializa array de mascotas para posterior carga.
 *
 * \param eCliente[] Array de mascotas.
 * \param int Tamaño del array.
 * \return void
 *
 */
void initMascotas(eMascota[] ,int);


/** \brief Mostrar listado de mascotas por un tipo especifico elegido por el usuario.
 *
 * \param Array de mascotas
 * \param Tamaño del array.
 * \return
 *
 */

void mostrarMascotasPorTipoElegido(eMascota[] ,int,eRaza[],int);



/** \brief Muestra promedio de edad de las mascotas.
 *
 * \param eMascota[] Array de mascotas
 * \param int Tamaño del array.
 * \return void
 *
 */
void promedioEdadMascotas(eMascota[] ,int);




/** \brief Muestra promedio de edad de las mascotas por tipo.
 *
 * \param eMascota[] Array de mascotas
 * \param int Tamaño del array.
 * \return void
 *
 */
void promedioEdadMascotaPorTipo(eMascota[] ,int);



void mostrarRaza(eRaza[],int);
