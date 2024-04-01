aux_source_directory(. SRC_LIST)
# set(SRC_LIST 
#     mprpcapplication.cc 
#     rpcprovider.cc 
# )
add_library(mprpc SHARED ${SRC_LIST})
target_link_libraries(mprpc)