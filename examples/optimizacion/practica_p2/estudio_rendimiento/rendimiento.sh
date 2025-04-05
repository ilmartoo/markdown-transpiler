#!/bin/bash

# Declaración de variables iniciales
tipo="final" 				 # Rango de N
paso=100000000				 # Paso de N
iter=2	 					 # ITER según tipo y paso
ejecutable="rendimiento.out" # Nombre del ejecutable

	n=$paso # Valor inicial de N

	# Obtención de tiempos según N
	for j in {1..20} # 20 iteraciones
	do
		echo -e "\x1b[32m n = ${n}\x1b[0m"
		
		# Repeticiones de ejecución
		for k in {1..15}
		do
			echo -n " ... $k"
			"./${ejecutable}" $n $iter
		done
		echo "!"
		
		# Renombrado de archivos
		mv tiempos_opt.csv "time_opt${n}.csv"
		mv tiempos_nopt.csv "time_nopt${n}.csv"
		
		n=$(($n + $paso)) # N = N + paso
	
	done
	
	# Combinado de archivos de tiempo
	paste time_opt*.csv -d',' > "tiempos_opt_${tipo}.csv"
	paste time_nopt*.csv -d',' > "tiempos_nopt_${tipo}.csv"
	rm time_opt*.csv time_nopt*.csv
