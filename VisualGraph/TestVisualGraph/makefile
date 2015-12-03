
CFLAGS= -std=c++11 -Wall

SRCDIR= ../model/
HEADDIR= ../model/
OBJDIR= ./Objets/

SRC= sommet.cpp graphemat.cpp sommetMat.cpp

OBJ= $(SRC:.cpp=.o)

FICSRC = $(wildcard $(SRCDIR)*.cpp) main.cpp

FICOBJ = $(OBJDIR)main.o $(OBJDIR)sommet.o $(OBJDIR)graphemat.o $(OBJDIR)sommetMat.o

test : $(FICOBJ)
	@echo
	@echo - Compilation du projet
	g++ $^ $(CFLAGS) -o $@.bin
	@echo
	
$(OBJDIR)main.o : main.cpp
	g++ -o $@ -c $^ $(CFLAGS)
	
$(OBJDIR)sommet.o	 : $(SRCDIR)sommet.cpp
	g++ -o $@ -c $^ $(CFLAGS)

$(OBJDIR)sommetMat.o : $(SRCDIR)sommetMat.cpp
	g++ -o $@ -c $^ $(CFLAGS)
	
$(OBJDIR)graphemat.o : $(SRCDIR)graphemat.cpp
	g++ -o $@ -c $^ $(CFLAGS)

all : aff test clean
		
aff : 	
	@echo - Affichage des fichiers sources et objets
	@echo
	@echo $(FICOBJ)
	@echo $(FICSRC)
	@echo

launch:
	exec ./test.bin
	@echo fini
	
clean:
	@echo - Nettoyage de fichiers Objets
	@echo 
	rm -rf $(FICOBJ)
	@echo 
	
cleanall : clean
	@echo - Nettoyage de fichiers exécutables
	@echo 
	rm -rf *.bin
	@echo 
	@echo - Nettoyage de fichiers de backup
	@echo 
	rm -rf $(SRCDIR)*~
	rm -rf $(HEADDIR)*~
	rm -rf *~
