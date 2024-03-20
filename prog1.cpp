#include <iostream>
#include <chrono>
#define MAX 100
double A[MAX][MAX], x[MAX], y[MAX];

int main(){
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = 1.0;
        }
        x[i] = 1.0;
    }
    
    for (int i = 0; i < MAX; i++) {
        y[i] = 0.0;
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Primero: " << elapsed.count() << " segundos" << std::endl;

    for (int i = 0; i < MAX; i++) {
        y[i] = 0.0;
    }

    start_time = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    end_time = std::chrono::high_resolution_clock::now();
    elapsed = end_time - start_time;
    std::cout << "Segundo: " << elapsed.count() << " segundos" << std::endl;

    return 0;
}

