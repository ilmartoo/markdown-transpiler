#!/bin/bash

# Declaración de valores de N
n_values=(10000 40000 70000 100000 400000 700000 1000000 4000000 7000000 10000000 40000000 70000000 100000000)

# Creación del codigo y ejecutables
if (( $# == 0 )) || [ $1 = "files" ]
then
	
	rm -f codigos/*.c # Borrado de archivos
	rm -f ejecutables/*.out # Borrado de archivos
	
	# Bucle de creación de archivos de código y ejecutables
	for n in ${n_values[@]}
	do
		echo "#define N ${n}" | cat - codigo_sin_n.c > "codigos/codigo_${n}.c"
		gcc -O1 -o "ejecutables/O1_${n}.out" "codigos/codigo_${n}.c"
		gcc -O1 -funroll-loops -o "ejecutables/frlp_${n}.out" "codigos/codigo_${n}.c"
	done
	
fi

# Ejecución de las pruebas
if (( $# == 0 )) || [ $1 = "execute" ]
then

	rm -f tiempos/*.csv # Borrado de archivos
	
	# Bucle de ejecución de programas y obtención de tiempos
	for n in ${n_values[@]}
	do
		echo -e "\x1b[32m>> N=${n} <<\x1b[0m"
		
		echo -e " \x1b[34m-O1\x1b[0m"
		for i in {1..12}
		do
			echo -n " ... $i"
			./"ejecutables/O1_${n}.out"
		done
		mv tiempos.csv "tiempos/time_O1_${n}.csv"
		echo "!"
		
		echo -e " \x1b[34m-O1 -funroll-loops\x1b[0m"
		for i in {1..12}
		do
			echo -n " ... $i"
			./"ejecutables/frlp_${n}.out"
		done
		mv tiempos.csv "tiempos/time_frlp_${n}.csv"
		echo "!"
		
	done
	
	paste tiempos/time_O1_*.csv -d"," > time_O1.csv
	paste tiempos/time_frlp_*.csv -d"," > time_frlp.csv

fi