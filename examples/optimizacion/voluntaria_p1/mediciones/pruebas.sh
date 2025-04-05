options="O0 O1 O2 O3 Os"

for op in $options
do
	echo "Compilando codigo con ${op}..."
	gcc -o "mediciones_${op}.out" mediciones.c "-${op}"
	echo "Ejecutando pruebas de ${op}..."
	for i in {0..50}
	do
		./"mediciones_${op}.out"
	done
	mv tiempos.csv "tiempos_${op}.csv"
	echo -e "Finalizadas pruebas de ${op}.\n"
done
