
class MyVisistor :public CBaseVisitor
{
	ModDef					*Mod;
	FnDef					*curFn;

public:
	MyVisistor(ModDef	*m);
	antlrcpp::Any visitFuncCall(CParser::FuncCallContext *ctx) override;
	antlrcpp::Any visitTreeSetKey(CParser::TreeSetKeyContext *ctx) override;
	antlrcpp::Any visitTreeGetKey(CParser::TreeGetKeyContext *ctx) override;
	antlrcpp::Any visitTreeAddKey(CParser::TreeAddKeyContext *ctx) override;
	antlrcpp::Any visitTreeEnum(CParser::TreeEnumContext *ctx) override;
	antlrcpp::Any visitTreeFindKey(CParser::TreeFindKeyContext *ctx) override;
	antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx)override ;


};

