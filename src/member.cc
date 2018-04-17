#include "member.h"

#include <queue>

#include "database.h"

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  // Fill in your code here.
  //start = this->member_id, finish = dst_member_id
  std::queue<Member *> q;
  this->color = COLOR_GRAY;
  q.push(this);
  while(!q.empty() && this->member_id != dst_member_id){
    Member *i = q.front();
    q.pop();
    for (std::pair<const long unsigned int, algdb::MemberConnection> cm : this->connecting_members){
      if (cm.second.dst->color != COLOR_GRAY){
        cm.second.dst->color = COLOR_GRAY;
        cm.second.dst->parent = i;
        q.push(cm.second.dst);
      }
    }
  }
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
}
  
void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}