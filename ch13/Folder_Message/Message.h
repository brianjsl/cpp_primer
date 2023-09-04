#pragma once

#include "Folder.h"
#include <set>
#include <string>

class Message {
	friend class Folder;
	friend void swap(Message &, Message &);

public:
	explicit Message(const std::string &str = "") : contents(str){};

	// copy control operators
	Message(const Message &);
	Message &operator=(const Message &);
	~Message();

	//move semantics
	Message(Message&& m);
	Message& Message::operator=(Message&& rhs);

	void save(Folder &);
	void remove(Folder &);

	void addFolder(Folder *);
	void remFolder(Folder *);
  
private:
	std::string contents;
	std::set<Folder *> folders;
	void add_to_Folders(const Message &);
	void remove_from_Folders();

	void move_Folders(Message* m);
};
