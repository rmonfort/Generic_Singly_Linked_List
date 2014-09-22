#include <iostream>

// Singly linked list node
template <typename T>
class Node
{
private:
	T data; // Data
	Node<T>* next; // Pointer to next node in linked list
	template<typename T>
	friend class LinkedList; // Give access to LinkedList
};

// Singly linked list
template <typename T>
class LinkedList
{
public:
	LinkedList(); 
	~LinkedList();
	bool empty() const; // Checks if list is empty
	const T& return_front() const; // Returns the front element in linked list
	const Node<T>* LinkedList<T>::return_head() const; // Returns pointer to head of linked list
	void add_to_front(const T& n); // Add node to front of linked list
	void remove_front(); // Remove node from front of list
	void print_list(); // Prints all the values in linked list
	void search_linked_list(const Node<T>* ptr, const T& search_value); // Recursively searches linked list

private:
	Node<T>* head;
};

// Constructor
template<typename T>
LinkedList<T>::LinkedList()
: head(NULL)
{
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	while (!empty())
	{
		remove_front();
	}
}

// Checks if list is empty
template<typename T>
bool LinkedList<T>::empty() const
{
	return head == NULL;
}

// Returns the front element in linked list
template<typename T>
const T& LinkedList<T>::return_front() const
{
	return head->data;
}

// Returns pointer to head of linked list
template<typename T>
const Node<T>* LinkedList<T>::return_head() const
{
	return head;
}

// Adds element to front of linked list
template<typename T>
void LinkedList<T>::add_to_front(const T& n)
{
	Node<T>* nn = new Node<T>; // Create a new node
	nn->data = n; // Store data in new node
	nn->next = head; // Head now comes after new node
	head = nn; // New node becomes head
}

// Remove node from front of list
template<typename T>
void LinkedList<T>::remove_front()
{
	Node<T>* old = head; // Save current head
	head = old->next; // Set head to node after current head
	delete old; // Remove old head
}

template<typename T>
void LinkedList<T>::print_list()
{
	Node<T>* tn = head;
	while (tn != NULL)
	{
		std::cout << tn->data << " ";
		tn = tn->next;
	}
	std::cout << std::endl;
}

// Recursively searches linked list
template<typename T>
void LinkedList<T>::search_linked_list(const Node<T>* ptr, const T& search_value)
{
	if (ptr == NULL)
	{
		std::cout << search_value << " was not found in the list." << std::endl;
	}
	else if (ptr->data == search_value)
	{
		std::cout << search_value << " was found in the list." << std::endl;
	}
	else
	{
		search_linked_list(ptr->next, search_value);
	}
}

int main()
{
	std::cout << "A linked list has been created...\n" << std::endl;
	LinkedList<int> llint;

	std::cout << "Checking if linked list is empty..." << std::endl;
	if (llint.empty())
	{
		std::cout << "Linked list has no values...\n" << std::endl;
	}

	std::cout << "Generating values for linked list..." << std::endl;
	std::cout << "Linked List:" << std::endl;
	for (size_t i = 10; i > 0; i--)
	{
		llint.add_to_front(i);
	}
	llint.print_list();
	std::cout << "\n";

	std::cout << "The first element in the linked list is " << llint.return_front() << "." << std::endl;
	std::cout << "Removing the first element in linked list..." << std::endl;
	llint.remove_front();
	std::cout << "Linked List:" << std::endl;
	llint.print_list();
	std::cout << "\n";

	std::cout << "Searching for the value 1 in linked list... ";
	llint.search_linked_list(llint.return_head(), 1);
	std::cout << "Searching for the value 8 in linked list... ";
	llint.search_linked_list(llint.return_head(), 8);
	std::cout << "Searching for the value 21 in linked list... ";
	llint.search_linked_list(llint.return_head(), 21);

	std::cout << "\n" << std::endl;

	std::cout << "A linked list has been created...\n" << std::endl;
	LinkedList<char> llchar;

	std::cout << "Checking if linked list is empty..." << std::endl;
	if (llchar.empty())
	{
		std::cout << "Linked list has no values...\n" << std::endl;
	}

	std::cout << "Generating values for linked list..." << std::endl;
	char values[] = { 'u', 'o', 'i', 'e', 'a' };
	for (auto &c : values)
	{
		llchar.add_to_front(c);
	}
	std::cout << "Linked List:" << std::endl;
	llchar.print_list();
	std::cout << "\n";

	std::cout << "The first element in the linked list is " << llchar.return_front() << "." << std::endl;
	std::cout << "Removing the first element in linked list..." << std::endl;
	llchar.remove_front();
	std::cout << "Linked List:" << std::endl;
	llchar.print_list();
	std::cout << "\n";

	std::cout << "Searching for the character e in linked list... ";
	llchar.search_linked_list(llchar.return_head(), 'e');
	std::cout << "Searching for the character i in linked list... ";
	llchar.search_linked_list(llchar.return_head(), 'i');
	std::cout << "Searching for the character b in linked list... ";
	llchar.search_linked_list(llchar.return_head(), 'b');
}