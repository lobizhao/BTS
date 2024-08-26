cmake_minimum_required(VERSION 3.28)
project(BST)

set(CMAKE_CXX_STANDARD 23)

add_executable(BST main.cpp
        binaryTree.hpp
        binaryTree.cpp
        BSTIterator.cpp
        BSTIterator.hpp
)
