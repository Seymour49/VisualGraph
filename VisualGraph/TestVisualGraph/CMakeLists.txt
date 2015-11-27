project(testvisualgraph)

add_executable(testvisualgraph main.cpp ../model/graphemat.cpp ../model/sommetMat.cpp ../controller/algographemat.cpp)
add_definitions(-Wall)

install(TARGETS testvisualgraph RUNTIME DESTINATION bin)
