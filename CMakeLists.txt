cmake_minimum_required(VERSION 3.15)
project(PetLife)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set paths
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML-2.6.1")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIB_DIR "${SFML_ROOT}/lib")

# Create executable
add_executable(${PROJECT_NAME}
    main.cpp
    Bar.cpp
    BathMinigame.cpp
    Button.cpp
    Currency.cpp
    Debuff.cpp
    DifficultyUi.cpp
    EatingMinigame.cpp
    Game.cpp
    GameOver.cpp
    Map.cpp
    Player.cpp
    PlayingMinigame.cpp
    Shop.cpp
    SleepingFunctionality.cpp
    TitleScreen.cpp
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${SFML_INCLUDE_DIR}
)

# --------------------------------------------------------
# SFML Linking Logic (FORCED MANUAL)
# --------------------------------------------------------

message(STATUS "Forcing manual configuration from ${SFML_ROOT}")

# 1. Tell CMake where the .lib files are
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_LIB_DIR})

if(MSVC)
    # 2. Link SFML Libraries (Debug vs Release)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        debug sfml-graphics-d
        debug sfml-window-d
        debug sfml-system-d
        optimized sfml-graphics
        optimized sfml-window
        optimized sfml-system
    )

    # 3. Link Windows System Libraries (Required by SFML)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        opengl32
        winmm
        gdi32
        freetype
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg
        openal32
        ws2_32
    )
endif()

# --------------------------------------------------------
# Post-Build Commands (Asset & DLL Copying)
# --------------------------------------------------------

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    # 1. Copy Assets folder
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/Assets"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/Assets"
    
    # 2. Copy ReadMe folder
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/PetLifeReadMe"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/PetLifeReadMe"
)

# 3. Copy SFML DLLs
# We use copy_directory instead of copy *.dll because cmake -E does not support wildcards.
# This will copy all DLLs (Debug and Release) to the output folder.
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${SFML_ROOT}/bin"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    )
endif()

# MSVC specific settings
if(MSVC)
    # Runtime library settings - IMPORTANT: Must match how SFML was built
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:/MDd>  # Debug DLL runtime
        $<$<CONFIG:Release>:/MD> # Release DLL runtime
    )
    
    # Disable specific warnings if needed
    target_compile_options(${PROJECT_NAME} PRIVATE /W3)
endif()