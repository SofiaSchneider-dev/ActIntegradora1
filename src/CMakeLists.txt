# Definir las fuentes de la biblioteca (solo fuentes, no encabezados)
set(LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/funciones.cpp")

# Definir los encabezados
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/funciones.h")

# Definir directorios de inclusión
set(LIBRARY_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}")

# Crear la biblioteca estática "LibFunciones"
add_library("LibFunciones" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

# Incluir directorios de encabezados
target_include_directories("LibFunciones" PUBLIC ${LIBRARY_INCLUDES})

# Vincular con bibliotecas externas (nlohmann_json, fmt, spdlog, cxxopts)
target_link_libraries(
    "LibFunciones"
    PRIVATE nlohmann_json::nlohmann_json
            fmt::fmt
            spdlog::spdlog
            cxxopts::cxxopts)

# Si se habilitan las advertencias, agregarlas
if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET "LibFunciones"
        ENABLE ${ENABLE_WARNINGS}
        AS_ERRORS ${ENABLE_WARNINGS_AS_ERRORS})
endif()

# Si se habilita LTO (Link Time Optimization), activarlo
if(${ENABLE_LTO})
    target_enable_lto(
        TARGET "LibFunciones"
        ENABLE ON
    )
endif()

# Si se habilita Clang-Tidy, agregarlo a la biblioteca
if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("LibFunciones")
endif()
