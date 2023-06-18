cmake_minimum_required(VERSION 3.5)
project(DIPrimitives VERSION 0.1 DESCRIPTION "Primitives module" LANGUAGES CXX)


file( GLOB SOURCES **.cpp )

SetFlags()
SetLibraries( DIRenderer )
CreateLibrary( ${PROJECT_NAME} )