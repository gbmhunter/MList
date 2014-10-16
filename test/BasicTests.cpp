//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-16
//! @last-modified 	2014-10-16
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MListApi.hpp"

using namespace MbeddedNinja;

namespace MListTestsNs
{

	MTEST(BasicCapacityTest)
	{
		List<double> list;

		double myDouble = 5.5;
		list.Insert(myDouble, 0);

		List<double>::Iterator it;

		for(it = list.Start(); it <= list.End(); it++)
		{
			std::cout << "*it = " << *it << std::endl;
		}

		// Check capacity is calculated correctly
		//CHECK_EQUAL(myString, "Testing");
	}


} // namespace MListTestsNs
