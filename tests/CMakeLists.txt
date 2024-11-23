# Asegúrate de que Catch2 esté disponible. Si Catch2 está siendo gestionado por CPM, Conan o VCPKG, ya está disponible.
# Si Catch2 está siendo descargado o está en un submódulo, necesitas incluir su ruta.

# Agregar el archivo de prueba
add_executable(tests test_funciones.cpp)

# Si Catch2 está en el directorio 'external' o fue gestionado por algún gestor de paquetes como CPM, Conan o VCPKG,
# Asegúrate de vincular Catch2 a tu ejecutable de pruebas
target_link_libraries(tests Catch2::Catch2)

# Habilitar el soporte para pruebas en CMake
include(CTest)
enable_testing()

# Registrar las pruebas con CTest
add_test(NAME tests COMMAND tests)
