# Nom du compilateur
CC = gcc

# Options de compilation pour inclure les en-têtes
CFLAGS = -I/usr/local/include

# Options de liaison pour inclure les bibliothèques
LDFLAGS = -L/usr/local/lib -lcs50

# Nom de l'exécutable
TARGET = greet

# Les fichiers objets à générer
OBJS = greet.o

# Règle par défaut
all: $(TARGET)

# Règle pour générer l'exécutable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Règle pour générer les fichiers objets
%.o: %.c
	$(CC) -c $< $(CFLAGS)

# Règle de nettoyage
clean:
	rm -f $(OBJS) $(TARGET)

