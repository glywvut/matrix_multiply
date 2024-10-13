//
//  main.cpp
//  MatrixMult
//
//  Created by Daniil Litvyakov on 30.09.2024.
//

#include <iostream>
#include <random>
#include <chrono>
using namespace std;


int main() {
    const int n{205 };
    double A[n][n], B[n][n], C[n][n];
    int upper_bound = 1000;
    int lower_bound = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = lower_bound + (upper_bound - lower_bound) * (rand() % INT_MAX)
                / 10.0f;
            B[i][j] = lower_bound + (upper_bound - lower_bound) * (rand() % INT_MAX)
                / 10.0f;
        }
    }

    std::chrono::time_point<std::chrono::system_clock> time1, time2;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0.0;
        }
    }

    time1 = std::chrono::system_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    time2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = time2 - time1;
    cout << "i,j,k: " << elapsed_seconds.count() << endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0.0;
        }
    }
    time1 = std::chrono::system_clock::now();
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    time2 = std::chrono::system_clock::now();
    elapsed_seconds = time2 - time1;
    cout << "j,i,k: " << elapsed_seconds.count() << endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0.0;
        }
    }
    time1 = std::chrono::system_clock::now();
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    time2 = std::chrono::system_clock::now();
    elapsed_seconds = time2 - time1;
    cout << "j,k,i: "  <<elapsed_seconds.count()<< endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0.0;
        }
    }
    time1 = std::chrono::system_clock::now();
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    time2 = std::chrono::system_clock::now();
    elapsed_seconds = time2 - time1;
    cout << "i,k,j: " << elapsed_seconds.count() << endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0.0;
        }
    }
    time1 = std::chrono::system_clock::now();
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {

                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    time2 = std::chrono::system_clock::now();
    elapsed_seconds = time2 - time1;
    cout << "k,j,i: " << elapsed_seconds.count() << endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0.0;
        }
    }
    time1 = std::chrono::system_clock::now();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {


                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    time2 = std::chrono::system_clock::now();
    elapsed_seconds = time2 - time1;
    cout << "k,i,j: " << elapsed_seconds.count() << endl;
}