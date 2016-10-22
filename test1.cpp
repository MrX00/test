#ifndef TREE_H
  #define TREE_H
 
  #include "treenode.h"
 
  // TODO your code goes here:
  template < typename X>
  class BinarySearchTree{
   
  public:
   
    unique_ptr<TreeNode<X>> root;
    int counter = 0;
  public:
   
    ostream &write(ostream & x) const{
     
     
      return root -> write(x);
     
    }
    TreeNode<X> *insert(X data){
     
      TreeNode<X> *tmpNode = new TreeNode<X>(data);
     
      TreeNode<X> *rootNode = root.get();
     
     
      if (counter == 0){
   
    root.reset(tmpNode);
    return tmpNode;
      }
     
      while (tmpNode != nullptr){  
    // checking if first number is lower than second number -> go right
    if (root->data < data){
     
      if(rootNode->rightChild == nullptr){
       
        tmpNode->setRightChild(tmpNode);
        tmpNode = nullptr;
        counter++;    
      }else {
        rootNode = rootNode->rightChild.get();    
      }
    }
    // checking if first number is lower than second number -> go left
    else if (data < root->data ){
     
      if (rootNode->leftChild == nullptr){
       
        rootNode->setLeftChild(tmpNode);
        counter++;  
      }else {
           
        rootNode = rootNode->leftChild.get();  
       }
    }
   
    else
    tmpNode->data =  rootNode->data ;
     
      }
      return tmpNode;  
    }
     
  };
 
 
  // do not edit below this line
 
  #endif
