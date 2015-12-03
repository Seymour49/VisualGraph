project(testvisualgraph)

add_executable(testvisualgraph main.cpp ../model/graphemat.cpp ../model/sommet.cpp ../model/sommetMat.cpp ../model/algographemat.cpp)
add_definitions(-Wall -std=c++11)

install(TARGETS testvisualgraph RUNTIME DESTINATION bin)
