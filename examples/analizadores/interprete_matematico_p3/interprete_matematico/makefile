#------- Makefile para la compilación de un programa en C -------
# Comando de compilacion
CC			:= gcc

# Nombre del programa
TARGET		:= interprete

# Directorios de includes, codigo fuente, objetos y destino
SRCDIR		:= src
LEXDIR		:= flex
BISDIR		:= bison
INCDIR		:= includes
OBJDIR		:= obj
TARGETDIR	:= target

# Flags, librerias e includes
FLAGS		:= -Wall -g3
LIB			:= -lm -ldl
INC			:= -I$(INCDIR)

#----------------------------------------------------------------
# REGLAS - NO EDITAR
#----------------------------------------------------------------
SOURCES_SRC := $(wildcard $(SRCDIR)/*.c)
SOURCES_LEX := $(patsubst %.l,%.yy.c,$(wildcard $(LEXDIR)/*.l))
SOURCES_BIS := $(patsubst %.y,%.tab.c,$(wildcard $(BISDIR)/*.y))
SOURCES		:= $(SOURCES_BIS) $(SOURCES_LEX) $(SOURCES_SRC)
OBJECTS_SRC	:= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES_SRC:.c=.o))
OBJECTS_LEX	:= $(patsubst $(LEXDIR)/%,$(OBJDIR)/%,$(patsubst %.yy.c,%.o,$(SOURCES_LEX)))
OBJECTS_BIS	:= $(patsubst $(BISDIR)/%,$(OBJDIR)/%,$(patsubst %.tab.c,%.o,$(SOURCES_BIS)))
OBJECTS		:= $(OBJECTS_BIS) $(OBJECTS_LEX) $(OBJECTS_SRC)
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

# Compilacion de flex
$(OBJDIR)/%.o: $(LEXDIR)/%.l $(INCLUDES)
	flex -o $(patsubst %.l,%.yy.c,$<) $<
	@echo "\e[1;34m[$@] Archivo flex $< convertido \e[0m"
	$(CC) $(FLAGS) $(INC) -o $@ -c $(patsubst %.l,%.yy.c,$<)
	@echo "\e[1;34m[$@] Archivo $< compilado \e[0m"

#Compilacion de bison
$(OBJDIR)/%.o: $(BISDIR)/%.y $(INCLUDES)
	bison --defines=includes/definiciones.h -o $(patsubst %.y,%.tab.c,$<) $<
	@echo "\e[1;34m[$@] Archivo bison $< convertido \e[0m"
	$(CC) $(FLAGS) $(INC) -o $@ -c $(patsubst %.y,%.tab.c,$<)
	@echo "\e[1;34m[$@] Archivo $< compilado \e[0m"
	

# Compilación del codigo fuente
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@echo "\e[1;34m[$@] Archivo $< compilado \e[0m"

# Creacion de directorios
directories:
	@mkdir -p $(OBJDIR) $(TARGETDIR)
	@echo "\e[1;34m[$@] Directorios creados\e[0m"

# Limpiado de archivos ejecutables y objeto
clean: cleanObj cleanFlex cleanBison
	$(RM) -r $(TARGETDIR)
	@echo "\e[1;34m[$@] Borrado total completado\e[0m"
	
# Limpiado de archivos flex
cleanFlex:
	$(RM) -r $(LEXDIR)/*.yy.c
	@echo "\e[1;34m[$@] Borrado de codigo flex generado completado\e[0m"

# Limpiado de archivos bison
cleanBison:
	$(RM) -r $(BISDIR)/*.tab.c $(INCDIR)/*.tab.h
	@echo "\e[1;34m[$@] Borrado de codigo flex generado completado\e[0m"

# Limpiado de archivos objeto
cleanObj:
	$(RM) -r $(OBJDIR)
	@echo "\e[1;34m[$@] Borrado de codigo objeto completado\e[0m"
