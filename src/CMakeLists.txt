set(target MINI_RPG)

set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/..)

# include
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

# source
set(header_dir ${root_dir}/include)

set(headers
    ${header_dir}/game/character/character.hpp
    ${header_dir}/game/character/elf.hpp
    ${header_dir}/game/character/human.hpp
    ${header_dir}/game/character/orc.hpp
    ${header_dir}/game/item/item.hpp
    ${header_dir}/game/shop/shop.hpp
    )

set(sources
    game/character/character.cpp
    game/character/elf.cpp
    game/character/human.cpp
    game/character/orc.cpp
    game/item/item.cpp
    game/shop/shop.cpp
)

# build library
add_library(${target}
            ${headers} ${sources})

set_target_properties(${target} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES)

# resource dir
target_compile_definitions(${target}
    PRIVATE
    RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/../resouce/")

# library link options
find_package(fmt)
target_link_libraries(${target} fmt::fmt)

#install
install(TARGETS ${target} 
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include)


