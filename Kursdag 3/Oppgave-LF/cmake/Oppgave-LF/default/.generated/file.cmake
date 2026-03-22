# The following variables contains the files used by the different stages of the build process.
set(Oppgave_LF_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${Oppgave_LF_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${Oppgave_LF_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(Oppgave_LF_default_default_XC8_FILE_TYPE_assemblePreprocess "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/protected_io.S")
set_source_files_properties(${Oppgave_LF_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${Oppgave_LF_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(Oppgave_LF_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/i2c_host/src/twi0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/clock.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/config_bits.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/interrupt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/pins.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/system.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/uart/src/usart3.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcp9808.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/src/drivere/mcp9808.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/src/drivere/oled/ssd1306.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/ssd1306.c")
set_source_files_properties(${Oppgave_LF_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(Oppgave_LF_default_default_XC8_FILE_TYPE_link)
set(Oppgave_LF_default_image_name "default.elf")
set(Oppgave_LF_default_image_base_name "default")

# The output directory of the final image.
set(Oppgave_LF_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/Oppgave-LF")

# The full path to the final image.
set(Oppgave_LF_default_full_path_to_image ${Oppgave_LF_default_output_dir}/${Oppgave_LF_default_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .hxl
    .mum
    .o
    .sdb
    .sym
    .cmf)
list(TRANSFORM output_extensions PREPEND "${Oppgave_LF_default_output_dir}/${Oppgave_LF_default_image_base_name}")
