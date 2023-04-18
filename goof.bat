@rem *This file is use to compile c/c++ programs with MingGW*
@rem *You have to add this to path to execute it everywhere*
@rem *This needs a single argument*
@rem *This is not Exception save*

@echo off
  g++ %1
  a.exe

@rem *Could produce Error if .exe File is not called "a.exe"*
