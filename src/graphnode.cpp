#include "graphnode.h"
#include "debug.h"
#include "graphedge.h"
#include <memory>

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  //// STUDENT CODE
  ////

  // Warm Up Task: delete _chatBot removed as it is not an owned data handle (no
  // new call in constructor)
  // delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  DEBUG("GraphNode MoveChatbotHere");
  _chatBot = std::move(chatbot);
  DEBUG("GraphNode MoveChatbotHere chatbot moved");
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));
  // _chatBot = nullptr; // not required when _chatBot is not a pointer
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  return (_childEdges[index]).get();

  ////
  //// EOF STUDENT CODE
}