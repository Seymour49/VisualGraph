project(testvisualgraph)

add_executable(testvisualgraph main.cpp ../model/graphemat.cpp ../model/sommetMat.cpp)
add_definitions(-Wall)

install(TARGETS testvisualgraph RUNTIME DESTINATION bin)
