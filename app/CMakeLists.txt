# Especificar el archivo fuente principal
set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")  # Cambio de .cc a .cpp

# Crear el ejecutable a partir de las fuentes
add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})

# Vincular con la biblioteca "LibFunciones" y otras dependencias externas
target_link_libraries(
    ${EXECUTABLE_NAME}
    PRIVATE "LibFunciones"
            nlohmann_json::nlohmann_json
            fmt::fmt
            spdlog::spdlog
            cxxopts::cxxopts)

# Configurar advertencias (si están habilitadas)
if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET ${EXECUTABLE_NAME}
        ENABLE ${ENABLE_WARNINGS}
        AS_ERRORS ${ENABLE_WARNINGS_AS_ERRORS})
endif()

# Si se habilita LTO (Link Time Optimization), activarlo
if(${ENABLE_LTO})
    target_enable_lto(
        TARGET ${EXECUTABLE_NAME}
        ENABLE ON)
endif()

# Si se habilita Clang-Tidy, agregarlo al ejecutable
if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${EXECUTABLE_NAME})
endif()
