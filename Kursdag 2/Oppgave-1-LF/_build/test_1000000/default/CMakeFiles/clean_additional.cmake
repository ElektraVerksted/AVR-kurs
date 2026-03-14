# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\Users\\husev\\AVR-kurs\\Kursdag 2\\Oppgave-1-LF\\out\\test_1000000\\default.cmf"
  "C:\\Users\\husev\\AVR-kurs\\Kursdag 2\\Oppgave-1-LF\\out\\test_1000000\\default.hex"
  "C:\\Users\\husev\\AVR-kurs\\Kursdag 2\\Oppgave-1-LF\\out\\test_1000000\\default.hxl"
  "C:\\Users\\husev\\AVR-kurs\\Kursdag 2\\Oppgave-1-LF\\out\\test_1000000\\default.mum"
  "C:\\Users\\husev\\AVR-kurs\\Kursdag 2\\Oppgave-1-LF\\out\\test_1000000\\default.o"
  "C:\\Users\\husev\\AVR-kurs\\Kursdag 2\\Oppgave-1-LF\\out\\test_1000000\\default.sdb"
  "C:\\Users\\husev\\AVR-kurs\\Kursdag 2\\Oppgave-1-LF\\out\\test_1000000\\default.sym"
  )
endif()
