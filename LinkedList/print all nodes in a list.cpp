struct List{
  int val;
  List next;
}

class Solution{
public:
  void print(List* root){
    List*temp = root;
    while(temp!=NULL){
      cout<<temp->val" ";
      temp=temp->next;
    }
  }
}
