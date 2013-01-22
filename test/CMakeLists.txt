FIND_PACKAGE(ICU REQUIRED)

SET(sources main.cpp)
SOURCE_GROUP("Source Files" FILES ${sources})

IF(UNIX)
    SET(UNIX_LIBS pthread)
ENDIF()

INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})
ADD_EXECUTABLE(google-url-test ${sources})
TARGET_LINK_LIBRARIES(google-url-test google-url-base googleurl ${ICU_LIBRARIES} ${UNIX_LIBS})
