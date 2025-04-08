# Analizador Léxico con Flex/Lex

Interprete de comandos matemáticos, creado usando flex y bison, para
la práctica 3 de la asignatura de Compiladores e Interpretes de la USC.

Código creado y probado en un sistema operativo `Ubuntu 20.04`, haciendo uso de los programas:

- `make 4.3`
- `gcc 10.3.0`
- `valgrind 3.15.0`
- `flex 2.6.4`
- `bison 3.7.5`

## Disposición del código

### ~/

Contiene los archivos [`makefile`](makefile) y [`README.md`](README.md)

### ~/includes/

Carpeta [`includes/`](includes/). Contiene las cabeceras del programa (.h).

### ~/src/

Carpeta [`src/`](src/). Contiene el código fuente del programa (.c).

### ~/flex/

Carpeta [`flex/`](flex/). Contiene el código y directivas de flex para crear el escaner (.l).

### ~/bison/

Carpeta [`bison/`](bison/). Contiene el código y directivas de bison para crear el parser (.y).

### ~/obj/

Carpeta contenedora de los archivos de código objeto.
Se crea al compilar el programa mediante el [`makefile`](makefile).

### ~/target/

Carpeta contenedora del ejecutable creado por la compilación.
Se crea al compilar y enlazar el programa mediante el [`makefile`](makefile).

## Compilación del programa

Para compilar el programa haremos uso del archivo [`makefile`](makefile).

Contiene una serie de opciones interesantes pero las principales son:

- **all (Opción por defecto)**. Crea el escaner con `flex` y analizador sintactico de `bison`, si
	es necesario, y compila los archivos de código que hayan sido modificados y los enlaza, creando el archivo ejecutable.

	El nombre por defecto del ejecutable es `interprete` y se puede cambiar en
	el elemento `TARGET` del [`makefile`](makefile):
	
	```makefile
	# Nombre del programa
	TARGET := <nombre_del_ejecutable>
	```

- **clean**. Borra las carpetas `obj/` y `target/` junto con todos los archivos
	contenidos.

- **remake**. Ejecuta las reglas `clean` y `all`, en ese orden.

## Ejecución del programa

Para ejecutar el programa solo se necesita llamar al ejecutable `$ <interprete>`.

A continuación, se muestra un ejemplo de ejecución:

```bash
$ ./interprete 				# Ejecución correcta del interprete
 >> var = 3 ^ 2 + 8.1
  17.1
 >> var += 5.04
  22.14
```

*Notas: Suponemos de la existencia de los archivos ejecutables y de codigo python2 en
el directorio de trabajo.*
