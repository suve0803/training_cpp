#pragma once
#include<string>
#include<vector>
#include<map>
#include<iostream>
//using namespace std;

enum class ASTNodeType {
	Number, Variable, Print,Add,Subract,Multipy,Divide,If
};

class ASTNode {
protected:
	ASTNodeType nodeType;
public:
	ASTNode(ASTNodeType type) {
		nodeType = type;
	}
	virtual ~ASTNode() = default;
	ASTNodeType getType() {
		return nodeType;
	}
};

class ExpressionNode :public ASTNode {
public:
	ExpressionNode(ASTNodeType type):ASTNode(type) {}
	virtual int eval() = 0;
	~ExpressionNode()override = default;
};

class NumberNode:public ExpressionNode {
private:
	int value;
public:
	NumberNode(int v):ExpressionNode(ASTNodeType::Number),value(v) {}
	int eval() override {
		return value;
	}
};

class VariableNode :public ExpressionNode {
private:
	std::string name;
	std::map<std::string, int>& var;
public:
	VariableNode(std::string&n,std::map<std::string,int>&vmap):ExpressionNode(ASTNodeType::Variable),name(n),var(vmap){}
	int eval()  override {
		auto it = var.find(name);
		if (it != var.end()) {
			return it->second;
		}
		return 0;
	}

};

class BinaryOpNode :public ExpressionNode {
private:
	ExpressionNode* left;
	ExpressionNode* right;
public:
	BinaryOpNode(ASTNodeType op,ExpressionNode* l,ExpressionNode* r):ExpressionNode(op),left(l),right(r){}
	~BinaryOpNode() {
		delete left;
		delete right;
	}
	int eval() override {
		int a = left->eval();
		int b = right->eval();

		if (nodeType == ASTNodeType::Add) {
			return a + b;
		}
		else if (nodeType == ASTNodeType::Subract) {
			return a - b;
		}
		else if (nodeType == ASTNodeType::Multipy) {
			return a * b;
		}
		else if (nodeType == ASTNodeType::Divide) {
			if (b != 0) {
				return a / b;
			}
			else {
				return 0;
			}
		}
		return 0;
		//switch (nodeType) {
		//case ASTNodeType::Add:
		//	return a + b;
		//case ASTNodeType::Subract: 
		//	return a - b;
		//case ASTNodeType::Multipy:
		//	return a * b;
		//case ASTNodeType::Divide:
		//	return b != 0 ? a / b : 0;//change later
		//default:
		//	return 0;
		//}
		/*{
		case ASTNodeType::Number:
			break;
		case ASTNodeType::Variable:
			break;
		case ASTNodeType::Print:
			break;
		case ASTNodeType::Add:
			break;
		case ASTNodeType::Subract:
			break;
		case ASTNodeType::Multipy:
			break;
		case ASTNodeType::Divide:
			break;
		case ASTNodeType::If:
			break;
		default:
			break;
		}*/
	}
};

class PrintNode :public ASTNode {
private:
	ExpressionNode* expr;
public:
	PrintNode(ExpressionNode* e):ASTNode(ASTNodeType::Print),expr(e){}
	~PrintNode() {
		delete expr;
	}
	void execute() {
		std::cout << expr->eval() << std::endl;
	}
};

class IfNode :public ASTNode {
	ExpressionNode* condition;
	ASTNode* thenStmt;
public:
	IfNode(ExpressionNode* cond,ASTNode* thenS):ASTNode(ASTNodeType::If),condition(cond),thenStmt(thenS){}
	~IfNode() {
		delete condition;
		delete thenStmt;
	}
	void execute() {
		int result = condition->eval();
		if (result != 0) {
			PrintNode* p = static_cast<PrintNode*>(thenStmt);
			p->execute();
		}
	}
};