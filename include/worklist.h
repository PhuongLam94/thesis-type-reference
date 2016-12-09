#ifndef WORKLIST_H
#define WORKLIST_H

#endif // WORKLIST_H

#include <memory>
#include <map>
//This file is to define classes will use in constant propagation.

//using namespace std;
//parent class for FlowWorkList and SSAWorkList
class BasicBlock;
class Statement;
class Binary;
class Const;
class Unary;
class TypedExp;
class Exp;
class AssemblyArgument;
class UserProc;
class Ternary;
class RefExp;
class WorkList{
protected:
    int typeOfWorkList;//1: flow work list, 2: ssa work list
public:
    bool isFlowWorkList(){return typeOfWorkList == 1;}
    bool isSSAWorkList(){return typeOfWorkList == 2;}
};
//class to define edges between bb, include one boolean to determine if this edge is executable or not
class FlowWorkList: public WorkList{
public:
    FlowWorkList(){
        typeOfWorkList = 1;
    }
    BasicBlock* fromBB;
    BasicBlock* toBB;
    bool isExecutable = false;
};
class SSAWorkList:public WorkList{
public:
    SSAWorkList(){
        typeOfWorkList = 2;
   }
   Statement* def;
   Statement* use;
};
class ConstantVariable{
public:
    int type; //1: top, 2: constant, 3: bottom
    Exp* variable; //two form: Const(i), i is an integer and m[Const(i)], i is an integer
    ConstantVariable(){
        type = 3;
    }
};
class MapExpConstant{
public:
    Exp* exp;
    ConstantVariable* val;
    MapExpConstant(){
    }
    ~MapExpConstant(){
    }
};

class EvalExpressionVisitor{
public:
    ConstantVariable* visit(Const* c, std::map<Exp*, ConstantVariable*> m,std::map<char*, AssemblyArgument*> replacement, UserProc* proc);
    ConstantVariable* visit(Binary* c, std::map<Exp*, ConstantVariable*> m,std::map<char*, AssemblyArgument*> replacement, UserProc* proc);
    ConstantVariable* visit(Unary* c, std::map<Exp*, ConstantVariable*> m,std::map<char*, AssemblyArgument*> replacement, UserProc* proc);
    ConstantVariable* visit(TypedExp* c, std::map<Exp*, ConstantVariable*> m,std::map<char*, AssemblyArgument*> replacement, UserProc* proc);
    ConstantVariable* visit(Ternary *c, std::map<Exp*, ConstantVariable*> m,std::map<char*, AssemblyArgument*> replacement, UserProc* proc);
    ConstantVariable* visit(RefExp *c, std::map<Exp*, ConstantVariable*> m,std::map<char*, AssemblyArgument*> replacement, UserProc* proc);
};
