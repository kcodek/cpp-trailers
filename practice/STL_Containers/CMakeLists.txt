add_library(STL_Containters container.cpp)
add_subdirectory(set_q)
add_subdirectory(list_q)
add_subdirectory(vector_q)
add_subdirectory(map_q)

target_link_libraries(STL_Containters set_q list_q vector_q map_q)
