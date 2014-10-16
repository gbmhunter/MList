//!
//! @file				List.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-16
//! @last-modified		2014-10-16
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef M_LIST_LIST_H
#define M_LIST_LIST_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	template < typename dataT >
	class List;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
#include <iostream>

//===== USER LIBRARIES =====//
#include "MAssert/api/MAssertApi.hpp"

//===== USER SOURCE =====//
#include "ListNode.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	//! @brief
	//! @details
	template < typename dataT >
	class List
	{	
		
		public:

		class Iterator
		{
			public:

			ListNode<dataT> * currListElement;
			List<dataT> * list;

			Iterator & operator++(int)
			{
				this->currListElement = this->currListElement->nextListElement;
				return *this;
			}

			bool operator!=(const Iterator & it)
			{
				if(this->currListElement != it.currListElement)
					return true;
				else
					return false;
			}

			bool operator<=(const Iterator & it)
			{
				if(this->currListElement == nullptr)
					return false;
				else
					return true;
			}

			dataT operator*() const
			{
				return this->currListElement->data;
			}

		};

		//======================================================================================//
		//==================================== PUBLIC METHODS ==================================//
		//======================================================================================//

		List() :
			numElements(0),
			firstElement(nullptr),
			lastElement(nullptr)
		{

		}

		void Insert(dataT & data, uint32_t pos)
		{
			// Make sure insert position is valid
			M_ASSERT(pos <= numElements);

			ListNode<dataT> * listElement = new ListNode<dataT>();

			// Copy data to element
			listElement->data = data;

			// Now we need to insert it at the correct place
			if(numElements == 0)
			{
				this->firstElement = listElement;
				this->lastElement = listElement;
				listElement->prevListElement = nullptr;
				listElement->nextListElement = nullptr;
			}
			else
			{

			}

			// Increment element count
			numElements++;
		}

		Iterator Start()
		{
			Iterator it;
			it.list = this;
			it.currListElement = this->firstElement;
			return it;
		}

		Iterator End()
		{
			Iterator it;
			it.list = this;
			it.currListElement = this->lastElement;
			return it;
		}

		//======================================================================================//
		//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
		//======================================================================================//



		//======================================================================================//
		//================================= PUBLIC VARIABLES ===================================//
		//======================================================================================//
				

				
		private:
						
		//======================================================================================//
		//=================================== PRIVATE METHODS ==================================//
		//======================================================================================//

		// none

		//======================================================================================//
		//================================== PRIVATE VARIABLES =================================//
		//======================================================================================//

		uint32_t numElements;

		ListNode<dataT> * firstElement;
		ListNode<dataT> * lastElement;

		
	}; // class List


} // namespace MbeddedNinja

#endif	// #ifndef M_LIST_LIST_H

// EOF
