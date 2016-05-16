# Build example
add_executable(example
  example.cpp
  vec2.cpp
  )
target_link_libraries(example
  m)
  
# Build aufgabe2bis4
add_executable(aufgabe2bis4
  aufgabe2bis4.cpp
  )
target_link_libraries(example
  m)

# Build tests
add_executable(tests
  vec2.cpp
  tests.cpp
  )
target_link_libraries(tests
 m)
