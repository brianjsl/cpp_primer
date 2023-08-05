#include "Message.h"

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
};

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}

void Message::remove_from_Folders() {
  for (auto f : folders) {
    f->remMsg(this);
  }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(*this);
}

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

Message::~Message() { remove_from_Folders(); }

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders)
    f->remMsg(&lhs);
  for (auto f : rhs.folders)
    f->remMsg(&rhs);
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto f : lhs.folders)
    f->addMsg(&lhs);
  for (auto f : rhs.folders)
    f->addMsg(&rhs);
}

void Message::addFolder(Folder *fp) {
  folders.insert(fp);
  fp->addMsg(this);
}

void Message::remFolder(Folder *fp) {
  folders.erase(fp);
  fp->remMsg(this);
}