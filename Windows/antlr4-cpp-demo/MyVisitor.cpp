#include <iostream>
#include <string>
#include <list>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "CBaseVisitor.h"



#pragma execution_character_set("utf-8")

using namespace antlrcpptest;
using namespace antlr4;

#include "mod.h"
#include "MyVisitor.h"

MyVisistor::MyVisistor(ModDef	*m)
{
	Mod = m;
}

antlrcpp::Any MyVisistor::visitFuncCall(CParser::FuncCallContext *ctx)  {
	CParser::ArgumentExpressionListContext	*ilist = ctx->argumentExpressionList();
	std::string total = ctx->getText();
	std::string name = ctx->Identifier()->getText();

	while ((ilist != nullptr) && (ilist->assignmentExpression() != nullptr))
	{
		std::string t = ilist->assignmentExpression()->getText();

		if (t[0] == '&')
		{
			t = t.substr(1);
		}

		curFn->add_arg_call(t, name);
		ilist = ilist->argumentExpressionList();
	}


	return visitChildren(ctx);
}

antlrcpp::Any MyVisistor::visitTreeSetKey(CParser::TreeSetKeyContext *ctx)  {
	std::string ref_name = ctx->Identifier()->getText();
	std::string key = ctx->StringLiteral()->getText();
	std::string type = ctx->Tree_set_key()->getText().substr(strlen("tree_manager_set_child_value_"));
	
	for (std::list<FnArg>::iterator arg = curFn->args.begin(); arg != curFn->args.end(); ++arg)
	{
		if (arg->native == 1)continue;

		if (!arg->id.compare(ref_name))
		{
			ArgKey ikey;

			ikey.name = key.data();
			ikey.type = type.data();
			arg->output.push_back(ikey);
		}

		for (std::list<ArgChildKey>::iterator ckey = arg->addkey.begin(); ckey != arg->addkey.end(); ++ckey)
		{
			ckey->addOutput(ref_name, type, key);
		}

		for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
		{
			ckey->addOutput(ref_name, type, key);
		}

		for (std::list<ArgChildKey>::iterator ckey = arg->enumkey.begin(); ckey != arg->enumkey.end(); ++ckey)
		{
			ckey->addOutput(ref_name, type, key);
		}
	}

	return visitChildren(ctx);
}

antlrcpp::Any MyVisistor::visitTreeGetKey(CParser::TreeGetKeyContext *ctx)  {
	std::string ref_name = ctx->Identifier(0)->getText();
	std::string type	 = ctx->Tree_get_key()->getText().substr(strlen("tree_manager_get_child_value_"));
	std::string key;

	if (ctx->StringLiteral())
	{
		key = ctx->StringLiteral()->getText();
	}
	else
	{
		key = ctx->Identifier(2)->getText();
	}

	for (std::list<FnArg>::iterator arg = curFn->args.begin(); arg != curFn->args.end(); ++arg)
	{
		if (arg->native == 1)continue;

		if (!arg->id.compare(ref_name))
		{
			ArgKey ikey;

			ikey.name = key.data();
			ikey.type = type.data();
			arg->input.push_back(ikey);
		}

		for (std::list<ArgChildKey>::iterator ckey = arg->addkey.begin(); ckey != arg->addkey.end(); ++ckey)
		{
			ckey->addInput(ref_name, type, key);
		}

		for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
		{
			ckey->addInput(ref_name, type, key);
		}

		for (std::list<ArgChildKey>::iterator ckey = arg->enumkey.begin(); ckey != arg->enumkey.end(); ++ckey)
		{
			ckey->addInput(ref_name, type, key);
		}
	}

	return visitChildren(ctx);
}
antlrcpp::Any MyVisistor::visitTreeAddKey(CParser::TreeAddKeyContext *ctx)  {
	std::string p = ctx->Identifier(0)->getText();
	std::string key;
	std::string type;
	std::string idx;
	unsigned int target_idx;


	if (ctx->StringLiteral())
	{
		key = ctx->StringLiteral()->getText();

		if (ctx->Constant())
		{
			target_idx = 1;
			type = ctx->Constant()->getText();
		}
		else
		{
			target_idx = 2;
			type = ctx->Identifier(1)->getText();
		}
	}
	else if (ctx->Identifier(1))
	{
		key = ctx->Identifier(1)->getText();

		if (ctx->Constant())
		{
			target_idx = 2;
			type = ctx->Constant()->getText();
		}
		else
		{
			type = ctx->Identifier(2)->getText();
			target_idx = 3;
		}
	}

	if (ctx->Identifier(target_idx))
		idx = ctx->Identifier(target_idx)->getText();

	for (std::list<FnArg>::iterator arg = curFn->args.begin(); arg != curFn->args.end(); ++arg)
	{
		if (arg->native == 1)continue;

		if (!arg->id.compare(p))
		{
			ArgChildKey ikey;

			ikey.name = key.data();
			ikey.type = type.data();
			ikey.ref_name = idx.data();
			arg->addkey.push_back(ikey);
		}
	}

	return visitChildren(ctx);
}

antlrcpp::Any MyVisistor::visitTreeEnum(CParser::TreeEnumContext *ctx)  {

	std::string p = ctx->Identifier(0)->getText();
	std::string idx = ctx->Identifier(2)->getText();;


	for (std::list<FnArg>::iterator arg = curFn->args.begin(); arg != curFn->args.end(); ++arg)
	{
		if (arg->native == 1)continue;

		if (!arg->id.compare(p))
		{
			ArgChildKey ikey;
			ikey.name = p.data();
			ikey.ref_name = idx.data();
			arg->enumkey.push_back(ikey);
		}

		for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
		{
			if (!ckey->ref_name.compare(p))
			{
				ArgKey ikey;
				ikey.name = idx.data();
				ckey->iter.push_back(ikey);
			}
		}

	}

	return visitChildren(ctx);
}

antlrcpp::Any MyVisistor::visitTreeFindKey(CParser::TreeFindKeyContext *ctx)  {

	std::string p = ctx->Identifier(0)->getText();
	std::string key;
	std::string type;
	std::string idx;
	unsigned int target_idx;

	if (ctx->StringLiteral())
	{
		key = ctx->StringLiteral()->getText();
		if (ctx->Constant())
		{
			target_idx = 2;
			type = ctx->Constant()->getText();
		}
		else
		{
			target_idx = 3;
			type = ctx->Identifier(1)->getText();
		}


	}
	else if (ctx->Identifier(2))
	{
		key = ctx->Identifier(2)->getText();

		if (ctx->Constant())
		{
			target_idx = 3;
			type = ctx->Constant()->getText();
		}

		else
		{
			target_idx = 4;
			type = ctx->Identifier(2)->getText();
		}
	}

	if (ctx->Identifier(target_idx))
		idx = ctx->Identifier(target_idx)->getText();

	for (std::list<FnArg>::iterator arg = curFn->args.begin(); arg != curFn->args.end(); ++arg)
	{
		if (arg->native == 1)continue;

		if (!arg->id.compare(p))
		{
			ArgChildKey ikey;

			ikey.name = key.data();
			ikey.type = type.data();
			ikey.ref_name = idx.data();
			arg->childkey.push_back(ikey);
		}
	}

	return visitChildren(ctx);
}

antlrcpp::Any MyVisistor::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx)  {
	CParser::ParameterListContext	*ilist;

	std::string p = ctx->getText();
	std::string p2 = ctx->declarator()->directDeclarator()->directDeclarator()->getText();

	curFn = new FnDef();
	curFn->name = p2;

	curFn->has_non_native = 0;

	if (ctx->declarator()->directDeclarator()->parameterTypeList())
	{
		ilist = ctx->declarator()->directDeclarator()->parameterTypeList()->parameterList();

		while (ilist != nullptr)
		{
			FnArg arg;

			std::string p3 = ilist->parameterDeclaration()->declarationSpecifiers()->getText();
			std::string p4 = ilist->parameterDeclaration()->declarator()->getText();

			arg.type = p3;
			arg.id = p4;

			if ((!p3.compare("mem_zone_ref_ptr")) || (!p3.compare("mem_zone_ref_const_ptr")))
			{
				arg.native = 0;
				curFn->has_non_native = 1;
			}
			else
				arg.native = 1;

			curFn->args.push_back(arg);

			ilist = ilist->parameterList();
		}
	}
	Mod->methods.push_back(curFn);

	//printf("\r\n");

	return visitChildren(ctx);
}