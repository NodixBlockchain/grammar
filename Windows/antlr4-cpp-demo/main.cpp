/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>
#include <string>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "CBaseVisitor.h"



#include <Windows.h>

#pragma execution_character_set("utf-8")

using namespace antlrcpptest;
using namespace antlr4;

class ArgKey
{
public:

	std::string	 name;
	std::string	 type;
};

class ArgChildKey:public ArgKey
{
public:
	std::string			ref_name;
	std::list<ArgKey >	output;
	std::list<ArgKey >	input;
};

class FnCall
{
public:
	std::string func_name;
	std::string target;

};


class FnArg
{
	public:

	unsigned int		native;
	std::string			type;
	std::string			id;

	std::list<FnCall>		fn_calls;
	std::list<ArgKey >		input;
	std::list<ArgKey >		output;

	std::list<ArgChildKey >	childkey;
	std::list<ArgChildKey >	addkey;

	std::list<ArgChildKey >	enumkey;

};


class FnDef
{
	public:

	unsigned int		scriptable;
	unsigned int		has_non_native;
	std::string			name;
	std::list<FnArg >	args;

	int add_arg_call(std::string name, std::string fnname)
	{
		for (std::list<FnArg>::iterator arg = args.begin(); arg != args.end(); ++arg)
		{
			if (arg->native == 1)continue;

			if (!arg->id.compare(name))
			{
				FnCall call;

				call.func_name = fnname;

				arg->fn_calls.push_back(call);
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->addkey.begin(); ckey != arg->addkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(name))
				{
					FnCall call;

					call.func_name = fnname;
					call.target = ckey->ref_name;

					arg->fn_calls.push_back(call);
				}
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(name))
				{
					FnCall call;

					call.func_name	= fnname;
					call.target		= ckey->ref_name;
					arg->fn_calls.push_back(call);
				}
			}

			
			for (std::list<ArgChildKey>::iterator ckey = arg->enumkey.begin(); ckey != arg->enumkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(name))
				{
					FnCall call;

					call.func_name = fnname;
					call.target = ckey->ref_name;
					arg->fn_calls.push_back(call);
				}
			}
		}

		return 0;
	}

};

class FileDef
{
public:
	std::string		filePath;

	ANTLRInputStream	*input;
	CLexer				*lexer;
	CommonTokenStream	*tokens;
	CParser				*parser;
	tree::ParseTree		*tree;

};


class ModDef
{
public:

	std::list<FileDef>  files;
	std::list<FnDef *>	methods;


	void addFile(const char *path)
	{
		FileDef myfile;
		myfile.filePath = path;
		files.push_back(myfile);
	}

	void dump_fn(FnDef *fn)
	{
		if (fn->has_non_native == 0)return;

		printf("function %s \r\n", fn->name.data());

		for (std::list<FnArg >::iterator arg = fn->args.begin(); arg != fn->args.end(); ++arg)
		{
			if (arg->input.size() > 0)
			{
				for (std::list<ArgKey >::iterator key = arg->input.begin(); key != arg->input.end(); ++key)
				{
					printf("\tinput : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());
				}
			}
			if (arg->childkey.size() > 0)
			{
				for (std::list<ArgChildKey >::iterator key = arg->childkey.begin(); key != arg->childkey.end(); ++key)
				{
					printf("\tuse : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());

					for (std::list<ArgKey >::iterator ckey = key->input.begin(); ckey != key->input.end(); ++ckey)
					{
						printf("\tsub get : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
					}

					for (std::list<ArgKey >::iterator ckey = key->output.begin(); ckey != key->output.end(); ++ckey)
					{
						printf("\tsub set : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
					}
				}
			}
			if (arg->enumkey.size() > 0)
			{
				for (std::list<ArgChildKey >::iterator key = arg->enumkey.begin(); key != arg->enumkey.end(); ++key)
				{
					printf("\tenum : %s->[*] as %s \r\n", arg->id.data(), key->type.data());

					for (std::list<ArgKey >::iterator ckey = key->input.begin(); ckey != key->input.end(); ++ckey)
					{
						printf("\tsub get : %s->[*]->%s as %s \r\n", arg->id.data(), ckey->name.data(), ckey->type.data());
					}

					for (std::list<ArgKey >::iterator ckey = key->output.begin(); ckey != key->output.end(); ++ckey)
					{
						printf("\tsub set : %s->[*]->%s as %s \r\n", arg->id.data(), ckey->name.data(), ckey->type.data());
					}
				}
			}
			if (arg->output.size() > 0)
			{
				for (std::list<ArgKey >::iterator key = arg->output.begin(); key != arg->output.end(); ++key)
				{
					printf("\toutput : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());
				}
			}
			if (arg->addkey.size() > 0)
			{
				for (std::list<ArgChildKey >::iterator key = arg->addkey.begin(); key != arg->addkey.end(); ++key)
				{
					printf("\tadd : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());


					for (std::list<ArgKey >::iterator ckey = key->input.begin(); ckey != key->input.end(); ++ckey)
					{
						printf("\tsub get : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
					}

					for (std::list<ArgKey >::iterator ckey = key->output.begin(); ckey != key->output.end(); ++ckey)
					{
						printf("\tsub set : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
					}

				}
			}

			if (arg->fn_calls.size() > 0)
			{
				for (std::list<FnCall>::iterator fn = arg->fn_calls.begin(); fn != arg->fn_calls.end(); ++fn)
				{
					if (fn->target.size() > 0)
					{
						printf("\tcall %s on %s->%s \r\n", fn->func_name.data(), arg->id.data(), fn->target.data());
					}
					else
					{
						printf("\tcall %s on %s \r\n", fn->func_name.data(), arg->id.data());
					}
				}
			}

		}
		printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\r\n");
	}

	void dump()
	{
		for (std::list<FnDef *>::iterator fn = methods.begin(); fn != methods.end(); ++fn)
		{
			dump_fn(*fn);
		}
	}

	void visist();


	void parse()
	{
		for (std::list<FileDef>::iterator file = files.begin(); file != files.end(); ++file)
		{
			std::ifstream stream;

			printf("parsing '%s' \r\n", file->filePath.data());

			stream.open(file->filePath);

			file->input		= new ANTLRInputStream (stream);
			file->lexer		= new CLexer(file->input);
			file->tokens	= new CommonTokenStream(file->lexer);
			file->parser	= new CParser(file->tokens);
			file->tree		= file->parser->translationUnit();
			stream.close();
		}
	}

};




class MyVisistor :public CBaseVisitor
{
	ModDef					*Mod;
	FnDef					*curFn;

	public:
	MyVisistor(ModDef	*m)
	{
		Mod = m;
	}

	antlrcpp::Any visitFuncCall(CParser::FuncCallContext *ctx) override {
		CParser::ArgumentExpressionListContext	*ilist	= ctx->argumentExpressionList();
		std::string total								= ctx->getText();
		std::string name								= ctx->Identifier()->getText();
		
		while ((ilist != nullptr) && (ilist->assignmentExpression() != nullptr))
		{
			std::string t = ilist->assignmentExpression()->getText();

			if (t[0] == '&')
			{
				t = t.substr(1);
			}
			
			curFn->add_arg_call(t,name);
			ilist = ilist->argumentExpressionList();
		}
		

		return visitChildren(ctx);
	}
	
	antlrcpp::Any visitTreeSetKey(CParser::TreeSetKeyContext *ctx) override {
		std::string ref_name = ctx->Identifier()->getText();
		std::string p2;
		if(ctx->postfixExpression()->primaryExpression())
		{ 
			p2 = ctx->postfixExpression()->primaryExpression()->getText();
		}
		
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
				if (!ckey->ref_name.compare(ref_name))
				{
					ArgKey ikey;
					ikey.name = ckey->name;
					ikey.type = type;
					ckey->output.push_back(ikey);
				}
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(ref_name))
				{
					ArgKey ikey;
					ikey.name = key;
					ikey.type = type;
					ckey->output.push_back(ikey);
				}

				for (std::list<ArgKey>::iterator cckey = ckey->input.begin(); cckey != ckey->input.end(); ++cckey)
				{
					if (!cckey->name.compare(ref_name))
					{
						ArgKey ikey;
						ikey.name =  "[*]." + key;
						ikey.type = type;
						ckey->output.push_back(ikey);
						break;
					}
				}
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->enumkey.begin(); ckey != arg->enumkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(ref_name))
				{
					ArgKey ikey;
					ikey.name = key;
					ikey.type = type;
					ckey->output.push_back(ikey);
				}

				for (std::list<ArgKey>::iterator cckey = ckey->input.begin(); cckey != ckey->input.end(); ++cckey)
				{
					if (!cckey->name.compare(ref_name))
					{
						ArgKey ikey;
						ikey.name = "[*]." + key;
						ikey.type = type;
						ckey->output.push_back(ikey);
						break;
					}
				}
			}
		}



		/*
		for (std::list<FnArg>::iterator arg=curFn->args.begin(); arg != curFn->args.end(); ++arg)
		{
			if (arg->native == 1)continue;

			if (!arg->id.compare(p))
			{
				ArgKey okey;

				okey.name = key.data();
				okey.type = type.data();
				arg->output.push_back(okey);
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->addkey.begin(); ckey != arg->addkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(p))
				{
					ArgKey cokey;

					cokey.name = key;
					cokey.type = type.data();
					ckey->output.push_back(cokey);
				}
			}


			for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(p))
				{
					ArgKey cokey;

					cokey.name = key;
					cokey.type = type.data();
					ckey->output.push_back(cokey);
				}
			}

		}
		*/

		
		return visitChildren(ctx);
	}

	antlrcpp::Any visitTreeGetKey(CParser::TreeGetKeyContext *ctx) override {
		std::string ref_name = ctx->Identifier(0)->getText();
		std::string p2;
		std::string key;
		if (ctx->postfixExpression()->primaryExpression())
		{
			p2 = ctx->postfixExpression()->primaryExpression()->getText();
		}

		if (ctx->StringLiteral())
		{
			key = ctx->StringLiteral()->getText();
		}
		else
		{
			key = ctx->Identifier(1)->getText();
		}

		
		std::string type = ctx->Tree_get_key()->getText().substr(strlen("tree_manager_get_child_value_"));

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
				if (!ckey->ref_name.compare(ref_name))
				{
					ArgKey ikey;
					ikey.name = ckey->name;
					ikey.type = type;
					ckey->input.push_back(ikey);
				}
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(ref_name))
				{
					ArgKey ikey;
					ikey.name = key;
					ikey.type = type;
					ckey->input.push_back(ikey);
				}

				for (std::list<ArgKey>::iterator cckey = ckey->input.begin(); cckey != ckey->input.end(); ++cckey)
				{
					if (!cckey->name.compare(ref_name))
					{
						ArgKey ikey;
						ikey.name = "[*]." +key;
						ikey.type = type;
						ckey->input.push_back(ikey);
						break;
					}
				}
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->enumkey.begin(); ckey != arg->enumkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(ref_name))
				{
					ArgKey ikey;
					ikey.name = key;
					ikey.type = type;
					ckey->input.push_back(ikey);
				}

				for (std::list<ArgKey>::iterator cckey = ckey->input.begin(); cckey != ckey->input.end(); ++cckey)
				{
					if (!cckey->name.compare(ref_name))
					{
						ArgKey ikey;
						ikey.name = "[*]." + key;
						ikey.type = type;
						ckey->input.push_back(ikey);
						break;
					}
				}
			}
		}

		return visitChildren(ctx);
	}
	antlrcpp::Any visitTreeAddKey(CParser::TreeAddKeyContext *ctx) override {
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

				ikey.name		= key.data();
				ikey.type		= type.data();
				ikey.ref_name	= idx.data();
				arg->addkey.push_back(ikey);
			}
		}

		return visitChildren(ctx);
	}

	antlrcpp::Any visitTreeEnum(CParser::TreeEnumContext *ctx) override {

		std::string p = ctx->Identifier(0)->getText();
		std::string idx = ctx->Identifier(2)->getText();;
	

		for (std::list<FnArg>::iterator arg = curFn->args.begin(); arg != curFn->args.end(); ++arg)
		{
			if (arg->native == 1)continue;

			if (!arg->id.compare(p))
			{
				ArgChildKey ikey;
				ikey.name		= p.data();
				ikey.ref_name	= idx.data();
				arg->enumkey.push_back(ikey);
			}

			for (std::list<ArgChildKey>::iterator ckey = arg->childkey.begin(); ckey != arg->childkey.end(); ++ckey)
			{
				if (!ckey->ref_name.compare(p))
				{
					ArgKey ikey;
					ikey.name = idx.data();
					ckey->input.push_back(ikey);
				}
			}

		}

		return visitChildren(ctx);
	}

	antlrcpp::Any visitTreeFindKey(CParser::TreeFindKeyContext *ctx) override {

		std::string p = ctx->Identifier(0)->getText();
		std::string key;
		std::string type;
		std::string idx;
		unsigned int target_idx;

		if (ctx->StringLiteral())
		{
			key= ctx->StringLiteral()->getText();
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

	antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override {
		CParser::ParameterListContext	*ilist;
		
		std::string p					= ctx->getText();
		std::string p2					= ctx->declarator()->directDeclarator()->directDeclarator()->getText();

		curFn		= new FnDef();
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

				if ((!p3.compare("mem_zone_ref_ptr"))|| (!p3.compare("mem_zone_ref_const_ptr")))
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


};

void ModDef::visist()
{
	MyVisistor Visitor(this);
	for (std::list<FileDef>::iterator file = files.begin(); file != files.end(); ++file)
	{
		Visitor.visit(file->tree);
	}
}

ModDef MyMod;

int main(int argc, const char * argv[]) {


	MyMod.addFile("C:\\bitstream\\serv\\block_adx\\block.i");
	MyMod.addFile("C:\\bitstream\\serv\\block_adx\\store.i");

	MyMod.parse();
	MyMod.visist();

	MyMod.dump();

	 //std::wcout << "Parse Tree: " << s << std::endl; //Unicode output in the console is very limited.

  return 0;
}
