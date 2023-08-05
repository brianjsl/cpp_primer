#include <initializer_list>
#include <set>
class Message;

class Folder {

public:
  // constructors
  Folder();

  Folder(std::initializer_list<Message *> msgs_init)
      : msgs(msgs_init.begin(), msgs_init.end()){};

  // utility functions
  void addMsg(Message *msg) { msgs.insert(msg); }

  void remMsg(Message *msg) { msgs.erase(msg); }

  // copy control
  Folder(const Folder &orig) : msgs(orig.msgs){};

  Folder &operator=(const Folder &orig) {
    msgs = orig.msgs;
    return *this;
  };

  ~Folder();

private:
  std::set<Message *> msgs;
};