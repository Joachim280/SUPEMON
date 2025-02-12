# Définition du compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Dossiers
SRC_DIR = supemon
INCLUDE_DIR = include

# Liste des fichiers source et objets
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

# Nom de l'exécutable final
EXEC = supemon.exe

# Règle principale
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Compilation de chaque fichier source en fichier objet
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Nettoyage des fichiers compilés
clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)

# Recompiler à zéro
rebuild: clean all
