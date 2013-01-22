
FILE(GLOB Base_hdrs "*.h" "*.hh" "*.hpp")
FILE(GLOB Base_incl "${HEADERS_LOC}/googleurl/base/*.h"
                    "${HEADERS_LOC}/googleurl/base/*.hh"
                    "${HEADERS_LOC}/googleurl/base/*.hpp")
FILE(GLOB Base_srcs "*.c" "*.cc" "*.cpp")

SOURCE_GROUP("Header Files" FILES ${Base_hdrs} ${Base_incl})
SOURCE_GROUP("Source Files" FILES ${Base_srcs})

ADD_LIBRARY(google-url-base STATIC ${Base_hdrs} ${Base_srcs} ${Base_incl})

INSTALL(TARGETS google-url-base
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

INSTALL(FILES ${Base_incl} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/googleurl/base)
