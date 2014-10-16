//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-16
//! @last-modified 	2014-10-17
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

	MTEST(AddOneNodeTest)
	{
		List<double> list;

		double myDouble = 5.5;
		list.Insert(list.Start(), myDouble);

		List<double>::Iterator it;

		for(it = list.Start(); it != list.End(); it++)
		{
			//std::cout << "*it = " << *it << std::endl;
			// Check capacity is calculated correctly
			CHECK_EQUAL(*it, 5.5);
		}

	}

	MTEST(AddTwoNodesTest)
	{
		List<double> list;

		double myDoubleA[2];
		myDoubleA[0] = 5.5;
		myDoubleA[0] = -3.4;

		List<double>::Iterator it;
		it = list.Start();
		list.Insert(it, myDoubleA[0]);
		list.Insert(it, myDoubleA[1]);
		//it++;;
		//list.Insert(it++, myDouble2);

		uint32_t count = 0;
		for(it = list.Start(); it != list.End(); it++)
		{
			std::cout << "*it = " << *it << std::endl;
			// Check capacity is calculated correctly
			CHECK_EQUAL(*it, myDoubleA[count]);

			count++;
		}

	}


} // namespace MListTestsNs
