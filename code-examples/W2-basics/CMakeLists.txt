cmake_minimum_required(VERSION 3.20)
project(BasicBuildingBlocks)


add_executable(functions src/apps/functions.cpp)
add_executable(types src/apps/types.cpp)
add_executable(scope src/apps/namespaces_and_scope.cpp)
add_executable(preproc src/apps/preprocessor.cpp)

add_library(my_cool_library src/lib/my_cool_library.cpp)
target_include_directories(my_cool_library PUBLIC include)

add_executable(my_cool_executable src/apps/my_cool_executable.cpp)
target_link_libraries(my_cool_executable my_cool_library)
