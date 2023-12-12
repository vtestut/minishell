project(ft)
cmake_minimum_required(VERSION 3.00)

file(GLOB SRC src/**/*.c src/*.c)
include_directories(./)

add_library(ft ${SRC})
target_compile_options(ft PRIVATE -g -Wall -Wextra -Werror)

add_library(ft_asan ${SRC})
target_link_libraries(ft_asan asan)
target_compile_options(ft_asan PRIVATE -g -Wall -Wextra -Werror -fsanitize=address)