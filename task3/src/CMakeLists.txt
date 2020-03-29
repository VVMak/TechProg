add_library(buffer SHARED buffer.cpp)
target_include_directories(buffer PRIVATE ../include)

install(TARGETS buffer
	LIBRARY DESTINATION .
)

