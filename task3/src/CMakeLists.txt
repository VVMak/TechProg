add_library(buffer SHARED buffer.cpp)

#install(TARGETS buffer
#	LIBRARY DESTINATION .
#)

install(FILES ../include/buffer.h
	DESTINATION ./include
)
