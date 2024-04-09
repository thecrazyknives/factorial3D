#!/bin/bash

if [[ $# -ne 3 ]]; then
    echo "Uso: $0 <exec_per_case> <mat_size> <max_rand>"
    exit 1
fi

EXECUTIONS=$1
SIZE=$2
MAX_RAND=$3
STEP_S=10
STEP_R=10

echo "This benchmark was performed with the following parameters:" > info.txt
echo "" >> info.txt
echo "Executions per case: $EXECUTIONS" >> info.txt
echo "Max size of the matriz: $SIZE" >> info.txt
echo "Step in size dimension: $STEP_S" >> info.txt
echo "Max random number: $MAX_RAND" >> info.txt
echo "Step in rand dimension: $STEP_R" >> info.txt

> resultRowColumn.txt

gcc matrizFactorial.cpp -o matrizFactorial

for ((s = 1; s <= SIZE; s+=STEP_S)); do
    for ((r = 1; r <= MAX_RAND; r+=STEP_R)); do
        timeColumn=0
        timeRow=0
        for ((e = 0; e < EXECUTIONS; e++)); do
            # Utilizar bc para realizar operaciones con números decimales
            timeColumn=$(echo "$timeColumn + $(./matrizFactorial "$s" "$r" 1)" | bc)
            timeRow=$(echo "$timeRow + $(./matrizFactorial "$s" "$r" 0)" | bc)
        done
        # Calcular el promedio dividiendo por el número de ejecuciones
        timeColumn=$(echo "scale=10; $timeColumn / $EXECUTIONS" | bc)
        timeRow=$(echo "scale=10; $timeRow / $EXECUTIONS" | bc)
        echo "$s,$r,$timeRow,$timeColumn" >> resultRowColumn.txt
    done
done

#python grafica3DFactorial.py


