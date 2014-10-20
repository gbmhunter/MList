//!
//! @file				List.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-16
//! @last-modified		2014-10-20
//! @brief				Doubly-linked list object for creating and managing lists.
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

			// We need this so that we can decrement from List::End() to the last node on the list
			List<dataT> * list;

			Iterator()	:
				currListNode(nullptr),
				list(nullptr)
			{}

			//! @brief		Postfix increment. Moves the iterator to the next node in the list.
			//! @details	Will raise an assert if called when iterator has not yet been assigned to a list or the iterator is at List::End().
			Iterator & operator++(int)
			{
				if(!this->list)
				{
					M_ASSERT_FAIL("%s", "Postfix increment called on iterator which has not yet been assigned to a list.");
					return *this;
				}

				// Makes sure we are not trying to increment if we are at List::End().
				if(!this->currListNode)
				{
					M_ASSERT_FAIL("%s", "Postfix increment called on iterator which was at the end of a list.");
					return *this;
				}

				this->currListNode = this->currListNode->nextListNode;

				return *this;
			}

			//! @brief		Postfix decrement. Moves the iterator to the previous node in the list.
			//! @details	Will raise an assert if called when iterator has not yet been assigned to a list or the iterator is at List::Start().
			Iterator & operator--(int)
			{
				if(!this->list)
				{
					M_ASSERT_FAIL("%s", "Postfix decrement called on iterator which has not yet been assigned to a list.");
					return *this;
				}

				if(!this->currListNode)
				{
					// Special case where we are at List::End(), and need to decrement onto the last node in the list
					// This is why we save a pointer to the list in the iterator!
					this->currListNode = list->lastNode;
					return *this;
				}

				// Makes sure we are not trying to decrement if we are at the start of the list.
				if(!this->currListNode->prevListNode)
				{
					M_ASSERT_FAIL("%s", "Postfix decrement of Iterator called while at start of list.");
					return *this;
				}

				// This should work for all nodes except the first node (which should be caught by the assert above),
				// and the List::End() node (which is handled above also).
				this->currListNode = this->currListNode->prevListNode;
				return *this;
			}

			Iterator & operator+=(int32_t i)
			{
				// Call the increment operator "i" number of times
				// Because this is a linked list, and not something with a contiguous space in
				// memory, there is no faster way of doing this...
				for(uint32_t x = 0; x < i; x++)
				{
					(*this)++;
				}

				return *this;
			}

			Iterator & operator-=(int32_t i)
			{
				// Call the increment operator "i" number of times
				// Because this is a linked list, and not something with a contiguous space in
				// memory, there is no faster way of doing this...
				for(uint32_t x = 0; x < i; x++)
				{
					(*this)--;
				}

				return *this;
			}


			Iterator operator+(uint32_t i)
			{
				// Create a new iterator, and copy across the contents of the existing one
				Iterator result = *this;

				// Now use += iterator
				result+= i;

				return result;
			}

			Iterator operator-(uint32_t i)
			{
				// Create a new iterator, and copy across the contents of the existing one
				Iterator result = *this;

				// Now use += iterator
				result-= i;

				return result;
			}

			//! @brief		Not-equals operator. Commonly used as the stop condition for a for loop iterating over all of the nodes in a list.
			//! @details	Raises assert if iterator has not yet been assigned to a list.
			bool operator!=(const Iterator & it)
			{
				if(!this->list)
				{
					M_ASSERT_FAIL("%s", "Not-equals operator called on iterator which has not yet been assigned to a list.");
					return false;
				}

				if(this->currListNode != it.currListNode)
					return true;
				else
					return false;
			}

			//! @brief		Dereference operator. Allows user to easily access the data at the current node pointed to by the iterator.
			//! @details	Will raise an assert if this is called while at List::End() (this is one place beyond the end of the list), or if iterator has not yet been assigned to a list.
			dataT operator*() const
			{
				if(!this->list)
				{
					M_ASSERT_FAIL("%s", "Dereference operator called on iterator which has not yet been assigned to a list.");

					// Since we can't access a value here, let's return the default value for the datatype used.
					static dataT defaultVal;
					return defaultVal;
				}

				// Makes sure we are not trying to dereference if we are at List::End().
				if(!this->currListNode)
				{
					M_ASSERT_FAIL("%s", "Dereference operator called on iterator while it was at List::End().");

					// Since we can't access a value here, let's return the default value for the datatype used.
					static dataT defaultVal;
					return defaultVal;
				}

				// Dereferencing should be o.k., let's return the data
				return this->currListNode->data;
			}

		}; // class Iterator

		//======================================================================================//
		//==================================== PUBLIC METHODS ==================================//
		//======================================================================================//

		List() :
			numNodes(0),
			firstNode(nullptr),
			lastNode(nullptr)
		{

		}

		static void StaticInit(std::ostream * ostream, bool isDebugPrintingEnabled)
		{
			List::ostream = ostream;
			List::isDebugPrintingEnabled = isDebugPrintingEnabled;
		}

		static std::ostream * ostream;
		static bool isDebugPrintingEnabled;

		uint32_t NumNodes() const
		{
			return this->numNodes;
		}

		//! @brief		Deletes the list node pointed to by the iterator it.
		//! @details	Assert will be raised if Delete() is called when there are no nodes.
		void Delete(Iterator it)
		{
			if(List::isDebugPrintingEnabled)
				std::cerr << __PRETTY_FUNCTION__ << " called." << std::endl;

			// Make sure Delete() wasn't called when there were no elements to delete
			if(this->NumNodes() == 0)
			{
				M_ASSERT_FAIL("%s", "Error: List::Delete() called when there were no nodes to delete.");
				return;
			}

			// There must be at least one element to delete now!

			ListNode<dataT> * prevListNode = it.currListNode->prevListNode;
			ListNode<dataT> * nextListNode = it.currListNode->nextListNode;

			if(prevListNode == nullptr && nextListNode == nullptr)
			{
				// There must be only one node in the list
				if(List::isDebugPrintingEnabled)
					std::cerr << "We are deleting the only node in the list." << std::endl;

				// No nodes will be left in list
				this->firstNode = nullptr;
				this->lastNode = nullptr;
			}
			else if(prevListNode == nullptr)
			{
				// We must be at the start of the list!
				if(List::isDebugPrintingEnabled)
					std::cerr << "We are deleting from the start of the list." << std::endl;


				// We need to delete the first node, and change the firstNode variable
				nextListNode->prevListNode = nullptr;
				this->firstNode = nextListNode;
			}
			else if(nextListNode == nullptr)
			{
				// We must be at the end of the list!
				if(List::isDebugPrintingEnabled)
					std::cerr << "We are deleting from the end of the list." << std::endl;

				//
				prevListNode->nextListNode = nullptr;
				this->lastNode = prevListNode;
			}
			else
			{
				// We must be somewhere in the middle of the list
				if(List::isDebugPrintingEnabled)
					std::cerr << "We are deleting from somewhere in the middle of the list." << std::endl;

				// Stitch up the previous and next list nodes together, removing the current node from the list
				prevListNode->nextListNode = nextListNode;
				nextListNode->prevListNode = prevListNode;
			}

			if(List::isDebugPrintingEnabled)
				std::cerr << "Deleting current node..." << std::endl;
			// Now that we have stitched up the list nodes before and after the one we wish to delete, we
			// can delete the current list node from memory.
			delete it.currListNode;

			// Decrement the node count
			this->numNodes--;

			if(List::isDebugPrintingEnabled)
				std::cerr << "Returning..." << std::endl;
		}

		//! @brief		Inserts data before the position specified by the iterator, unless there are currently no nodes in list, and in that case, inserts at start.
		void Insert(Iterator it, dataT & data)
		{
			if(List::isDebugPrintingEnabled)
				std::cerr << __PRETTY_FUNCTION__ << " called." << std::endl;

			// Lets create a new node
			ListNode<dataT> * listNode = new ListNode<dataT>();

			// Make sure memory was allocated successfully
			if(!listNode)
			{
				M_ASSERT_FAIL("%s", "Memory allocation for new list node failed.");
				return;
			}

			// Copy data to element
			listNode->data = data;


			// Now we need to insert it at the correct place
			if(this->firstNode == nullptr && this->lastNode == nullptr)
			{
				// List must be empty!
				if(List::isDebugPrintingEnabled)
					std::cout << "List is empty, inserting first node." << std::endl;
				this->firstNode = listNode;
				this->lastNode = listNode;
				listNode->prevListNode = nullptr;
				listNode->nextListNode = nullptr;
			}
			else if(it.currListNode == nullptr)
			{
				// We must be past the end of the list!
				if(List::isDebugPrintingEnabled)
					std::cout << "We are past the end of the list!" << std::endl;

				ListNode<dataT> * prevListNode = this->lastNode;
				if(List::isDebugPrintingEnabled)
					std::cout << "prevListNode = '" << prevListNode << "'." << std::endl;

				//if(List::isDebugPrintingEnabled)
					//std::cout << "prevListNode->data = '"<< prevListNode->data << "'." << std::endl;

				if(List::isDebugPrintingEnabled)
					std::cout << "Adjusting neighbouring list node pointers..." << std::endl;
				// Point the old list node last element to this new one
				prevListNode->nextListNode = listNode;
				listNode->prevListNode = prevListNode;

				// We are at the last node in the list
				listNode->nextListNode = nullptr;

				this->lastNode = listNode;
			}
			else if(it.currListNode->prevListNode == nullptr)
			{
				// We must be inserting at the start of the list

				// This new node will be the first node in the list
				this->firstNode = listNode;

				listNode->prevListNode = this->firstNode;
				listNode->nextListNode = it.currListNode;

				// The current node is now the second node in the list
				it.currListNode->prevListNode = listNode;

			}
			else
			{
				// We must be inserting somewhere in the middle of the list...

				if(List::isDebugPrintingEnabled)
					std::cout << "We are inserting before a existing and valid node!" << std::endl;

				//===== PREV NODE =====//
				ListNode<dataT> * prevListNode = it.currListNode->prevListNode;
				if(List::isDebugPrintingEnabled)
					std::cout << "prevListNode = '" << prevListNode << "'." << std::endl;

				//if(List::isDebugPrintingEnabled)
				//	std::cout << "prevListNode->data = '"<< prevListNode->data << "'." << std::endl;

				if(List::isDebugPrintingEnabled)
					std::cout << "Adjusting neighbouring list node pointers..." << std::endl;
				// Point the old list node last element to this new one
				prevListNode->nextListNode = listNode;
				listNode->prevListNode = prevListNode;

				//===== NEXT NODE =====//
				ListNode<dataT> * nextListNode = it.currListNode;
				if(List::isDebugPrintingEnabled)
					std::cout << "currListNode = '" << nextListNode << "'." << std::endl;

				//if(List::isDebugPrintingEnabled)
				//	std::cout << "currListNode->data = '"<< nextListNode->data << "'." << std::endl;

				if(List::isDebugPrintingEnabled)
					std::cout << "Adjusting neighbouring list node pointers..." << std::endl;
				// Point the old list node last element to this new one
				nextListNode->prevListNode = listNode;
				listNode->nextListNode = nextListNode;

			}


			// Increment element count
			numNodes++;
		}

		//! @brief		Returns an iterator to the first node in the list.
		//! @details	Mimics the behaviour of std::begin().
		Iterator Start()
		{
			if(List::isDebugPrintingEnabled)
				*List::ostream << __PRETTY_FUNCTION__ << " called." << std::endl;
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
			if(List::isDebugPrintingEnabled)
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

		uint32_t numNodes;

		//! @brief		Pointer to the first node in the list.
		ListNode<dataT> * firstNode;
		ListNode<dataT> * lastNode;

		
	}; // class List



	template < typename dataT >
	std::ostream * List<dataT>::ostream = nullptr;

	template < typename dataT >
	bool List<dataT>::isDebugPrintingEnabled = false;


} // namespace MbeddedNinja

#endif	// #ifndef M_LIST_LIST_H

// EOF
