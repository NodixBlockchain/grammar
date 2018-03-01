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

int FnDef::add_arg_call(std::string name, std::string fnname)
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

				call.func_name = fnname;
				call.target = ckey->ref_name;
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


int ArgChildKey::addOutput(std::string var_ref_name, std::string type, std::string key)
{
	if (!this->ref_name.compare(var_ref_name))
	{
		ArgKey ikey;
		ikey.name = key;
		ikey.type = type;
		this->output.push_back(ikey);
	}

	for (std::list<ArgKey>::iterator cckey = this->iter.begin(); cckey != this->iter.end(); ++cckey)
	{
		if (!cckey->name.compare(var_ref_name))
		{
			ArgKey ikey;
			ikey.name = cckey->name + "[*]." + key;
			ikey.type = type;
			this->output.push_back(ikey);
			break;
		}
	}

	return 1;
}

int ArgChildKey::addInput(std::string var_ref_name, std::string type, std::string key)
{
	if (!this->ref_name.compare(var_ref_name))
	{
		ArgKey ikey;
		ikey.name = key;
		ikey.type = type;
		this->input.push_back(ikey);
	}

	for (std::list<ArgKey>::iterator cckey = this->iter.begin(); cckey != this->iter.end(); ++cckey)
	{
		if (!cckey->name.compare(var_ref_name))
		{
			ArgKey ikey;
			ikey.name = cckey->name+"[*]."+key;
			ikey.type = type;
			this->input.push_back(ikey);
			break;
		}
	}

	return 1;
}

void ModDef::addFile(const char *path)
{
	FileDef myfile;
	myfile.filePath = path;
	files.push_back(myfile);
}

void ModDef::dump_fn(FnDef *fn)
{
	if (fn->has_non_native == 0)return;

	printf("function %s \r\n", fn->name.data());

	for (std::list<FnArg >::iterator arg = fn->args.begin(); arg != fn->args.end(); ++arg)
	{
		if (arg->input.size() > 0)
		{
			for (std::list<ArgKey >::iterator key = arg->input.begin(); key != arg->input.end(); ++key)
			{
				printf("\tget : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());
			}
		}
		if (arg->output.size() > 0)
		{
			for (std::list<ArgKey >::iterator key = arg->output.begin(); key != arg->output.end(); ++key)
			{
				printf("\tset : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());
			}
		}

		if (arg->enumkey.size() > 0)
		{
			for (std::list<ArgChildKey >::iterator key = arg->enumkey.begin(); key != arg->enumkey.end(); ++key)
			{
				printf("\tenum : %s->[*] \r\n", arg->id.data());

				for (std::list<ArgKey >::iterator ckey = key->input.begin(); ckey != key->input.end(); ++ckey)
				{
					printf("\tenum get : %s->[*]->%s as %s \r\n", arg->id.data(), ckey->name.data(), ckey->type.data());
				}

				for (std::list<ArgKey >::iterator ckey = key->output.begin(); ckey != key->output.end(); ++ckey)
				{
					printf("\tenum set : %s->[*]->%s as %s \r\n", arg->id.data(), ckey->name.data(), ckey->type.data());
				}
			}
		}

		if (arg->childkey.size() > 0)
		{
			for (std::list<ArgChildKey >::iterator key = arg->childkey.begin(); key != arg->childkey.end(); ++key)
			{
				printf("\tuse : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());

				for (std::list<ArgKey >::iterator ckey = key->iter.begin(); ckey != key->iter.end(); ++ckey)
				{
					printf("\tused key enum : %s->%s->[*]->%s\r\n", arg->id.data(), key->name.data(), ckey->name.data());
				}

				for (std::list<ArgKey >::iterator ckey = key->input.begin(); ckey != key->input.end(); ++ckey)
				{
					printf("\tused key get : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
				}

				for (std::list<ArgKey >::iterator ckey = key->output.begin(); ckey != key->output.end(); ++ckey)
				{
					printf("\tused key set : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
				}
			}
		}

		if (arg->addkey.size() > 0)
		{
			for (std::list<ArgChildKey >::iterator key = arg->addkey.begin(); key != arg->addkey.end(); ++key)
			{
				printf("\tadd : %s->%s as %s \r\n", arg->id.data(), key->name.data(), key->type.data());


				for (std::list<ArgKey >::iterator ckey = key->input.begin(); ckey != key->input.end(); ++ckey)
				{
					printf("\tadded key get : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
				}

				for (std::list<ArgKey >::iterator ckey = key->output.begin(); ckey != key->output.end(); ++ckey)
				{
					printf("\tadded key set : %s->%s->%s as %s \r\n", arg->id.data(), key->name.data(), ckey->name.data(), ckey->type.data());
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

void ModDef::dump()
{
	for (std::list<FnDef *>::iterator fn = methods.begin(); fn != methods.end(); ++fn)
	{
		dump_fn(*fn);
	}
}

void ModDef::parse()
{
	for (std::list<FileDef>::iterator file = files.begin(); file != files.end(); ++file)
	{
		std::ifstream stream;

		printf("parsing '%s' \r\n", file->filePath.data());

		stream.open(file->filePath);

		file->input = new ANTLRInputStream(stream);
		file->lexer = new CLexer(file->input);
		file->tokens = new CommonTokenStream(file->lexer);
		file->parser = new CParser(file->tokens);
		file->tree = file->parser->translationUnit();
		stream.close();
	}
}

void ModDef::visit()
{
	MyVisistor Visitor(this);

	for (std::list<FileDef>::iterator file = files.begin(); file != files.end(); ++file)
	{
		Visitor.visit(file->tree);
	}
}