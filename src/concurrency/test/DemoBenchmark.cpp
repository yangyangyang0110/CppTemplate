/* Proj: CppHighProgramming
 * File: DemoBenchmark.cpp
 * Created Date: 2023/5/27
 * Author: YangYangYang (yangyangyang0110@outlook.com)
 * Description:
 * -----
 * Last Modified: 2023/5/27 10:21:01
 * Modified By: YangYangYang (yangyangyang0110@outlook.com)
 * -----
 * Copyright (c) 2023  . All rights reserved.
 */

#include <benchmark/benchmark.h>

// 计算阶乘
static void BM_Factorial(benchmark::State& state) {
    for (auto _ : state) {
        int n = state.range(0);
        int result = 1;
        while (n > 1) {
            result *= n--;
        }
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_Factorial)->RangeMultiplier(2)->Range(1, 1024);

// 程序开始点
BENCHMARK_MAIN();
