# Analizador Léxico
Análizador léxico de Python2 creado para la práctica 1 
de la asignatura de Compiladores e Interpretes de la USC.

Código creado y probado en un sistema operativo `Ubuntu 20.04.2 LTS`, haciendo uso de los programas:
- `gcc 9.3.0`
- `valgrind 3.15.0`

## Disposición del código
### ~/
Contiene los archivos [`makefile`](makefile) y [`README.md`](README.md)

### ~/includes/
Carpeta [`includes/`](includes/). Contiene las cabeceras del programa (.h).

### ~/src/
Carpeta [`src/`](src/). Contiene el código fuente del programa (.c).

### ~/obj/
Carpeta contenedora de los archivos de código objeto.
Se crea al compilar el programa mediante el [`makefile`](makefile).

### ~/target/
Carpeta contenedora del ejecutable creado por la compilación.
Se crea al compilar y enlazar el programa mediante el [`makefile`](makefile).

## Compilación del programa
Para compilar el programa haremos uso del archivo [`makefile`](makefile).

Contiene una serie de opciones interesantes pero las principales son:
- **all (Opción por defecto)**. Compila los archivos de código que hayan sido 
    modificados y los enlaza, creando el archivo ejecutable.
	
	El nombre por defecto del ejecutable es `analizador` y se puede cambiar en 
	el elemento `TARGET` del [`makefile`](makefile):
	```makefile
	# Nombre del programa
	TARGET := <nombre_del_ejecutable>
	```
	
- **clean**. Borra las carpetas `obj/` y `target/` junto con todos los archivos 
	contenidos.

- **remake**. Ejecuta las reglas `clean` y `all`, en ese orden.

## Ejecución del programa
Para ejecutar el programa se necesita pasarle el archivo de código a analizar 
lexicamente como argumento siguiendo el formato `$ <programa_analizador> <archivo.py>`.

A continuación, se muestran algunos ejemplos:
```bash
$ ./analizador archivo.py               # Ejecución correcta
$ ./analizador archivo1.py archivo2.py  # Ejecución incorrecta
$ ./analizador                          # Ejecución incorrecta
```
*Notas: Suponemos de la existencia de los archivos ejecutables y de codigo python2 en 
el directorio de trabajo.*