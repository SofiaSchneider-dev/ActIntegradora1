# Incluir Catch2, que se ha configurado previamente en el CMake principal
include(Catch)

# Crear un ejecutable para las pruebas unitarias
add_executable("UnitTestFunciones" "test_funciones.cpp")

# Vincular las bibliotecas necesarias (como "LibFunciones" y "Catch2")
target_link_libraries("UnitTestFunciones" PUBLIC "LibFunciones")
target_link_libraries("UnitTestFunciones" PRIVATE Catch2::Catch2WithMain)

# Configurar advertencias si ENABLE_WARNINGS está habilitado
if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET "UnitTestFunciones"
        ENABLE ${ENABLE_WARNINGS}
        AS_ERRORS ${ENABLE_WARNINGS_AS_ERRORS})
endif()

# Descubrir y ejecutar las pruebas definidas en test_funciones.cpp
catch_discover_tests("UnitTestFunciones")

# Si se habilita la cobertura de código, configurar el análisis de cobertura
if(ENABLE_COVERAGE)
    set(COVERAGE_MAIN "coverage")
    set(COVERAGE_EXCLUDES
        "${PROJECT_SOURCE_DIR}/app/*"
        "${PROJECT_SOURCE_DIR}/cmake/*"
        "${PROJECT_SOURCE_DIR}/docs/*"
        "${PROJECT_SOURCE_DIR}/external/*"
        "${PROJECT_SOURCE_DIR}/tests/*"
        "${PROJECT_SOURCE_DIR}/build/*"
        "/usr/include/*")
    set(COVERAGE_EXTRA_FLAGS)
    set(COVERAGE_DEPENDENCIES "UnitTestFunciones")

    # Si se utiliza gcovr para la cobertura, configurarlo
    setup_target_for_coverage_gcovr_html(
        NAME
        ${COVERAGE_MAIN}
        EXECUTABLE
        ctest
        DEPENDENCIES
        ${COVERAGE_DEPENDENCIES}
        BASE_DIRECTORY
        ${CMAKE_SOURCE_DIR})
endif()
