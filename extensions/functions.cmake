include_guard()

function(create_extension name sources)
    add_executable(${name})
    target_sources(${name} PRIVATE ${sources})
    target_link_libraries(${name}
        PRIVATE MINI_RPG)
endfunction()
