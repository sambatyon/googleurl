FIND_PACKAGE(ICU REQUIRED)

SET(LIBRARY_NAME googleurl)

FILE(GLOB GUrl_hdrs "*.h" "*.hh" "*.hpp")
FILE(GLOB GUrl_incl "${HEADERS_LOC}/googleurl/*.h"
                    "${HEADERS_LOC}/googleurl/*.hh"
                    "${HEADERS_LOC}/googleurl/*.hpp")
FILE(GLOB GUrl_srcs "*.c" "*.cc" "*.cpp")

LIST(REMOVE_ITEM GUrl_incl "${HEADERS_LOC}/googleurl/url_test_utils.h")
LIST(REMOVE_ITEM GUrl_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/url_test_utils.h")
LIST(REMOVE_ITEM GUrl_srcs "${CMAKE_CURRENT_SOURCE_DIR}/url_util_unittest.cc")
LIST(REMOVE_ITEM GUrl_srcs "${CMAKE_CURRENT_SOURCE_DIR}/url_parse_unittest.cc")
LIST(REMOVE_ITEM GUrl_srcs "${CMAKE_CURRENT_SOURCE_DIR}/url_canon_unittest.cc")
LIST(REMOVE_ITEM GUrl_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gurl_unittest.cc")
LIST(REMOVE_ITEM GUrl_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gurl_test_main.cc")

SOURCE_GROUP("Header Files" FILES ${GUrl_hdrs} ${GUrl_incl})
SOURCE_GROUP("Source Files" FILES ${GUrl_srcs})

IF (MSVC)
#    ADD_DEFINITIONS(-DGURL_DLL)
ENDIF()

INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})
ADD_LIBRARY(${LIBRARY_NAME} STATIC ${GUrl_hdrs} ${GUrl_srcs} ${GUrl_incl})
TARGET_LINK_LIBRARIES(${LIBRARY_NAME} google-url-base ${ICU_LIBRARIES})

INSTALL(TARGETS googleurl
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

INSTALL(FILES ${GUrl_incl} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/googleurl)
