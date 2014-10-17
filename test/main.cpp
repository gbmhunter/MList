//!
//! @file 			main.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-16
//! @last-modified 	2014-10-17
//! @brief 			Contains main entry point for unit tests.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
// none

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "MList/api/MListApi.hpp"

using namespace MbeddedNinja;

int main()
{
	List<double>::StaticInit(&std::cout, false);

	// Run all unit tests and return the result
	return TestRegister::RunAllTests();
	
}
