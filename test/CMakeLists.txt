cmake_minimum_required(VERSION 3.5.1)
file(GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
foreach(source ${srcs})
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
    target_link_libraries(${name} leveldb)
endforeach(source)

