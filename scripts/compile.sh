#!/bin/bash

# gcc - c ../src/main.c -I../src/includes -o ../build/main.o
# gcc - c ../src/implementations/vehicule.c -I../src/includes -o ../build/vehicule.o

# gcc ../build/main.o ../build/vehicule.o -o ../executable/main

gcc ../src/main.c ../src/implementations/carrefour.c ../src/implementations/serveur.c ../src/implementations/utils.c ../src/implementations/vehicule.c -I../src/includes -o ../executable/main