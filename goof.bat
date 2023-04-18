@rem *This file is use to compile c/c++ programs with MingGW*
@rem *You have to add this to path to execute it everywhere*
@rem *This needs a single argument*

@echo off
if (%1 == EXISTS) (
  g++ %1
  a.exe
) else (
  color 4
  echo Can't find file: %1
)
