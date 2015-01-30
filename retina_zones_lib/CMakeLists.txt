CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(KEYWORD retina_zones)

# Start a project
PROJECT(${KEYWORD})

# Define system type
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(SYSTEM_FOLDER_NAME linux)
ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(SYSTEM_FOLDER_NAME win32)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Define standard paths.
SET(MY_OUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/out/${SYSTEM_FOLDER_NAME})
SET(MY_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Search for source code.
FILE(GLOB folder_source ${MY_SRC_PATH}/*.cpp)
FILE(GLOB folder_header ${MY_SRC_PATH}/*.h)
SOURCE_GROUP("Source Files" FILES ${folder_source})
SOURCE_GROUP("Header Files" FILES ${folder_header})

# Automatically add include directories if needed.
FOREACH(header_file ${folder_header})
  GET_FILENAME_COMPONENT(p ${header_file} PATH)
  INCLUDE_DIRECTORIES(${p})
ENDFOREACH(header_file ${folder_header})

# Set location for binary output
set(LIBRARY_OUTPUT_PATH ${MY_OUT_PATH})

# Set up our library.
IF (folder_source)
  ADD_LIBRARY(${KEYWORD} SHARED ${folder_source} ${folder_header})
ELSE (folder_source)
  MESSAGE(FATAL_ERROR "No source code files found. Please add something")
ENDIF (folder_source)

TARGET_LINK_LIBRARIES(${KEYWORD} xml_config)

# Setup make install
INSTALL_TARGETS(/lib ${KEYWORD})
INSTALL(FILES ${folder_header}        
         DESTINATION "/usr/local/include/retina_zones")
