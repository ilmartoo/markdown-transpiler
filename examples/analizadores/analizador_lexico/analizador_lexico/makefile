#------- Makefile para la compilación de un programa en C -------
# Comando de compilacion
CC			:= gcc

# Nombre del programa
TARGET		:= analizador

# Directorios de includes, codigo fuente, objetos y destino
SRCDIR		:= src
INCDIR		:= includes
OBJDIR		:= obj
TARGETDIR	:= target

# Flags, librerias e includes
FLAGS		:= -Wall -g3
LIB			:=
INC			:= -I$(INCDIR)

#----------------------------------------------------------------
# REGLAS - NO EDITAR
#----------------------------------------------------------------
SOURCES  	:= $(wildcard $(SRCDIR)/*.c)
OBJECTS		:= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.c=.o))
INCLUDES	:= $(wildcard $(INCDIR)/*.h)

# Opcion por defecto
all: directories $(TARGET)
	@echo "\e[1;32m[$@] Compilación del programa completada\e[0m"

# Limpieza + opcion por defecto
remake: clean all
	@echo "\e[1;34m[$@] Remake del programa completado\e[0m"

# Enlazado del programa
$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) -o $(TARGETDIR)/$(TARGET) $(INC) $^ $(LIB)
	@echo "\e[1;34m[$@] Programa enlazado\e[0m"

# Compilación del codigo
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@echo "\e[1;34m[$@] Archivo $< compilado \e[0m"

# Creacion de directorios
directories:
	@mkdir -p $(OBJDIR) $(TARGETDIR)
	@echo "\e[1;34m[$@] Directorios creados\e[0m"

# Limpiado de archivos ejecutables y objeto
clean: cleanObj
	$(RM) -r $(TARGETDIR)
	@echo "\e[1;34m[$@] Borrado total completado\e[0m"
	
# Limpiado de archivos objeto
cleanObj:
	$(RM) -r $(OBJDIR)
	@echo "\e[1;34m[$@] Borrado de codigo objeto completado\e[0m"
