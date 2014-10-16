//!
//! @file				List.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-16
//! @last-modified		2014-10-17
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

			ListNode<dataT> * currListNode;
			List<dataT> * list;

			//! @brief		Postfix increment.
			Iterator & operator++(int)
			{
				// Makes sure we are not trying to increment if we are at List::End().
				M_ASSERT(this->currListNode);

				this->currListNode = this->currListNode->nextListNode;
				return *this;
			}

			bool operator!=(const Iterator & it)
			{
				if(this->currListNode != it.currListNode)
					return true;
				else
					return false;
			}

			/*bool operator<=(const Iterator & it)
			{
				if(this->currListElement == nullptr)
					return false;
				else
					return true;
			}*/

			dataT operator*() const
			{
				// Makes sure we are not trying to increment if we are at List::End().
				M_ASSERT(this->currListNode);
				return this->currListNode->data;
			}

		};

		//======================================================================================//
		//==================================== PUBLIC METHODS ==================================//
		//======================================================================================//

		List() :
			numElements(0),
			firstNode(nullptr),
			lastNode(nullptr)
		{

		}

		//! @brief		Inserts data before the position specified by the iterator, unless there are currently no nodes in list, and in that case, inserts at start.
		void Insert(Iterator it, dataT & data)
		{
			std::cerr << __PRETTY_FUNCTION__ << " called." << std::endl;

			// Make sure insert position is valid
			//M_ASSERT(pos <= numElements);

			ListNode<dataT> * listNode = new ListNode<dataT>();

			// Copy data to element
			listNode->data = data;


			// Now we need to insert it at the correct place
			if(numElements == 0)
			{
				std::cout << "List is empty, inserting first node." << std::endl;
				this->firstNode = listNode;
				this->lastNode = listNode;
				listNode->prevListNode = nullptr;
				listNode->nextListNode = nullptr;
			}
			else
			{
				if(it.currListNode == nullptr)
				{
					// We must be past the end of the list!
					std::cout << "We are past the end of the list!" << std::endl;


					ListNode<dataT> * prevListNode = this->lastNode;
					std::cout << "prevListNode = '" << prevListNode << "'." << std::endl;
					std::cout << "prevListNode->data = '"<< prevListNode->data << "'." << std::endl;

					std::cout << "Adjusting neighbouring list node pointers..." << std::endl;
					// Point the old list node last element to this new one
					prevListNode->nextListNode = listNode;
					listNode->prevListNode = prevListNode;

					// We are at the last node in the list
					listNode->nextListNode = nullptr;

					this->lastNode = listNode;
				}
				else
				{
					std::cout << "We are inserting before a existing and valid node!" << std::endl;
				}
			}

			// Increment element count
			numElements++;
		}

		//! @brief		Returns an iterator to the first node in the list.
		//! @details	Mimics the behaviour of std::begin().
		Iterator Start()
		{
			std::cout << __PRETTY_FUNCTION__ << " called." << std::endl;
			Iterator it;
			it.list = this;
			// This could be nullptr if there are no nodes in the list
			it.currListNode = this->firstNode;
			return it;
		}

		//! @brief		Returns the 'past-the-end' node of the list.
		//! @details	This behaviour is so that you can move through an iterator inside a for loop and use the it <! List::End() guard to stop the for loop. Mimics the behaviour of std::end().
		Iterator End()
		{
			std::cout << __PRETTY_FUNCTION__ << " called." << std::endl;
			Iterator it;
			it.list = this;
			// Return the 'past-the-end' node, not the last node.
			it.currListNode = nullptr;
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

		//! @brief		Pointer to the first node in the list.
		ListNode<dataT> * firstNode;
		ListNode<dataT> * lastNode;

		
	}; // class List


} // namespace MbeddedNinja

#endif	// #ifndef M_LIST_LIST_H

// EOF
