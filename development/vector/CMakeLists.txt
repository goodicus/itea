cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "3" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(Vector VERSION ${PROJECT_VESRION})

# # # _ _ _ _ _ _ _ _ P R O J E C T _ L I B _ _ _ _ _ _ _ # # #
set(PROJECT_LIB_NAME ${PROJECT_NAME}_lib)

add_library(${PROJECT_LIB_NAME}
    inc/vector.h
    src/vector.cpp
)

target_include_directories(${PROJECT_LIB_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

# # # _ _ _ _ _ _ _ _ _ _ _ T E S T S _ _ _ _ _ _ _ _ _ _ _ # # #
 if(WITH_GOOGLE_TEST)
    set(PROJECT_TESTS_NAME ${PROJECT_NAME}_tests)
    add_executable(${PROJECT_TESTS_NAME}
        tests/main.cpp
        tests/vector_tests.cpp
    )

    set_target_properties(${PROJECT_TESTS_NAME}
        PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
    )

    target_include_directories(${PROJECT_TESTS_NAME}
        PRIVATE
            ${gtest_SOURCE_DIR}/include
    )

    target_link_libraries(${PROJECT_TESTS_NAME}
        PRIVATE
            GTest::gtest
            GTest::gtest_main
            ${PROJECT_LIB_NAME}
    )
endif()

if (MSVC)
    target_compile_options(${PROJECT_LIB_NAME}
        PRIVATE
            /W4
    )

    # target_compile_options(${PROJECT_NAME}
    #     PRIVATE
    #         /W4
    # )

    if(WITH_GOOGLE_TEST)
        target_compile_options(${PROJECT_TESTS_NAME}
            PRIVATE
                /W4
        )
    endif()
else ()
    target_compile_options(${PROJECT_LIB_NAME}
        PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

    if(WITH_GOOGLE_TEST)
        target_compile_options(${PROJECT_TESTS_NAME}
            PRIVATE
                -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

# if(WITH_GOOGLE_TEST)
#     add_test(${PROJECT_TESTS_NAME} ${PROJECT_TESTS_NAME})
# endif()
