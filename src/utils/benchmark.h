#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "matrix.h"

typedef struct {
    char   *algorithm_name;
    char   *dataset_filepath;
    double *times;
    double time_max;
    double time_min;
    double time_median;
    double time_avg;
    double time_stddev;
    int    connected_components;
    uint8_t n_threads;
    uint16_t n_trials;
    uint32_t matrix_rows;
    uint32_t matrix_cols;
    uint32_t matrix_nnz;
} Benchmark;

Benchmark*
benchmark_init(const char *name,
               const char *filepath,
               const unsigned int n_trials,
               const unsigned int n_threads,
               const CSCBinaryMatrix *mat);

void benchmark_free(Benchmark *b);

int benchmark_cc(int (*cc_func)(const CSCBinaryMatrix*, const int), const CSCBinaryMatrix *m, Benchmark *b);

void benchmark_print(Benchmark *b);

#endif // BENCHMARK_H
