file(WRITE "${TEST_DIR}/input1.txt" "5 3 8 1 2 255 0 10")

execute_process(
        COMMAND "${EXECUTABLE}" "${TEST_DIR}/input1.txt"
        WORKING_DIRECTORY "${TEST_DIR}"
        RESULT_VARIABLE result
)

if(NOT result EQUAL 0)
    message(FATAL_ERROR "Program se ni uspešno izvedel pri testu 1.")
endif()

file(READ "${TEST_DIR}/out.txt" output)
string(STRIP "${output}" output)

if(NOT output STREQUAL "0 1 2 3 5 8 10 999")
    message(FATAL_ERROR "Test 1 ni uspel. Dobljeno: ${output}")
endif()


file(WRITE "${TEST_DIR}/input2.txt" "1 2 3 4 5")

execute_process(
        COMMAND "${EXECUTABLE}" "${TEST_DIR}/input2.txt"
        WORKING_DIRECTORY "${TEST_DIR}"
        RESULT_VARIABLE result
)

if(NOT result EQUAL 0)
    message(FATAL_ERROR "Program se ni uspešno izvedel pri testu 2.")
endif()

file(READ "${TEST_DIR}/out.txt" output)
string(STRIP "${output}" output)

if(NOT output STREQUAL "1 2 3 4 5")
    message(FATAL_ERROR "Test 2 ni uspel. Dobljeno: ${output}")
endif()


file(WRITE "${TEST_DIR}/input3.txt" "9 1 9 3 1 0")

execute_process(
        COMMAND "${EXECUTABLE}" "${TEST_DIR}/input3.txt"
        WORKING_DIRECTORY "${TEST_DIR}"
        RESULT_VARIABLE result
)

if(NOT result EQUAL 0)
    message(FATAL_ERROR "Program se ni uspešno izvedel pri testu 3.")
endif()

file(READ "${TEST_DIR}/out.txt" output)
string(STRIP "${output}" output)

if(NOT output STREQUAL "0 1 1 3 9 9")
    message(FATAL_ERROR "Test 3 ni uspel. Dobljeno: ${output}")
endif()

file(WRITE "${TEST_DIR}/input4.txt" "1 2 300")

execute_process(
        COMMAND "${EXECUTABLE}" "${TEST_DIR}/input4.txt"
        WORKING_DIRECTORY "${TEST_DIR}"
        RESULT_VARIABLE result
)

if(result EQUAL 0)
    message(FATAL_ERROR "Test 4 ni uspel. Program bi moral vrniti napako za število 300.")
endif()

message("Vsi testi so uspešno prestali preverjanje.")