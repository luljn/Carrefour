#!/bin/bash

gcc -c ../src/main.c -I../src/includes -o ../build/main.o

gcc -c ../src/implementations/carrefour.c -I../src/includes -o ../build/carrefour.o
gcc -c ../src/implementations/file.c -I../src/includes -o ../build/file.o
gcc -c ../src/implementations/serveur.c -I../src/includes -o ../build/serveur.o
gcc -c ../src/implementations/utils.c -I../src/includes -o ../build/utils.o
gcc -c ../src/implementations/vehicule.c -I../src/includes -o ../build/vehicule.o

gcc ../build/main.o ../build/carrefour.o ../build/file.o ../build/serveur.o ../build/utils.o ../build/vehicule.o -o ../executable/main

# gcc ../src/main.c ../src/implementations/carrefour.c ../src/implementations/file.c ../src/implementations/serveur.c ../src/implementations/utils.c ../src/implementations/vehicule.c -I../src/includes -o ../executable/main