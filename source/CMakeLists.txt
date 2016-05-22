# Build example
add_executable(example
  example.cpp
  vec2.cpp
  )
target_link_libraries(example
  m
  )
  
# Build aufgabe2bis4
add_executable(aufgabe2bis4
  aufgabe2bis4.cpp
  )
target_link_libraries(example
  m
  )

# Build aufgabe5
add_executable(aufgabe5
  aufgabe5.cpp
  circle.cpp
  )
target_link_libraries(example
  m
  )

# Build tests
add_executable(tests
  tests.cpp
  )
target_link_libraries(tests
 m
 )
