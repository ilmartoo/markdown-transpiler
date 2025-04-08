#------- Makefile para la compilación de un programa en C -------
# Comando de compilacion
CC			:= gcc -Wall

# Nombre del programa
TARGET		:= analizador_flex

# Directorios de includes, codigo fuente, objetos y destino
SRCDIR		:= src
LEXDIR		:= flex
INCDIR		:= includes
OBJDIR		:= obj
TARGETDIR	:= target

# Flags, librerias e includes
FLAGS		:= 
LIB			:= 
INC			:= -I$(INCDIR)

#----------------------------------------------------------------
# REGLAS - NO EDITAR
#----------------------------------------------------------------
SOURCES_SRC := $(wildcard $(SRCDIR)/*.c)
SOURCES_LEX := $(patsubst %.l,%.yy.c,$(wildcard $(LEXDIR)/*.l))
SOURCES		:= $(SOURCES_SRC) $(SOURCES_LEX)
OBJECTS_SRC	:= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES_SRC:.c=.o))
OBJECTS_LEX	:= $(patsubst $(LEXDIR)/%,$(OBJDIR)/%,$(patsubst %.yy.c,%.o,$(SOURCES_LEX)))
OBJECTS		:= $(OBJECTS_SRC) $(OBJECTS_LEX)
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

# Compilación del codigo fuente
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@echo "\e[1;34m[$@] Archivo $< compilado \e[0m"

# Compilacion de los escaneres
$(OBJDIR)/%.o: $(LEXDIR)/%.yy.c $(INCLUDES)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@echo "\e[1;34m[$@] Archivo $< compilado \e[0m"

# Compilacion de archivos flex
$(LEXDIR)/%.yy.c: $(LEXDIR)/%.l
	flex -o $@ $<
	@echo "\e[1;34m[$@] Archivo $< convertido en escaner \e[0m"

# Creacion de directorios
directories:
	@mkdir -p $(OBJDIR) $(TARGETDIR)
	@echo "\e[1;34m[$@] Directorios creados\e[0m"

# Limpiado de archivos ejecutables y objeto
clean: cleanObj cleanFlex
	$(RM) -r $(TARGETDIR)
	@echo "\e[1;34m[$@] Borrado total completado\e[0m"
	
# Limpiado de archivos flex
cleanFlex:
	$(RM) -r $(FLEXDIR)/*.yy.c
	@echo "\e[1;34m[$@] Borrado de codigo flex generado completado\e[0m"

# Limpiado de archivos objeto
cleanObj:
	$(RM) -r $(OBJDIR)
	@echo "\e[1;34m[$@] Borrado de codigo objeto completado\e[0m"
