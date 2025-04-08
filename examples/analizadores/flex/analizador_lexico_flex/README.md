# Analizador Léxico con Flex/Lex
Análizador léxico de Python2, junto con un escaner creado en `flex`, para la práctica 2 
de la asignatura de Compiladores e Interpretes de la USC.

Código creado y probado en un sistema operativo `Ubuntu 20.04.2 LTS`, haciendo uso de los programas:
- `gcc 9.3.0`
- `valgrind 3.15.0`
- `flex 2.6.4` 

## Disposición del código
### ~/
Contiene los archivos [`makefile`](makefile) y [`README.md`](README.md)

### ~/includes/
Carpeta [`includes/`](includes/). Contiene las cabeceras del programa (.h).

### ~/src/
Carpeta [`src/`](src/). Contiene el código fuente del programa (.c).

### ~/lex/
Carpeta [`lex/`](lex/). Contiene el código y directivas de flex para crear el escaner (.l).

### ~/obj/
Carpeta contenedora de los archivos de código objeto.
Se crea al compilar el programa mediante el [`makefile`](makefile).

### ~/target/
Carpeta contenedora del ejecutable creado por la compilación.
Se crea al compilar y enlazar el programa mediante el [`makefile`](makefile).

## Compilación del programa
Para compilar el programa haremos uso del archivo [`makefile`](makefile).

Contiene una serie de opciones interesantes pero las principales son:
- **all (Opción por defecto)**. Crea el escaner con `flex` si es necesario, compila los archivos 
	de código que hayan sido modificados y los enlaza, creando el archivo ejecutable.
	
	El nombre por defecto del ejecutable es `analizador_flex` y se puede cambiar en 
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
$ ./analizador_flex archivo.py               # Ejecución correcta
$ ./analizador_flex archivo1.py archivo2.py  # Ejecución incorrecta
$ ./analizador_flex                          # Ejecución incorrecta
```
*Notas: Suponemos de la existencia de los archivos ejecutables y de codigo python2 en 
el directorio de trabajo.*