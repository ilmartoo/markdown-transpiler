#!/bin/bash

# Declaración de variables iniciales
tipo=("bajo" "medio" "alto") # Rango de N
paso=(200 200000 200000000)	 # Paso de N
iter=(400000 600 1)	 		 # ITER según tipo y paso
ejecutable="rendimiento.out" # Nombre del ejecutable

# Bucle de rangos de valores de N
for i in {1..2}
do
	echo -e "\x1b[32m Ejecución de tipo \"${tipo[i]}\"\x1b[0m"

	n=${paso[i]} # Valor inicial de N

	# Obtención de tiempos según N
	for j in {0..9} # 10 iteraciones
	do
		echo -e "\x1b[32m n = ${n}\x1b[0m"
		
		# Repeticiones de ejecución
		for k in {1..5}
		do
			"./${ejecutable}" $n ${iter[i]}
		done
		
		# Renombrado de archivos
		mv tiempos_opt.csv "time_opt${n}.csv"
		mv tiempos_nopt.csv "time_nopt${n}.csv"
		
		n=$(($n + ${paso[i]})) # N = N + paso
	
	done
	
	# Combinado de archivos de tiempo
	paste time_opt*.csv -d',' > "tiempos_opt_${tipo[i]}.csv"
	paste time_nopt*.csv -d',' > "tiempos_nopt_${tipo[i]}.csv"
	rm time_opt*.csv time_nopt*.csv
	
done