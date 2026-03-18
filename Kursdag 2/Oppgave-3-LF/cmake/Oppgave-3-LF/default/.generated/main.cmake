include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Oppgave_3_LF_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Oppgave_3_LF_default_default_XC8_FILE_TYPE_assemble)
add_library(Oppgave_3_LF_default_default_XC8_assemble OBJECT ${Oppgave_3_LF_default_default_XC8_FILE_TYPE_assemble})
    Oppgave_3_LF_default_default_XC8_assemble_rule(Oppgave_3_LF_default_default_XC8_assemble)
    list(APPEND Oppgave_3_LF_default_library_list "$<TARGET_OBJECTS:Oppgave_3_LF_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(Oppgave_3_LF_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Oppgave_3_LF_default_default_XC8_assemblePreprocess OBJECT ${Oppgave_3_LF_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Oppgave_3_LF_default_default_XC8_assemblePreprocess_rule(Oppgave_3_LF_default_default_XC8_assemblePreprocess)
    list(APPEND Oppgave_3_LF_default_library_list "$<TARGET_OBJECTS:Oppgave_3_LF_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(Oppgave_3_LF_default_default_XC8_FILE_TYPE_compile)
add_library(Oppgave_3_LF_default_default_XC8_compile OBJECT ${Oppgave_3_LF_default_default_XC8_FILE_TYPE_compile})
    Oppgave_3_LF_default_default_XC8_compile_rule(Oppgave_3_LF_default_default_XC8_compile)
    list(APPEND Oppgave_3_LF_default_library_list "$<TARGET_OBJECTS:Oppgave_3_LF_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(Oppgave_3_LF_default_image_q9956A3A ${Oppgave_3_LF_default_library_list})

set_target_properties(Oppgave_3_LF_default_image_q9956A3A PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Oppgave_3_LF_default_output_dir}")
target_link_libraries(Oppgave_3_LF_default_image_q9956A3A PRIVATE ${Oppgave_3_LF_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
Oppgave_3_LF_default_link_rule( Oppgave_3_LF_default_image_q9956A3A)


