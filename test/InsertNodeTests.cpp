//!
//! @file 			InsertNodeTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-16
//! @last-modified 	2014-10-19
//! @brief 			Contains tests which make sure nodes can be inserted into lists correctly.
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

	MTEST(InsertOneNodeTest)
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

	MTEST(InsertTwoNodesTest)
	{
		List<double> list;

		double myDoubleA[2];
		myDoubleA[0] = 5.5;
		myDoubleA[1] = -3.4;

		List<double>::Iterator it;
		it = list.Start();
		list.Insert(it, myDoubleA[0]);
		list.Insert(it, myDoubleA[1]);
		//it++;;
		//list.Insert(it++, myDouble2);

		uint32_t count = 0;
		for(it = list.Start(); it != list.End(); it++)
		{
			//std::cout << "*it = " << *it << std::endl;
			// Check capacity is calculated correctly
			CHECK_EQUAL(*it, myDoubleA[count]);

			count++;
		}

	}

	MTEST(InsertManyNodesTest)
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

		uint32_t count = 0;
		for(it = list.Start(); it != list.End(); it++)
		{
			//std::cout << "*it = " << *it << std::endl;
			// Check capacity is calculated correctly
			CHECK_EQUAL(*it, myDoubleA[count]);

			count++;
		}

	}

	MTEST(InsertIntoMiddleTest)
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

		uint32_t count = 0;
		for(it = list.Start(); it != list.End(); it++)
		{
			//std::cout << "*it = " << *it << std::endl;
			// Check capacity is calculated correctly
			CHECK_EQUAL(*it, myDoubleA[count]);

			count++;
		}

		// Now lets insert one into the middle
		//List<double>::isDebugPrintingEnabled = true;

		it = list.Start();
		it++;
		it++;

		double insertedDouble = 0.12;

		// Insert double into the third position
		list.Insert(it, insertedDouble);

		count = 0;
		for(it = list.Start(); it != list.End(); it++)
		{
			//std::cout << "*it = " << *it << std::endl;

			if(count < 2)
			{
				CHECK_EQUAL(*it, myDoubleA[count]);
			}
			else if(count == 2)
			{
				CHECK_EQUAL(*it, insertedDouble);
			}
			else
			{
				CHECK_EQUAL(*it, myDoubleA[count-1]);
			}

			count++;
		}

	}

	MTEST(InsertAtStartTest)
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

		uint32_t count = 0;
		for(it = list.Start(); it != list.End(); it++)
		{
			//std::cout << "*it = " << *it << std::endl;
			// Check capacity is calculated correctly
			CHECK_EQUAL(*it, myDoubleA[count]);

			count++;
		}

		// Now lets insert one more at the start
		//List<double>::isDebugPrintingEnabled = true;

		it = list.Start();

		double insertedDouble = 0.12;

		// Insert double into the third position
		list.Insert(it, insertedDouble);

		count = 0;
		for(it = list.Start(); it != list.End(); it++)
		{
			//std::cout << "*it = " << *it << std::endl;

			if(count < 0)
			{
				CHECK_EQUAL(*it, myDoubleA[count]);
			}
			else if(count == 0)
			{
				CHECK_EQUAL(*it, insertedDouble);
			}
			else
			{
				CHECK_EQUAL(*it, myDoubleA[count-1]);
			}

			count++;
		}

	}

} // namespace MListTestsNs
