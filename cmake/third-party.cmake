
include(FetchContent)


include(detail/spdlog)
#include(detail/yaml-cpp)

if (ENABLE_BENCHMARK)
  include(detail/benchmark)
endif()


