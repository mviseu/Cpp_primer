#include "Folder.h"
#include <iostream>
#include "Message.h"

using std::cout;
using std::endl;

Folder::Folder(const Folder &rhs) : messages(rhs.messages) {
	add_to_messages(rhs);
}

Folder &Folder::operator=(const Folder &rhs) {
	remove_from_messages();
	add_to_messages(rhs);
	messages = rhs.messages;
	return *this;
}

void Folder::addMsg(Message *m) {
	messages.insert(m);
}

void Folder::remMsg(Message *m) {
	messages.erase(m);
}

Folder::~Folder() {
	remove_from_messages();
}

void Folder::add_to_messages(const Folder &f) {
	for(const auto &m : f.messages) {
		m -> addFolder(this);
	}
}

void Folder::remove_from_messages() {
	for(const auto &m : messages) {
		m -> remFolder(this);
	}
}