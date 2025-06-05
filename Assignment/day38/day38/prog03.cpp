/*std::forward_list<string> – Chat History Cleanup*/

#include <iostream>
#include <forward_list>
#include <string>

void cln_msg(std::forward_list<std::string>& msg) {
    auto pre = msg.before_begin(); 
    for (auto cur = msg.begin(); cur != msg.end(); ) {
        if (cur->substr(0, 8) == "DELETED:") {
            cur = msg.erase_after(pre); 
        }
        else {
            pre = cur; 
            cur++;          
        }
    }
}

int main() {
  
    std::forward_list<std::string> msg = {
        "Hi", "Hello", "DELETED: Spam", "How are you?", "DELETED: Abuse"
    };
   
    cln_msg(msg);

    std::cout << std::endl;
    for (const std::string& message : msg) {
        std::cout << message <<std::endl;
    }

    return 0;
}

