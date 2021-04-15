#include <bits/stdc++.h>

using namespace std;

struct node { // a TRIE node
  vector<node*> children;
  char ch;
  bool isCompWord;
};

node* create_node(char ch = 0) {
  // create an empty node and return it's pointer
  node* root = new node();
  root->ch = ch;
  return root;
}

node* root = create_node();

node* insert_char(node* root, char c) {
  // check if there is a children with character c
  int found = -1;
  for(int i=0; i<root->children.size(); i++) {
    if(root->children[i]->ch == c) {
      found = i;
    }
  }
  // if not found, then create a node
  if(found == -1) {
    node* new_node = create_node(c);
    root->children.push_back(new_node);
    return new_node;
  }
  return root->children[found];
}

void insert_word(node* root, string& word) {
  for(int i=0; i<word.length(); i++) {
    char c = word[i];
    node* new_root = insert_char(root, c);
    root = new_root;
    if(i+1 == word.size()) {
      root->isCompWord = true;
    }
  }
}

node* goto_next(node* root, char c) {
  for(int i=0; i<root->children.size(); i++) {
    if(root->children[i]->ch == c) {
      return root->children[i];
    }
  }
  return NULL;
}

bool find_word(node* root, string& word) {
  for(int i=0; i<word.length(); i++) {
    char c = word[i];
    root = goto_next(root, c);
    if(root == NULL) {
      return false;
    }
  }
  return root->isCompWord;
}

int main()
{
  string word;
  cin>>word;
  insert_word(root, word);
  cout<<find_word(root, word)<<endl;
  return 0;
}
