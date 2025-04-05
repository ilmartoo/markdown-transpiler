import csv

CELL_TAM = 10 # Tamaño de una celda

# IMPRESIÓN DEL SEPARADOR
def separator(n_values = 1):
	return '+' + '+'.join(['-' * (CELL_TAM + 2)] * n_values) + '+\n'

# IMPRESIÓN DEL HEADER
def string_header(head: list):
	header = separator(len(head)) + '|\x1b[1;37;40m'
	header += '\x1b[0m|\x1b[1;37;40m'.join([f' {value: <{CELL_TAM}} ' for value in head])
	header += '\x1b[0m|\n' + separator(len(head))
	return header

# IMPRESIÓN DE LA TABLA
def print_lines(reader: csv.DictReader):
	# Header
	tabla = string_header(reader.fieldnames)
	
	# Lineas
	odd = False
	for line in reader:
		if odd:
			color = '\x1b[47;30m'
		else:
			color = '\x1b[1;47;30m'
		odd = not odd
	
		tabla += f'|{color}'
		tabla += f'\x1b[0m|{color}'.join([f' {value: <{CELL_TAM}} ' for value in line.values()]) + '\x1b[0m|\n'
	
	# Final e impresión
	tabla += separator(len(reader.fieldnames))
	print(tabla)

# MAIN
if __name__ == '__main__':
	with open('tiempos.csv', 'r') as file:
		print_lines(csv.DictReader(file))