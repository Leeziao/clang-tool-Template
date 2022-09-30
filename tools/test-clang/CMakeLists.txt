project(test-clang)

add_executable(test-clang test-clang.cpp)

# Add Clang Library

unset(REQ_CLANG_LIBRARIES CACHE)
list(APPEND REQ_CLANG_LIBRARIES clangAST)
list(APPEND REQ_CLANG_LIBRARIES clangBasic)
list(APPEND REQ_CLANG_LIBRARIES clangCodeGen)
list(APPEND REQ_CLANG_LIBRARIES clangLex)
list(APPEND REQ_CLANG_LIBRARIES clangParse)
list(APPEND REQ_CLANG_LIBRARIES clangSema)
list(APPEND REQ_CLANG_LIBRARIES clangAnalysis)
list(APPEND REQ_CLANG_LIBRARIES clangDriver)
list(APPEND REQ_CLANG_LIBRARIES clangFrontend)
list(APPEND REQ_CLANG_LIBRARIES clangEdit)
list(APPEND REQ_CLANG_LIBRARIES clangSerialization)
list(APPEND REQ_CLANG_LIBRARIES clangTooling)
list(APPEND REQ_CLANG_LIBRARIES clangToolingCore)

foreach(_req_clang_library ${REQ_CLANG_LIBRARIES})
	get_target_property(_req_library_dep ${_req_clang_library} INTERFACE_LINK_LIBRARIES)
	message(STATUS "${_req_clang_library} depends on ${_req_library_dep}")
	target_link_libraries(test-clang ${_req_library_dep} ${_req_clang_library})
endforeach()

target_link_libraries(test-clang testlib)

