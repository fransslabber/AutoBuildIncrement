// AutoBuildIncrement.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*
  Usage:- autobuildincrement filename idstring1 idstring2 ...
  */
  if( argc > 2 ) // we have something to do
  {
    string buffer;
    int tmp = 0;
    fstream::streampos readingpos = std::ios::beg;
    fstream target( argv[1] );
    if( target.is_open() )
    {
      while( target >> buffer )
      {
        // check for each substring given in commandline
        for( int i = 2; i < argc; i++ )
        {
          if( buffer == string(argv[i]) )
          {
            readingpos = target.tellg();
            if( target >> buffer )
            {
              target.seekp( readingpos );
              sscanf( buffer.c_str(), "%d", &tmp );
              target << " " << ++tmp;
              target.flush();
            }
            break;
          }
        }
      }
      target.close();
    }
  }
  else
  {
    cout << "Usage:- autobuildincrement.exe filename idstring1 idstring2 ..." << endl;
  }
}

