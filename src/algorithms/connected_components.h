/**
 * @file connected_components.h
 * @brief Connected components counting algorithms for sparse binary matrices.
 *
 * Provides sequential and parallel implementations of label propagation
 * algorithms to count connected components in a sparse binary matrix (CSC format).
 *
 * Implementations:
 * - Sequential
 * - OpenMP
 * - Pthreads
 * - OpenCilk
 */

#ifndef CONNECTED_COMPONENTS_H
#define CONNECTED_COMPONENTS_H

#include "matrix.h"

/**
 * @brief Computes connected components using sequential algorithms.
 *
 * Supported variants:
 *   0: Label propagation (simple, slower)
 *   1: Union-find (more complex, faster)
 *
 * @param matrix Sparse binary matrix in CSC format
 * @param n_threads Unused (for API compatibility with parallel version)
 * @param algorithm_variant Algorithm selection (0 or 1)
 * @return Number of connected components, or -1 on error
 */
int cc_sequential(const CSCBinaryMatrix *matrix, const unsigned int n_threads, const unsigned int algorithm_variant);

/**
 * @brief Computes connected components using parallel algorithms.
 *
 * Supported variants:
 *   0: Label propagation (simple, slower)
 *   1: Union-find with Rem's algorithm (more complex, faster)
 *
 * Both algorithms use OpenMP for parallelization and are designed to
 * scale efficiently across multiple cores.
 *
 * @param matrix Sparse binary matrix in CSC format
 * @param n_threads Number of OpenMP threads to use
 * @param algorithm_variant Algorithm selection (0 or 1)
 * @return Number of connected components, or -1 on error
 */
int cc_openmp(const CSCBinaryMatrix *matrix, const unsigned int n_threads, const unsigned int algorithm_variant);

/**
 * @brief Count connected components using parallel label propagation with opencilk
 * @param matrix Input sparse binary matrix in CSC format
 * @param n_threads Number of threads to use
 * @param algorithm_variant Algorithm variant to use:
 *                          - 0: TODO: add variants.
 *                          - 1: TODO: add variants.
 * @return Number of connected components, or -1 on error
 */
int cc_cilk(const CSCBinaryMatrix *matrix, const unsigned int n_threads, const unsigned int algorithm_variant);

/**
 * @brief Count connected components using parallel label propagation with pthreads
 * @param matrix Input sparse binary matrix in CSC format
 * @param n_threads Number of threads to use
 * @param algorithm_variant Algorithm variant to use:
 *                          - 0: TODO: add variants.
 *                          - 1: TODO: add variants.
 * @return Number of connected components, or -1 on error
 */
int cc_pthreads(const CSCBinaryMatrix *matrix, const unsigned int n_threads, const unsigned int algorithm_variant);

#endif
