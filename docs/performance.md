# Performance Evaluation

This document contains benchmark results for the parallel connected components implementations.

---

## Experimental Setup

- **Dataset:** LiveJournal social network (com-LiveJournal.mtx)
- **Nodes:** 3,997,962
- **Edges:** 69,362,378
- **System:** Intel Core i7-11800H @ 2.30GHz
- **Threads:** 8
- **Trials:** 10

---

## Label Propagation

| Algorithm  | Mean Time (s) | Throughput (Medges/s) | Speedup | Efficiency |
|------------|---------------|-----------------------|---------|------------|
| Sequential | 0.4392        | 157.9                 | 1.00×   | 100%       |
| OpenMP     | 0.1031        | 672.1                 | 4.26×   | 53.2%      |
| Pthreads   | 0.1101        | 630.2                 | 3.99×   | 49.9%      |
| **OpenCilk** | **0.0859**  | **807.3**             | **5.11×** | **63.9%** |

---

## Union-Find

| Algorithm  | Mean Time (s) | Throughput (Medges/s) | Speedup | Efficiency |
|------------|---------------|-----------------------|---------|------------|
| Sequential | 0.1800        | 385.3                 | 1.00×   | 100%       |
| **OpenMP** | **0.0472**    | **1469.9**            | **3.82×** | **47.7%** |
| Pthreads   | 0.0492        | 1411.2                | 3.66×   | 45.8%      |
| OpenCilk   | 0.0528        | 1314.2                | 3.41×   | 42.6%      |

---

## Observations

- Union-Find consistently outperforms Label Propagation
- OpenMP provides the best overall performance on this platform
- Efficiency decreases due to synchronization and memory contention
