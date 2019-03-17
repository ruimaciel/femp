# initialize the search
unset(SuiteSparse_FOUND CACHE)
unset(SuiteSparse_INCLUDE_PATH CACHE)
unset(SuiteSparse_LIBRARY CACHE)

find_path(SuiteSparse_INCLUDE_PATH
    PATH_SUFFIXES suitesparse
    NAMES umfpack.h
    )

find_library(SuiteSparse_LIBRARY
    NAMES umfpack
    )

if(SuiteSparse_INCLUDE_PATH AND SuiteSparse_LIBRARY)
    set(SuiteSparse_FOUND true CACHE bool "foo")
    if(NOT SuiteSparse_FIND_QUIETLY)
        message("SuiteSparse found.")
    endif()
else()
    set(SuiteSparse_FOUND false CACHE bool "foo")
    unset(SuiteSparse_INCLUDE_PATH CACHE)
    unset(SuiteSparse_LIBRARY CACHE)
    message(FATAL_ERROR "SuiteSparse not found.")
    return()
endif()

add_library(umfpack INTERFACE )

target_link_libraries(umfpack
    INTERFACE ${SuiteSparse_LIBRARY}
    )

target_include_directories(umfpack
    INTERFACE ${SuiteSparse_INCLUDE_PATH}
    )
