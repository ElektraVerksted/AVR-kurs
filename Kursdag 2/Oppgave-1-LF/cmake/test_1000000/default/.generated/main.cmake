include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(test_1000000_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(test_1000000_default_default_XC8_FILE_TYPE_assemble)
add_library(test_1000000_default_default_XC8_assemble OBJECT ${test_1000000_default_default_XC8_FILE_TYPE_assemble})
    test_1000000_default_default_XC8_assemble_rule(test_1000000_default_default_XC8_assemble)
    list(APPEND test_1000000_default_library_list "$<TARGET_OBJECTS:test_1000000_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(test_1000000_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(test_1000000_default_default_XC8_assemblePreprocess OBJECT ${test_1000000_default_default_XC8_FILE_TYPE_assemblePreprocess})
    test_1000000_default_default_XC8_assemblePreprocess_rule(test_1000000_default_default_XC8_assemblePreprocess)
    list(APPEND test_1000000_default_library_list "$<TARGET_OBJECTS:test_1000000_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(test_1000000_default_default_XC8_FILE_TYPE_compile)
add_library(test_1000000_default_default_XC8_compile OBJECT ${test_1000000_default_default_XC8_FILE_TYPE_compile})
    test_1000000_default_default_XC8_compile_rule(test_1000000_default_default_XC8_compile)
    list(APPEND test_1000000_default_library_list "$<TARGET_OBJECTS:test_1000000_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(test_1000000_default_image_iE5CF_UI ${test_1000000_default_library_list})

set_target_properties(test_1000000_default_image_iE5CF_UI PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${test_1000000_default_output_dir}")
target_link_libraries(test_1000000_default_image_iE5CF_UI PRIVATE ${test_1000000_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
test_1000000_default_link_rule( test_1000000_default_image_iE5CF_UI)


