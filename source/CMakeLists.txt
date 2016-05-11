# Build example
add_executable(example
  vec2.cpp
  )
 
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(example glfw ${COPY_BINARY})
 
# Build tests
add_executable(tests
  vec2.cpp
  tests.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES})
