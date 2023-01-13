# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/graph/assimpBuild/test/gtest/src/gtest"
  "D:/graph/assimpBuild/test/gtest/src/gtest-build"
  "D:/graph/assimpBuild/test/gtest"
  "D:/graph/assimpBuild/test/gtest/tmp"
  "D:/graph/assimpBuild/test/gtest/src/gtest-stamp"
  "D:/graph/assimpBuild/test/gtest/src"
  "D:/graph/assimpBuild/test/gtest/src/gtest-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/graph/assimpBuild/test/gtest/src/gtest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/graph/assimpBuild/test/gtest/src/gtest-stamp${cfgdir}") # cfgdir has leading slash
endif()
