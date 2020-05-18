/** \brief Muestra menu de ABB
 *
 * \param void
 * \return int Opcion elegida por el usuario.
 *
 */
int mostrarMenuABM(void);


/** \brief Valida que una cadena contenga solo caracteres validos.
 *
 * \param char[] Cadena a validar
 * \return int 1 la cadena es valida, 0 la cadena no es valida.
 *
 */
int validarCadena(char[]);


/** \brief Ingresa una cadena con la opcion ingresada del usuario para su posterior validacion.
 *
 * \param char[] Cadena ingresada por el usuario.
 * \return float Numero validado.
 *
 */
float getFloat(char[]);


/** \brief Analisis de una cadena para determinar que sea flotante.
 *
 * \param char[] Cadena a analizar.
 * \return int 0 si la cadena es numero flotante, 0 si no es numerica.
 *
 */
int validarFloat(char[] );



int getInt(char[]);


/** \brief Analisis de una cadena para determinar que sea numerica.
 *
 * \param char[] Cadena a analizar.
 * \return 0 si la cadena es numerica, 0 si no es numerica.
 *
 */
int validarEntero (char[]);


/** \brief Validacion de un numero entre un rango minimo y maximo.
 *
 * \param entrada[] char Numero a validar.
 * \param rangoMinimo int Rango minimo para la validacion.
 * \param rangoMaximo int Rango maximo para la validacion.
 * \return int Numero validado.
 *
 */
int validarIntEntreRangos(char[],int,int);



/** \brief Ingresa un caracter escrito por el usuario para su posterior validacion.
 *
 * \param char Caracter ingresado por el usuario.
 * \return char Caracter validado.
 *
 */
char getChar(char);



/** \brief Analisis de una cadena para determinar que sea un caracter valido.
 *
 * \param char Caracter a validar
 * \return 0 si es valido, 1 si es invalido.
 *
 */
int validarChar (char);



/** \brief Formatea un nombre y apellido al siguiente formato: Aguirre, Matias.
 *
 * \param Nombre
 * \param Apellido
 *
 */
void formatearNombres (char*);




/** \brief Valida que el tipo de mascota sea Gato,Perro o Raro.
 *
 * \param char* Cadena a validar
 * \return int 1 cadena correcta, 0 cadena invalida.
 *
 */
int validarTipoMascota(char*);




/** \brief Valida que el telefono sea del formato XXXX-XXXX.
 *
 * \param char* Cadena a validar
 * \return int 1 cadena incorrecta, 0 cadena correcta
 *
 */
int validarTelefono(char*);



/** \brief Valida el sexo del cliente.
 *
 * \param char sexo ingresado.
 * \return intn 1 correcto,0 incorrecto:
 *
 */
int validarSexoClientes(char);



/** \brief Valida el sexo de la mascota.
 *
 * \param char sexo ingresado.
 * \return intn 1 correcto,0 incorrecto:
 *
 */
int validarSexoMascota(char);
