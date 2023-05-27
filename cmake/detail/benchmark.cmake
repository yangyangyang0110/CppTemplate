#set(benchmark_ROOT $ENV{HOME}/3rdparty/google_benchmark)
#find_package(benchmark REQUIRED)
#list(APPEND PUBLIC_MODULE_LIBRARIES_LIST benchmark::benchmark)

FetchContent_Declare(
  benchmark
  GIT_REPOSITORY "https://gitee.com/mirrors/google-benchmark.git"
  GIT_TAG v1.8.0
)
FetchContent_MakeAvailable(benchmark)
