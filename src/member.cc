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
  // Start = this->member_id, Finish = dst_member_id
  std::queue<Member *> q;
  this->color = COLOR_GRAY;
  q.push(this);
  while(!q.empty()){
    Member *i = q.front();
    q.pop();
    for (std::pair<const long unsigned int, algdb::MemberConnection> cm : i->connecting_members){
      if (cm.second.dst->color != COLOR_GRAY){
        cm.second.dst->color = COLOR_GRAY;
        cm.second.dst->parent = i;
        q.push(cm.second.dst);
      }
    }
  }
}

bool Member::DLS(Member *curr, uint64_t dst_member_id, double depth){
  // Additional function for IDDFS utility
  if (curr->member_id == dst_member_id){
    return true;
  }
  if (depth <= 0){
    return false;
  }
  for (std::pair<const long unsigned int, algdb::MemberConnection> cm : curr->connecting_members){
    cm.second.dst->parent = curr;
    if (DLS(cm.second.dst, dst_member_id, depth - 1) == true){
      return true;
    }
  }
  return false;
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  for (double i = 0; i <= 100; i++){
    if (DLS(this, dst_member_id, i) == true){
      return;
    };
  }
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