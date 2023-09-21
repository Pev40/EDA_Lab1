#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <fstream>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};

    for (int dim : dimensions) {
        std::vector<std::vector<double>> points(100, std::vector<double>(dim));

        // Generar 100 puntos aleatorios de dimensión 'dim'
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < dim; ++j) {
                points[i][j] = dis(gen);
            }
        }

        // Calcular todas las distancias euclidianas entre pares de puntos
        std::vector<double> distances;
        for (int i = 0; i < 100; ++i) {
            for (int j = i + 1; j < 100; ++j) {
                double distance = 0.0;
                for (int k = 0; k < dim; ++k) {
                    distance += pow(points[i][k] - points[j][k], 2);
                }
                distance = sqrt(distance);
                distances.push_back(distance);
            }
        }

        // Crear un nombre de archivo único para cada dimensión
        std::string filename = "distances_" + std::to_string(dim) + ".csv";

        // Escribir las distancias en un archivo CSV
        std::ofstream file(filename);
        for (const auto& distance : distances) {
            file << distance << "\n";
        }
        file.close();
    }

    return 0;
}
