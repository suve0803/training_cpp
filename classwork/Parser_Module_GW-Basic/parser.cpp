#include"parser.h"
#include<sstream>

Parser::~Parser() {
	for (ASTNode* node : ast){
		delete node;
}
ast.clear();
}

void Parser::parse(const std::vector<std::string>& code) {
	//	std::istringstream input(code);
	//	std::string line;

		//while (std::getline(input, line)) {
	for (std::string line : code)
	{
		std::istringstream ls(line);
		int lineno=0;
		ls >> lineno;

		std::string cmd;
		ls >> cmd;

		if (cmd == "LET") {
			std::string name, eq;
			ls >> name >> eq;
			ExpressionNode* expr = parseExpr(ls);
			int value = expr->eval();
			var[name] = value;
			delete expr;
		}
		else if (cmd == "PRINT") {
			ExpressionNode* expr = parseExpr(ls);
			ast.push_back(new PrintNode(expr));
		}
		else if (cmd == "IF") {
			ExpressionNode* cond = parseExpr(ls);
			std::string thenWord;
			ls >> thenWord;
			std::string rest;
			getline(ls, rest);
			std::istringstream thenLs(rest);
			std::string p;
			thenLs >> p;
			ExpressionNode* thenExpr = parseExpr(thenLs);
			ast.push_back(new IfNode(cond, new PrintNode(thenExpr)));
		}
	}
}
ExpressionNode* Parser::parseExpr(std::istringstream& ls) {
	ExpressionNode* left = parseTerm(ls);
	while (true) {
		ls >> std::ws;
		char op = ls.peek();
		if (op == '+' || op == '-') {
			ls.get();
			ExpressionNode* right = parseTerm(ls);

			ASTNodeType type;
			if (op == '+') {
				type = ASTNodeType::Add;
			}
			else {
				type = ASTNodeType::Subract;
			}
			left = new BinaryOpNode(type, left, right);
		}
		else {
			break;
		}
	}
	return left;
}

ExpressionNode* Parser::parseTerm(std::istringstream& ls) {
	ExpressionNode* left = parseFactor(ls);
	while (true) {
		ls >> std::ws;
		char op = ls.peek();
		if (op == '*' || op == '/') {
			ls.get();
			ExpressionNode* right = parseFactor(ls);

			ASTNodeType type;
			if (op == '*') {
				left = new BinaryOpNode(ASTNodeType::Multipy, left, right);
			}
			else {
				left = new BinaryOpNode(ASTNodeType::Divide, left, right);
			}
			
		}
		else {
			break;
		}
	}
	return left;
}

ExpressionNode* Parser::parseFactor(std::istringstream& ls) {
	ls >> std::ws;
	char c = ls.peek();
	
	if (c == '(') {
		ls.get();
		ExpressionNode* e = parseExpr(ls);
		ls >> std::ws;
		if (ls.peek() == ')') {
			ls.get();
		}
		return e;
	}

	if (std::isdigit(static_cast<unsigned char>(c))) {
		int v = 0;
		ls >> v;
		return new NumberNode(v);
	}
	std::string name;
	ls >> name;
	return new VariableNode(name, var);

	/*if (ls.peek() == '(') {
		ls.get();
		ExpressionNode* e = parseExpr(ls);
		if (ls.peek() == ')') {
			ls.get();
		}
		return e;
	}
	if (isdigit(ls.peek())) {
		int v;
		ls >> v;
		return new NumberNode(v);
	}
	std::string name;
	ls >> name;
	return new VariableNode(name, var);*/
}



void Parser::run() {
	for (ASTNode* node : ast) {
		ASTNodeType t = node->getType();
		if (t == ASTNodeType::Print) {
			PrintNode* p = static_cast<PrintNode*>(node);
			p->execute();
		}
		else if (t == ASTNodeType::If) {
			IfNode* i = static_cast<IfNode*>(node);
			i->execute();
		}
	}
}