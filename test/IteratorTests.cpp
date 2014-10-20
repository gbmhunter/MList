//!
//! @file 			IteratorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-20
//! @last-modified 	2014-10-20
//! @brief 			Contains tests which make sure the List iterator object works as expected.
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


	MTEST(IterateBackwardsTest)
	{
		List<double> list;

		const uint32_t sizeOfArray = 10;

		double myDoubleA[sizeOfArray];
		myDoubleA[0] = 5.5;
		myDoubleA[1] = -3.4;
		myDoubleA[2] = 2.2;
		myDoubleA[3] = 1.1;
		myDoubleA[4] = 100.2;
		myDoubleA[5] = -34.2;
		myDoubleA[6] = 21.2;
		myDoubleA[7] = 0.6;
		myDoubleA[8] = -0.6;
		myDoubleA[9] = 1.345;

		List<double>::Iterator it;
		it = list.Start();

		for(uint32_t x = 0; x < sizeOfArray; x++)
		{
			list.Insert(it, myDoubleA[x]);
		}

		uint32_t count = sizeOfArray - 1;
		for(it = list.End() - 1; it != list.Start(); it--)
		{
			//std::cout << "*it = " << *it << std::endl;
			// Check capacity is calculated correctly
			CHECK_EQUAL(*it, myDoubleA[count]);

			count--;
		}

	}

	MTEST(Jump3ForwardTest)
	{
		List<double> list;

		const uint32_t sizeOfArray = 10;

		double myDoubleA[sizeOfArray];
		myDoubleA[0] = 5.5;
		myDoubleA[1] = -3.4;
		myDoubleA[2] = 2.2;
		myDoubleA[3] = 1.1;
		myDoubleA[4] = 100.2;
		myDoubleA[5] = -34.2;
		myDoubleA[6] = 21.2;
		myDoubleA[7] = 0.6;
		myDoubleA[8] = -0.6;
		myDoubleA[9] = 1.345;

		List<double>::Iterator it;
		it = list.Start();

		for(uint32_t x = 0; x < sizeOfArray; x++)
		{
			list.Insert(it, myDoubleA[x]);
		}

		it = list.Start();
		it += 3;
		// Iterator should now be pointing at the 4th node in the list
		CHECK_EQUAL(*it, myDoubleA[3]);

	}

	MTEST(Jump4BackwardTest)
	{
		List<double> list;

		const uint32_t sizeOfArray = 10;

		double myDoubleA[sizeOfArray];
		myDoubleA[0] = 5.5;
		myDoubleA[1] = -3.4;
		myDoubleA[2] = 2.2;
		myDoubleA[3] = 1.1;
		myDoubleA[4] = 100.2;
		myDoubleA[5] = -34.2;
		myDoubleA[6] = 21.2;
		myDoubleA[7] = 0.6;
		myDoubleA[8] = -0.6;
		myDoubleA[9] = 1.345;

		List<double>::Iterator it;
		it = list.Start();

		for(uint32_t x = 0; x < sizeOfArray; x++)
		{
			list.Insert(it, myDoubleA[x]);
		}

		it = list.End();
		it -= 4;
		// Iterator should now be pointing at the 7th node in the list
		// (remember that list.End() returns an iterator at the end+1 position)
		CHECK_EQUAL(*it, myDoubleA[6]);

	}

} // namespace MListTestsNs
