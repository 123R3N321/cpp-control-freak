# Add source files for each component
add_library(calculator
    calculator.cpp
)

add_library(logger
    logger.cpp
)

add_library(notifier
    notifier.cpp
)

target_include_directories(logger
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_include_directories(notifier
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_include_directories(calculator
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(calculator
    logger
    notifier
)

# bundle the components together into an interface for convenience
add_library(calculator_lib INTERFACE)
target_link_libraries(calculator_lib INTERFACE calculator logger notifier)

