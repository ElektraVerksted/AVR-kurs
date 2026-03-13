include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Oppgave_1_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Oppgave_1_default_default_XC8_FILE_TYPE_assemble)
add_library(Oppgave_1_default_default_XC8_assemble OBJECT ${Oppgave_1_default_default_XC8_FILE_TYPE_assemble})
    Oppgave_1_default_default_XC8_assemble_rule(Oppgave_1_default_default_XC8_assemble)
    list(APPEND Oppgave_1_default_library_list "$<TARGET_OBJECTS:Oppgave_1_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(Oppgave_1_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Oppgave_1_default_default_XC8_assemblePreprocess OBJECT ${Oppgave_1_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Oppgave_1_default_default_XC8_assemblePreprocess_rule(Oppgave_1_default_default_XC8_assemblePreprocess)
    list(APPEND Oppgave_1_default_library_list "$<TARGET_OBJECTS:Oppgave_1_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(Oppgave_1_default_default_XC8_FILE_TYPE_compile)
add_library(Oppgave_1_default_default_XC8_compile OBJECT ${Oppgave_1_default_default_XC8_FILE_TYPE_compile})
    Oppgave_1_default_default_XC8_compile_rule(Oppgave_1_default_default_XC8_compile)
    list(APPEND Oppgave_1_default_library_list "$<TARGET_OBJECTS:Oppgave_1_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(Oppgave_1_default_image_UmumOocP ${Oppgave_1_default_library_list})

set_target_properties(Oppgave_1_default_image_UmumOocP PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Oppgave_1_default_output_dir}")
target_link_libraries(Oppgave_1_default_image_UmumOocP PRIVATE ${Oppgave_1_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
Oppgave_1_default_link_rule( Oppgave_1_default_image_UmumOocP)


