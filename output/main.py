import matplotlib.pyplot as plt
import numpy as np

# Lista de dimensiones
dimensions = [10, 50, 100, 500, 1000, 2000, 5000]

# Iterar sobre cada dimensión
for dim in dimensions:
    # Construir el nombre del archivo CSV para la dimensión actual
    filename = f"distances_{dim}.csv"
    
    # Leer las distancias del archivo CSV
    with open(filename) as f:
        distances = [float(line.strip()) for line in f]
    
    # Crear el histograma
    plt.hist(distances, bins=20, edgecolor='black', alpha=0.7)
    
    # Añadir etiquetas y título
    plt.xlabel('Distancia')
    plt.ylabel('Frecuencia')
    plt.title(f'Histograma de Distancias para d={dim}')
    
    # Mostrar el histograma
    plt.show()
