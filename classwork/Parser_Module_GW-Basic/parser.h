#pragma once
#include "ASTNode.h"
#include <string>
#include <vector>
#include <map>
#include<sstream>

class Parser {
	std::vector<ASTNode*>ast;
	std::map<std::string, int>var;
public:
	~Parser();
	//void parse(const string& code);
	void parse(const std::vector<std::string>& code);
	void run();

private:
	ExpressionNode* parseExpr(std::istringstream&);
	ExpressionNode* parseTerm(std::istringstream&);
	ExpressionNode* parseFactor(std::istringstream&);
};

