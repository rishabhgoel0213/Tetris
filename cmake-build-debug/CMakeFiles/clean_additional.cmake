# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TetrisGraphicsQt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TetrisGraphicsQt_autogen.dir/ParseCache.txt"
  "TetrisGraphicsQt_autogen"
  )
endif()
