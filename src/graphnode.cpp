#include "graphedge.h"
#include "graphnode.h"

#include <iostream> // DEBUG

GraphNode::GraphNode(int id)
{
    _id = id;
}

/// STUDENT CODE
///

// No destructor needed anymore, so I've removed it completely.

///
/// EOF STUDENT CODE


void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatBot)
{
    _chatBot = std::move(chatBot);
    _chatBot.SetCurrentNode(this);  
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}