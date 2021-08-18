add_definitions(-DTAGLIB_STATIC)

add_library(soundlib2 SHARED
        ${CMAKE_CURRENT_LIST_DIR}/extension.cpp
        ${CMAKE_CURRENT_LIST_DIR}/natives.cpp
        ${CMAKE_CURRENT_LIST_DIR}/soundfile.cpp
        ${CMAKE_CURRENT_LIST_DIR}/systemfilestream.cpp
        ${CMAKE_CURRENT_LIST_DIR}/valvefilestream.cpp
        )

target_include_directories(soundlib2 PUBLIC
        ./
        )

target_link_libraries(soundlib2 PUBLIC smsdk_ext)
target_link_libraries(soundlib2 PUBLIC taglib)

set_target_properties(soundlib2 PROPERTIES PREFIX "" SUFFIX ".ext.2.csgo${HL2SDK_LIB_SHARED_EXT}")