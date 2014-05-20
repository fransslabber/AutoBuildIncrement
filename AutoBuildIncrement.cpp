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

	//if( argc == 4 )
 // {
 //   major = _wtol( argv[1] );
 //   minor = _wtol( argv[2] );
 //   build_number = _wtol( argv[3] );
 // }

 // // now write it again....
 // std::wofstream out( L"moduleinfo.h", std::ios::trunc );
 // time_t currenttime;
 // time( &currenttime );
 // if( out.is_open() )
 // {

 //   out << L"#define BUILD_NUMBER              " << currenttime - _2013_01_01 << L"\n#define BUILD_USERNAME_STR        \"Frans Slabber\"\n";
 //   out << L"#define BUILD_USERDOMAIN_STR      \"knowledgetree.com\"\n#define MODULE_MAJOR_VERSION			  " << major << L"\n#define MODULE_MICRO_VERSION			  " << micro << L"\n";
 //   out << L"#define MODULE_MINOR_VERSION			  " << minor << L"\n#define MODULE_REVISION_VERSION			" << build_number << L"\n";
 //   out << L"#define MODULE_PRODUCT_NAME_STR			\"KT Gateway\"\n#define MODULE_FILE_DESCRIPTION_STR		\"KT Virtual Drive Manager\"\n";
 //   out << L"#define MODULE_INTERNAL_NAME_STR		\"ktvdm_g\"\n#define MODULE_ORIGINAL_FILENAME_STR	\"ktvdmgateway.exe\"\n";
 //   out << L"#define MODULE_COMPANY_NAME_STR			\"KnowledgeTree Inc.\"\n#define MODULE_COPYRIGHT_YEAR_STR		\"2012\"\n";

 //   out.close();
 // }

	//if( argc >= 3 )
 // {
 //   // Build a XML version file for WiX installer
 //   std::wofstream executable_file_name( std::wstring( argv[1] ) + L"\\component_build_name.xml" , std::ios::trunc );
 //   if( executable_file_name.is_open() )
 //   {
 //     executable_file_name << L"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<Include Id=\"VersionNumberInclude\">\n\t<?define ComponentName=\"KTSync_"<< argv[2] << L"\" ?>\n\t<?define MajorVersion=\"" << major << L"\" ?>\n\t<?define MinorVersion=\"" << minor << L"\" ?>\n\t<?define MicroVersion=\"" << micro << L"\" ?>\n\t<?define BuildNumberVersion=\"" << build_number << L"\" ?>\n\t<?define TimeStampVersion=\"" << currenttime - _2013_01_01 << L"\" ?>\n</Include>";
 //     executable_file_name.close();
 //   }  
 //     
 //   std::wofstream package_executable_file_name( std::wstring( argv[1] ) + L"\\package_build_name.txt" , std::ios::trunc );
 //   if( package_executable_file_name.is_open() )
 //   {
 //     package_executable_file_name << L"KTSync_Win7_x32x64_BETA_DBG_" << major << L"." << minor << L"." << micro << L"." << build_number << L"_" << currenttime - _2013_01_01;
 //     package_executable_file_name.close();
 //   }  
 // }
}

